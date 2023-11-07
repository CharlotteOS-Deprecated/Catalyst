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

#ifdef __x86_64__

#include "isa/include/api.h"

#include "isa/x86_64/include/cpu.h"
#include "isa/x86_64/include/gdt.h"
#include "isa/x86_64/include/idt.h"
#include "isa/x86_64/include/serial.h"
#include "isa/x86_64/include/tss.h"
#include "utility/include/string.h"
#include "utility/include/type_conv.h"
#include "log/include/log.h"

// Global Descriptor Table and Task State Segment
static gdt_t gdt;
static tss_t tss;
static uint8_t bsp_stack[4096];

// Interrupt Descriptor Table
static idt_t idt;


/*CPU*/
inline void isa_disable_interrupts(void)
{
        disable_interrupts();
}
inline void isa_enable_interrupts(void)
{
        enable_interrupts();
}
[[noreturn]]
void isa_hcf(void)
{
        hcf();
}
void isa_init_lp(void)
{
        // setup and load the GDT and TSS
        setup_gdt(gdt, tss, &bsp_stack);
        // setup the IDT with execption handlers and load it
        setup_idt(idt);
}

/*Serial Port*/
int32_t isa_init_serial(void)
{
        init_serial();
        return 0;
}
void isa_serial_putc(const char c)
{
        serial_putc(c);
}
#endif
