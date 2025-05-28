#include <lib/prelude/prelude.h>

#include <limine.h>

// static u8 PFA_ME = 0;
static usize PFA_BITMAP_SIZE;

const usize FRAME_SIZE = 4096;
const usize BITS_PER_BYTE = 8;

enum pfa_status {
	PFA_SUCCESS = 0,
	PFA_INVALID_MEMORY_MAP,
};

[[maybe_unused]]
static enum pfa_status pfa_get_bitmap_size(const struct limine_memmap_response *const response)
{
	usize highest_addr = 0, n_frames = 0, n_bytes = 0;
	usize i;
	const struct limine_memmap_entry *entry;

	// find the highest address in the memory map
	for (i = 0; i < response->entry_count; i++) {
		entry = response->entries[i];
		if (entry->base + entry->length > highest_addr) {
			highest_addr = entry->base + entry->length;
		}
	}
	// adjust the number of frames for a remainder
	if (highest_addr % FRAME_SIZE) {
		n_frames = highest_addr / FRAME_SIZE + 1;
	} else {
		n_frames = highest_addr / FRAME_SIZE;
	}
	// adjust the number of bytes for a remainder
	if (n_frames % BITS_PER_BYTE) {
		n_bytes = n_frames / BITS_PER_BYTE + 1;
	} else {
		n_bytes = n_frames / BITS_PER_BYTE;
	}

	printf("PFA: highest_addr = %x, n_frames = %d, n_bytes = %d\n", highest_addr, n_frames,
	       n_bytes);
	PFA_BITMAP_SIZE = n_bytes;
	return PFA_SUCCESS;
}
