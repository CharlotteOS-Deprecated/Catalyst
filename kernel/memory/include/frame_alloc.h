#ifndef MEMORY_FRAME_ALLOC
#define MEMORY_FRAME_ALLOC

#include <stddef.h>
#include <stdint.h>

#include "limine.h"

struct phys_mem_buf {
        uint64_t base;
        uint64_t n_frames;
};

uint64_t init_frame_alloc(struct limine_memmap_entries **entries);
const struct phys_mem_buf *get_available_phys_mem(void);
uint8_t allocate_frames(struct phys_mem_buf *frame_list);
uint8_t deallocate_frames(struct phsy_mem_buf *frame_list);

#endif