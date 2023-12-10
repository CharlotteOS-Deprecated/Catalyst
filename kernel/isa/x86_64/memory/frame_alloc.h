#ifndef MEMORY_FRAME_ALLOC
#define MEMORY_FRAME_ALLOC

#include <stddef.h>
#include <stdint.h>

#include "limine.h"

#include "types.h"

struct phys_mem_blk {
        paddr_t base;
        size_t n_frames;
        bool is_allocated;
        struct phys_mem_blk *next;
};

const size_t PAGE_SZ = 4096;

void init_frame_alloc(struct limine_memmap_entry **entries);
const struct phys_mem_blk *get_available_phys_mem(void);
bool allocate_frames(const struct phys_mem_blk *const frame_list);
void deallocate_frames(const struct phys_mem_blk *const frame_list);

#endif
