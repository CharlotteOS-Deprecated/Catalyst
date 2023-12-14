#ifndef MEMORY_VMM_H
#define MEMORY_VMM_H

#include <stddef.h>
#include <stdint.h>

#include "types.h"

/***Virtual Memory Manager***/

enum vmm_error {
        SUCCESS = 0,
        INVALID_ARGUMENT = -1,
        INVALID_ALIGNMENT = -2,
};

/*Attach the given physical frames to the chosen virtual addresses in the given page table tree*/
int32_t vmm_attach_frame(const vaddr_t page_addr, const paddr_t frame_addr);
/*Detach the pages at the given virtual address and write its physical frame base address to frame_addr*/
int32_t vmm_detach_frame(paddr_t *const frame_addr, vaddr_t page_addr);

/*Get the physical address of the active page map from the CR3 register*/
extern paddr_t asm_get_active_pgmap_paddr(void);
#endif
