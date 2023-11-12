#include "memory/include/frame_alloc.h"

#include <stdint.h>

typedef uint64_t paddr_t;
typedef void* vaddr_t;

//The number of page frames reserved for use by the allocator and their physical base address
[[maybe_unused]]
static uint64_t N_FRAMES_RESERVED = 0;
[[maybe_unused]]
static uint64_t RESERVED_BADDR = 0;

//Use a linked list with structs describing blocks of contiguous frames

