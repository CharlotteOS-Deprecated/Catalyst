/* 
Catalyst: A Standalone General Purpose OS Kernel
Copyright (C) 2023  Mohit D. Patel (mdpatelcsecon)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see https://www.gnu.org/licenses/
*/

#include <stdint.h>
#include <stddef.h>

#include "include/gdt.h"

#include "include/cpu.h"
#include "include/tss.h"

#include "hlk/log/include/log.h"


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
        *dest_upper = ((base & 0xFFFFFFFF00000000) >> 32ul);
}

void setup_gdt(gdt_t gdt, tss_t tss, void *const rsp0)
{
        disable_interrupts();

        //null descriptor
        create_segment_descriptor(&gdt[0], 0, 0, 0, 0);
        //kernel mode code segment descriptor
        create_segment_descriptor(&gdt[1], 0, 0xFFFFF, 0x9A, 0xA);
        //kernel mode data segment descriptor
        create_segment_descriptor(&gdt[2], 0, 0xFFFFF, 0x92, 0xC);
        //user mode code segment descriptor
        create_segment_descriptor(&gdt[3], 0, 0xFFFFF, 0xFA, 0xA);
        //user mode data segment descriptor
        create_segment_descriptor(&gdt[4], 0, 0xFFFFF, 0xF2, 0xC);
        //task state segment
        setup_tss(tss, rsp0);
        create_system_segment_descriptor(&gdt[5], (uint64_t) tss, (*tss) * TSS_N_ELEMENTS, 0x89, 0x0);

        enable_interrupts();
}

// assembly routines used to load the GDT
extern void set_gdt(const gdt_t gdt, volatile uint8_t gdtr[10]);
extern void reload_segments(void);

void load_gdt(gdt_t gdt)
{
        volatile uint8_t gdtr[10];
        log_puts("Setting GDT\r\n");
        set_gdt(gdt, gdtr);
        log_puts("Reloading Segment Registers\r\n");
        reload_segments();
}
