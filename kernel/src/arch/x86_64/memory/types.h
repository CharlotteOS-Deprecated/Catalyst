#ifndef MEMORY_TYPES_H
#define MEMORY_TYPES_H

#include <libk/common.h>
#include <stdint.h>

typedef uint64_t paddr_t;
typedef void *vaddr_t;

// Clears the upper 24 bits of a physical address as is required by the x86-64 ISA
inline void normalize_paddr(paddr_t *const paddr)
{
	if (paddr)
		*paddr &= 0xFFFFFFFFFF;
}

// This function should not normally be needed as all compiler generated virtual addresses i.e.
// pointers should already be in canonical form however it is provided to ensure correctness
inline void normalize_vaddr(vaddr_t *const vaddr)
{
	if (vaddr) {
		bool is_msb_set = (*(uint64_t *const)vaddr & (1ul << 47ul)) == 0;
		if (is_msb_set) {
			(*(uint64_t *const)vaddr) |= 0xFFFF000000000000;
		} else {
			(*(uint64_t *const)vaddr) &= 0xFFFFFFFFFFFF;
		}
	}
}

#endif
