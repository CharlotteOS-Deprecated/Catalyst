#include "lib/prelude/prelude.h"

#include <limine.h>
#include <stddef.h>

const size_t FRAME_SIZE = 4096ull;
const size_t BITS_PER_BYTE = 8ull;

enum pfa_status {
    PFA_SUCCESS = 0,
    PFA_INVALID_MEMORY_MAP,
    PFA_REGION_ALLOC_FULL,
};

struct physical_frame_allocator {
    size_t total_frames;
    size_t free_frames;
    size_t committed_frames;
    size_t frame_bitmap_size;
    uint8_t *frame_bitmap;
};

size_t compute_bitmap_size(const struct limine_memmap_entry *const *const memory_map)
{
    paddr_t highest_address = 0;

    for (size_t i = 0; memory_map[i] != NULL; i++) {
        const struct limine_memmap_entry *entry = memory_map[i];
        size_t region_size = entry->length / FRAME_SIZE;
        highest_address = MAX(highest_address, entry->base + entry->length);
    }

    size_t bitmap_sz = highest_address / FRAME_SIZE;
    if (highest_address % FRAME_SIZE != 0) {
        ++bitmap_sz;
    }

    return bitmap_sz;
}
