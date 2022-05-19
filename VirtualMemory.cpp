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

uint64_t getNextFrame() {
    //gets next frame
}

struct cell {
    unsigned long val: OFFSET_WIDTH;
};


uint64_t DFS(cell *entries, uint64_t index, uint64_t currentAddress) {
    //stopping condition
    if (index >= TABLES_DEPTH - 1) {
        return currentAddress;
    }

    uint64_t nextAddress;
    PMread(currentAddress * PAGE_SIZE + entries[index].val, (word_t *) (&nextAddress));

    if (!nextAddress) {
        uint64_t nextFrame = getNextFrame();
        PMwrite(currentAddress * PAGE_SIZE + entries[index].val, (word_t) nextFrame);
        nextAddress = nextFrame;
    }

    return DFS(entries, ++index, nextAddress);
}


cell getBits(uint64_t number, int i)
{
    return cell{(((1 << OFFSET_WIDTH) - 1) & (number >> (i - 1)))};
}

/**
 * Traverses the tree.
 * Restores/evicts pages as neccessary.
 * */
uint64_t getPhysicalAddress(uint64_t virtualAddress) {
    //copy virtualAddress to array of cells
    cell entries[TABLES_DEPTH];
    for (int i = 0; i < TABLES_DEPTH; ++i) {
        entries[i] = getBits(virtualAddress, i);
    }

    //traverse tree to find proper frame and calculate the physical address
    uint64_t frame = DFS(entries, 0, 0);
    uint64_t physicalAddress = (frame * PAGE_SIZE) + entries[TABLES_DEPTH - 1].val;
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
