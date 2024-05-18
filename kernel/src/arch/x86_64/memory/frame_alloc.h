#ifndef MEMORY_FRAME_ALLOC
#define MEMORY_FRAME_ALLOC

#include <libk/common.h>
#include <stddef.h>
#include <stdint.h>

#include "limine.h"

#include "types.h"

enum pmem_status { SUCCESS = 0, ARR_LEN_ERROR = 1, INVALID_ARGUMENT = 2, INVALID_ALIGNMENT = 3 };

const size_t PAGE_SZ = 4096ull;

enum pmem_status mem_alloc_pmem_bmap(const struct limine_memmap_entry *const *const entries,
				     const size_t n_entries);
enum pmem_status mem_alloc_frames(paddr_t *const frame_addrs, const size_t buf_sz,
				  const size_t nframes);
enum pmem_status mem_dealloc_frames(const paddr_t *const frame_addrs, const size_t nframes);

#endif
