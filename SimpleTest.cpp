#include "VirtualMemory.h"
# include "MemoryConstants.h"
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

#define ONE (64 - VIRTUAL_ADDRESS_WIDTH)
#define TWO ((64 - VIRTUAL_ADDRESS_WIDTH) + OFFSET_WIDTH)
#define THREE ((64 - VIRTUAL_ADDRESS_WIDTH) + (OFFSET_WIDTH*2))



int main(int argc, char **argv) {
//    uint64_t n = 74565;
//    cell a{};
//
//    std::cout << std::bitset<64>(n) << "\n";
//
//    std::cout << std::bitset<64>(((n<<ONE)>>60)) << "\n";
//    a.val = ((n<<ONE)>>60);
//    std::cout << a.val << "\n";
//
//    std::cout << std::bitset<64>(((n<<TWO)>>60)) << "\n";
//    a.val = ((n<<TWO)>>60);
//    std::cout << a.val << "\n";
//
//    std::cout << std::bitset<64>(((n<<THREE)>>60)) << "\n";
//    a.val = ((n<<THREE)>>60);
//    std::cout << a.val << "\n";


    VMinitialize();
    for (uint64_t i = 20; i < (2 * NUM_FRAMES); ++i) {
        printf("writing to %llu\n", (long long int) i);
        VMwrite(5 * i * PAGE_SIZE, i);
    }

    for (uint64_t i = 0; i < (2 * NUM_FRAMES); ++i) {
        word_t value;
        VMread(5 * i * PAGE_SIZE, &value);
        printf("reading from %llu %d\n", (long long int) i, value);
        assert(uint64_t(value) == i);
    }
    printf("success\n");

    return 0;
}
