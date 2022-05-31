#include "VirtualMemory.h"
#include "PhysicalMemory.h"

#define SUCCESS 1
#define FAILURE 0
#define NOT_FOUND -1

//TODO בדיקות קלט

struct cell {
    unsigned long val: OFFSET_WIDTH;
};

/**
 * Sets all entries in the given frame to zero
 * */
void zeroFrame(uint64_t frame_index) {
    for (uint64_t i = 0; i < PAGE_SIZE; ++i) {
        PMwrite(frame_index * PAGE_SIZE + i, 0);
    }
}

/**
 * Initialize the virtual memory.
 * */
void VMinitialize() {
    zeroFrame(0);
}

/**
 * Returns minimum of 2 integers
 * */
uint64_t min(uint64_t a, uint64_t b){
    return a < b ? a : b;
}

/**
 * Returns absolute value of integer
 * */
uint64_t abs(uint64_t a){
    return a > 0 ? a : -a;
}

/**
 * Calculates cyclic distance
 * */
uint64_t calculateCyclicDistance(uint64_t page_swapped_in, uint64_t p) {
    return min(NUM_PAGES - abs(page_swapped_in - p), abs(page_swapped_in - p));
}

/**
 * Runs DFS in the tree, looking for the furthest leaf (cyclic-distance wise).
 * */
void evictDFS(uint64_t& max_frame, word_t& max_offset, uint64_t& max_parent, uint64_t& max_page,
                  uint64_t curr_frame, word_t curr_offset, uint64_t curr_parent, uint64_t curr_page,
                  uint64_t& max_distance, uint64_t& depth, uint64_t page_swapped_in){
    if(depth == TABLES_DEPTH){
        auto dist = calculateCyclicDistance(page_swapped_in >> OFFSET_WIDTH, curr_page);
        if(dist > max_distance){
            max_distance = dist;
            max_frame = curr_frame;
            max_offset = curr_offset;
            max_parent = curr_parent;
            max_page = curr_page;
        }
    }

    else{
        word_t next_frame;
        for(word_t i=0;i<PAGE_SIZE;++i){
            PMread(curr_frame*PAGE_SIZE + i, &next_frame);
            if(next_frame){
                evictDFS(max_frame, max_offset, max_parent, max_page, next_frame, i, curr_frame, (curr_page << OFFSET_WIDTH) | i, max_distance, ++depth, page_swapped_in);
            }
        }
    }
    depth--;
}

/**
 * Deletes association to a child (offset is the child)
 * */
void deleteChild(uint64_t parent, int offset){
    PMwrite(parent*PAGE_SIZE + offset, 0);
}

/**
 * Evicts a page from the memory, returns the newly available frame
 * */
uint64_t evictPage(uint64_t virtualAddress){
    //vars: frame, parent, page
    uint64_t frame = 0; uint64_t parent = 0; uint64_t page = 0; word_t offset = 0; uint64_t max_dist = 0;
    uint64_t depth = 0;
    evictDFS(frame, offset, parent, page, 0, 0, 0, 0, max_dist, depth, virtualAddress);

    //evict
    PMevict(frame, page);

    //erase link from parent
    deleteChild(parent, offset);

    return frame;
}

/**
 * Checks if a given frame is empty.
 * */
bool checkEmptyFrame(uint64_t frame){
    word_t res=0;
    for(int i=0;i<PAGE_SIZE;++i){
        PMread(PAGE_SIZE*frame + i, &res);
        if(res){
            return false;
        }
    }
    return true;
}

/**
 * Searches the tree for an empty frame, using DFS.
 * IN the process, tracks the maximal frame used.
 * */
word_t searchDFS(uint64_t dontErase, uint64_t currentFrame, int offset, uint64_t parentFrame, uint64_t& depthIndex, uint64_t* maxFrame) {

    //branch is full
    if(depthIndex == TABLES_DEPTH){
        //update max cyclic distance
        depthIndex--;
        return NOT_FOUND;
    }

    //if currentFrame is an empty frame and different from father, return currentFrame
    if(checkEmptyFrame(currentFrame) && (currentFrame != dontErase)){
        deleteChild(parentFrame, offset);
        depthIndex--;
        return currentFrame;
    }


    //iterate over entries inside the frame (DFS)
    word_t newFrame;
    for (word_t i = 0; i < PAGE_SIZE; ++i) {
        PMread(currentFrame * PAGE_SIZE + i, &newFrame);
        if(newFrame){
            //update max
            if(newFrame > (*maxFrame)){
                *maxFrame = newFrame;
            }

            //recursive call
            newFrame = (word_t)searchDFS(dontErase, newFrame, i, currentFrame, ++depthIndex, maxFrame);
            if(newFrame != NOT_FOUND){
                depthIndex--;
                return newFrame;
            }
        }
    }
    depthIndex--;
    return NOT_FOUND;
}

/**
 * Searches for a proper frame for the data, according to the given priorities.
 * */
uint64_t getNextFrame(uint64_t virtualAddress, uint64_t fatherFrame) {

    uint64_t maxFrame = 0;
    uint64_t depth = 0;

    word_t emptyFrame = searchDFS(fatherFrame, 0, 0, 0, depth, &maxFrame);

    //1st priority
    if(emptyFrame != NOT_FOUND){
        return emptyFrame;
    }

    //2nd priority
    if(maxFrame + 1 < NUM_FRAMES){
        return maxFrame + 1;
    }

    //3rd priority
    return evictPage(virtualAddress);

}

/**
 * Traverses the memory-tree, returns the frame number after everything is set and clear.
 * */
uint64_t searchForFrame(cell *entries, uint64_t index, uint64_t currentFrame, uint64_t virtualAddress) {

    //stop condition
    if (index == TABLES_DEPTH) {
        return currentFrame;
    }

    word_t nextAddress;
    PMread(currentFrame * PAGE_SIZE + entries[index].val, &nextAddress);

    if (nextAddress == 0) {
        auto nextFrame = (word_t)getNextFrame(virtualAddress, currentFrame);

        if(index + 1 == TABLES_DEPTH){
            PMrestore(nextFrame, CEIL(virtualAddress/PAGE_SIZE));
        }
        else{
            zeroFrame(nextFrame);
        }

        PMwrite(currentFrame * PAGE_SIZE + entries[index].val, (word_t) nextFrame);
        nextAddress = nextFrame;
    }

    return searchForFrame(entries, ++index, nextAddress, virtualAddress);
}

/**
 * Returns the i'th OFFSET_WIDTH bits of the given number
 * */
cell getBits(uint64_t number, int i)
{
    return cell{((number << ((64 - VIRTUAL_ADDRESS_WIDTH) + (OFFSET_WIDTH*i))) >> (64 - OFFSET_WIDTH))};
}

/**
 * Traverses the tree.
 * Restores/evicts pages as neccessary.
 * */
uint64_t getPhysicalAddress(uint64_t virtualAddress) {
    //copy virtualAddress to array of cells
    cell entries[TABLES_DEPTH+1];
    for (int i = 0; i <= TABLES_DEPTH; ++i) {
        entries[i] = getBits(virtualAddress, i);
    }

    //traverse tree to find proper frame and calculate the physical address
    uint64_t frame = searchForFrame(entries, 0, 0, virtualAddress);
    uint64_t physicalAddress = (frame * PAGE_SIZE) + entries[TABLES_DEPTH].val;
    return physicalAddress;
}

/**
 * Reads a word from the given virtual address
 * and puts its content in *value.
 *
 * returns 1 on success.
 * returns 0 on failure (if the address cannot be mapped to a physical
 * address for any reason)
 * */
int VMread(uint64_t virtualAddress, word_t *value) {
    if(virtualAddress >= VIRTUAL_MEMORY_SIZE){
        return FAILURE;
    }

    uint64_t physicalAddress = getPhysicalAddress(virtualAddress);
    if(physicalAddress == NOT_FOUND){
        return FAILURE;
    }
    PMread(physicalAddress, value);
    return SUCCESS;
}

/**
 * Writes a word to the given virtual address.
 *
 * returns 1 on success.
 * returns 0 on failure (if the address cannot be mapped to a physical
 * address for any reason)
 * */
int VMwrite(uint64_t virtualAddress, word_t value) {
    if(virtualAddress >= VIRTUAL_MEMORY_SIZE){
        return FAILURE;
    }

    uint64_t physicalAddress = getPhysicalAddress(virtualAddress);
    if(physicalAddress == NOT_FOUND){
        return FAILURE;
    }
    PMwrite(physicalAddress, value);
    return SUCCESS;
}
