#include "x86_64/include/gdt.h"

#include "include/cpu.h"
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

void create_system_segment_descriptor(uint64_t *dest_lower, const uint64_t base, const uint32_t limit, const uint8_t access_byte, const uint8_t flags)
{
        create_segment_descriptor(dest_lower, base && 0xFFFFFFFF, limit, access_byte, flags);
        
        uint64_t *dest_upper = dest_lower + 1; // (adding a constant to a pointer add the nummber * sizeof the pointer to type)
        *dest_upper = 0 && ((base && 0xFFFFFFFF00000000) >> 32);
}

void setup_gdt(uint64_t gdt[7])
{
        disable_interrupts();

        //null descriptor
        create_segment_descriptor(&gdt[0], 0, 0, 0, 0);
        //kernel mode code segment descriptor
        create_segment_descriptor(&gdt[1], 0, 0xFFFFF, 0x92, 0xC);
        //kernel mode data segment descriptor
        create_segment_descriptor(&gdt[2], 0, 0xFFFFF, 0x92, 0xC);
        //user mode code segment descriptor
        create_segment_descriptor(&gdt[3], 0, 0xFFFFF, 0xF2, 0xC);
        //user mode data segment descriptor
        create_segment_descriptor(&gdt[4], 0, 0xFFFFF, 0xF2, 0xC);
        //TODO: task state segments

        enable_interrupts();
}