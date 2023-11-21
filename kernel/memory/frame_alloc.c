#include "memory/include/frame_alloc.h"
#include "limine.h"

#include <stddef.h>
#include <stdint.h>

typedef uint64_t paddr_t;
typedef void* vaddr_t;

//The number of page frames reserved for the physical memory bitmap and its physical base address
static uint64_t BMAP_NFRAMES = 0;
static uint64_t BMAP_PADDR = 0;

void alloc_pmem_bmap(const struct limine_memmap_entry *const *const entries, const size_t n_entries)
{
        size_t n_total_frames = 0;

        for(size_t i = 0; i < n_entries; ++i) {
                if (entries[i]->type == LIMINE_MEMMAP_USABLE) {
                        n_total_frames += entries[i]->length / PAGE_SZ;
                }
        }
        //Calculate the size of the physical memory bitmap in bytes (one bit per page frame)
        size_t bmap_sz = (n_total_frames / 8);
        if (n_total_frames % 8 > 0)
                ++bmap_sz;
        //Calculate the number of page frames to reserve for the physical memory bit map
        BMAP_NFRAMES = (bmap_sz / 4096);
        if (n_total_frames % PAGE_SZ > 0)
                ++bmap_sz;
        //find and reserve bmap_nframes page frames
        for(size_t i = 0; i < n_entries; ++i) {
                if (entries[i]->type == LIMINE_MEMMAP_USABLE && entries[i]->length > bmap_sz) {
                        BMAP_PADDR = entries[i]->base;
                }
        }
        //TODO: Handle the case where no simgle memmap entry has enough memory for the entire bitmap
}

