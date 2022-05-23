//
// Created by oren_gerc on 19/05/2022.
//

#include "VirtualMemory.h"
#include "PhysicalMemory.h"
#include "BitwiseOps.h"
#include <bitset>
#include <iostream> //TODO REMOVE
#include <string.h>


void zeroFrame(uint64_t frame_index) {
    for (uint64_t i = 0; i < PAGE_SIZE; ++i) {
        PMwrite(frame_index * PAGE_SIZE + i, 0);
    }
}

/*
 * Initialize the virtual memory.
 */
void VMinitialize() {
    zeroFrame(0);
}

word_t searchTree() {
    //search for empty frame throuth the tree
    for (int i = 0; i <= PAGE_SIZE; ++i) {

    }


}

word_t getNextFrame() {
    //search for empty frame
    for (int i = 0; i <= PAGE_SIZE; ++i) {

    }


}

struct cell {
    unsigned long val: OFFSET_WIDTH;
};


uint64_t DFS(cell *entries, uint64_t index, uint64_t currentAddress) {
    //stopping condition
    if (index == TABLES_DEPTH) {
        return currentAddress;
    }

    word_t nextAddress;
    PMread(currentAddress * PAGE_SIZE + entries[index].val, &nextAddress);

    if (!nextAddress) {
        word_t nextFrame = getNextFrame();
        PMwrite(currentAddress * PAGE_SIZE + entries[index].val, (word_t) nextFrame);
        nextAddress = nextFrame;
    }

    return DFS(entries, ++index, nextAddress);
}


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
    uint64_t frame = DFS(entries, 0, 0);
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
    PMread(physicalAddress, value);
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
    PMwrite(physicalAddress, value);
}
