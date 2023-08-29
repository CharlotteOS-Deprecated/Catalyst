#include <stdint.h>
#include <stddef.h>

#include "include/gdt.h"

#include "include/cpu.h"
#include "include/tss.h"


void create_segment_descriptor(uint64_t *const segment_descriptor, const uint32_t base, const uint32_t limit, const uint8_t access_byte, const uint8_t flags)
{
        *segment_descriptor = 0; // clear the segment descriptor

        *segment_descriptor |= ((base & 0xFFFFFFul) << 16ul) & ((base & 0xFF000000ul) << 56ul); //encode the base
        *segment_descriptor |= ((limit & 0xFFFFul) << 0ul) & ((limit & 0xF0000ul) << 48ul); //encode the limit
        *segment_descriptor |= (((uint64_t) access_byte) << 40ul); //encode the access byte
        *segment_descriptor |= (flags & 0xFul) << 52ul; //encode the flags field
}

void create_system_segment_descriptor(uint64_t *dest_lower, const uint64_t base, const uint32_t limit, const uint8_t access_byte, const uint8_t flags)
{
        create_segment_descriptor(dest_lower, base & 0xFFFFFFFFu, limit, access_byte, flags);
        
        uint64_t *dest_upper = dest_lower + 1; // (adding a constant to a pointer adds the constant * sizeof the pointed to type)
        *dest_upper = 0ul | ((base & 0xFFFFFFFF00000000) >> 32ul);
}

void setup_gdt(gdt_t gdt, tss_t tss, void *const rsp0)
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
        //task state segment
        setup_tss(tss, rsp0);
        create_system_segment_descriptor(&gdt[5], tss, (*tss) * TSS_N_ELEMENTS, 0x89, 0x0);

        enable_interrupts();
}
