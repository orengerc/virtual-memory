#include "VirtualMemory.h"

#include <cstdio>
#include <cassert>
#include <iostream>
#include <bitset>

struct cell {
    unsigned long val: OFFSET_WIDTH;
};

cell getBit(uint64_t number, int i)
{

    return cell{(((1 << OFFSET_WIDTH) - 1) & (number >> (i - 1)))};
}


int main(int argc, char **argv) {
    int64_t n = 135;
    std::cout << std::bitset<10>(n) << "\n";
    std::cout << std::bitset<4>(getBit(n, 4).val);

//    VMinitialize();
//    for (uint64_t i = 1; i < (2 * NUM_FRAMES); ++i) {
//        printf("writing to %llu\n", (long long int) i);
//        VMwrite(5 * i * PAGE_SIZE, i);
//    }
//
//    for (uint64_t i = 0; i < (2 * NUM_FRAMES); ++i) {
//        word_t value;
//        VMread(5 * i * PAGE_SIZE, &value);
//        printf("reading from %llu %d\n", (long long int) i, value);
//        assert(uint64_t(value) == i);
//    }
//    printf("success\n");

    return 0;
}
