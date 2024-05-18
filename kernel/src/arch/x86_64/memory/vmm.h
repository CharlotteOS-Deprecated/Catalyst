#ifndef MEMORY_VMM_H
#define MEMORY_VMM_H

#include <stddef.h>
#include <stdint.h>

#include "types.h"

/***Virtual Memory Manager***/

enum vmm_status {
	SUCCESS = 0,
	INVALID_ARGUMENT = -1,
	INVALID_ALIGNMENT = -2,
};

typedef uint64_t pagemap_table_t[512];
typedef pagemap_table_t *const pagemap_t;

/*All page maps used by the system should be created by copying this one which only maps the
 * kernel*/
extern const pagemap_t kernel_only_pagemap;

[[nodiscard("The status code returned by this function must be checked")]]
enum vmm_status vmm_create_base_page_map(pagemap_table_t *const pml4);
/*Attach the given physical frames to the chosen virtual addresses in the given page map*/
[[nodiscard("The status code returned by this function must be checked")]]
enum vmm_status vmm_attach_frame(pagemap_table_t *const pml4, const vaddr_t page_addr,
				 const paddr_t frame_addr);
/*Detach the pages at the given virtual address and write its physical frame base address to
 * frame_addr*/
[[nodiscard("The status code returned by this function must be checked")]]
enum vmm_status vmm_detach_frame(pagemap_table_t *const pml4, paddr_t *const frame_addr,
				 vaddr_t page_addr);

#endif
