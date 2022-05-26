//
// Created by oren_gerc on 19/05/2022.
//

#include "VirtualMemory.h"
#include "PhysicalMemory.h"
#include "BitwiseOps.h"
#include <bitset>
#include <iostream> //TODO REMOVE
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define NOT_FOUND -1

struct cell {
    unsigned long val: OFFSET_WIDTH;
};

/**
 *
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
 *
 * */
uint64_t evictDFS(){

}

/**
 *
 * */
uint64_t evictPage(){

}

/**
 *
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
 *
 * */
void deleteChild(uint64_t parent, int offset){
    PMwrite(parent*PAGE_SIZE + offset, 0);
}

/**
 *
 * */
uint64_t searchDFS(uint64_t dontErase, uint64_t currentFrame, int offset, uint64_t parentFrame, uint64_t depthIndex, uint64_t* maxFrame) {

    //branch is full
    if(depthIndex == TABLES_DEPTH){
        return NOT_FOUND;
    }

    //if currentFrame is an empty frame and different from father, return currentFrame
    if(checkEmptyFrame(currentFrame) && (currentFrame != dontErase)){
        deleteChild(parentFrame, offset);
        return currentFrame;
    }


    //iterate over entries inside the frame (DFS)
    word_t newFrame;
    for (word_t i = 0; i <= PAGE_SIZE; ++i) {
        PMread(currentFrame * PAGE_SIZE + i, &newFrame);
        if(newFrame){
            //update max
            if(newFrame > (*maxFrame)){
                *maxFrame = newFrame;
            }

            //recursive call
            newFrame = (word_t)searchDFS(dontErase, newFrame, i, currentFrame, depthIndex++, maxFrame);
            if(newFrame != NOT_FOUND){
                return newFrame;
            }
        }
    }

    return NOT_FOUND;

}

/**
 *
 * */
uint64_t getNextFrame(uint64_t fatherFrame) {

    uint64_t maxFrame = 0;
    auto emptyFrame = searchDFS(fatherFrame, 0, 0, 0, 0, &maxFrame);

    //1st priority
    if(emptyFrame != NOT_FOUND){
        return emptyFrame;
    }

    //2nd priority
    if(maxFrame + 1 < NUM_FRAMES){
        return maxFrame + 1;
    }

    //3rd priority
    return evictPage();

}

/**
 *
 * */
uint64_t searchForFrame(cell *entries, uint64_t index, uint64_t currentFrame, uint64_t virtualAddress) {

    //stop condition
    if (index == TABLES_DEPTH) {
        return currentFrame;
    }

    word_t nextAddress;
    PMread(currentFrame * PAGE_SIZE + entries[index].val, &nextAddress);

    if (nextAddress == 0) {
        auto nextFrame = (word_t)getNextFrame(currentFrame);

        if(index + 1 == TABLES_DEPTH){
            PMrestore(nextFrame, virtualAddress);
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
 *
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
    uint64_t physicalAddress = getPhysicalAddress(virtualAddress);
    if(physicalAddress == -1){
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
    uint64_t physicalAddress = getPhysicalAddress(virtualAddress);
    if(physicalAddress == -1){
        return FAILURE;
    }
    PMwrite(physicalAddress, value);
    return SUCCESS;
}
