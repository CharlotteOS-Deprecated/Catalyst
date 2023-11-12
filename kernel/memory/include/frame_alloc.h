#ifndef MEMORY_FRAME_ALLOC
#define MEMORY_FRAME_ALLOC

#include <stddef.h>
#include <stdint.h>

#include "limine.h"

typedef uint64_t paddr_t;
typedef void* vaddr_t;

struct phys_mem_blk {
        paddr_t base;
        size_t n_frames;
        bool is_allocated;
        struct phys_mem_blk *next;
};

void init_frame_alloc(struct limine_memmap_entry **entries);
const struct phys_mem_blk *get_available_phys_mem(void);
bool allocate_frames(const struct phys_mem_blk *const frame_list);
void deallocate_frames(const struct phys_mem_blk *const frame_list);

#endif
