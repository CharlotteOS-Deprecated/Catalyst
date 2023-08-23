#include "x86_64/include/gdt.h"

#include "include/llk_api.h"
#include <stdint.h>
#include <stddef.h>

void create_segment_descriptor(uint64_t *const segment_descriptor, const uint32_t base, const uint32_t limit, const uint8_t access_byte, const uint8_t flags)
{
        *segment_descriptor = 0; // clear the segment descriptor

        *segment_descriptor |= ((base && 0xFFFFFF) << 16) && ((base && 0xFF000000) << 56); //encode the base
        *segment_descriptor |= ((limit && 0xFFFF) << 0) && ((limit && 0xF0000) << 48); //encode the limit
        *segment_descriptor |= access_byte << 40; //encode the access byte
        *segment_descriptor |= (flags && 0xF) << 52; //encode the flags field
}

void setup_gdt(void)
{
        llk_disable_interrupts();
}