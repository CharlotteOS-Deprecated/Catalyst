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

#include "include/api.h"

#include "x86_64/include/cpu.h"
#include "x86_64/include/gdt.h"
#include "x86_64/include/idt.h"
#include "x86_64/include/serial.h"
#include "x86_64/include/tss.h"

#include "hlk/log/include/log.h"
#include "hlk/log/include/string.h"
#include "hlk/log/include/type_conv.h"

// Global Descriptor Table and Task State Segment
static gdt_t gdt;
static tss_t tss;
static uint8_t bsp_stack[4096];

// Interrupt Descriptor Table
static idt_t idt;


/*CPU*/
void inline llk_disable_interrupts(void)
{
        disable_interrupts();
}
void inline llk_enable_interrupts(void)
{
        enable_interrupts();
}
[[noreturn]]
void llk_hcf(void)
{
        hcf();
}
void llk_init_lp(void)
{
        // setup and load the GDT and TSS
        setup_gdt(gdt, tss, &bsp_stack);
        // setup the IDT with execption handlers and load it
        setup_idt(idt);
}

/*Serial Port*/
int32_t llk_init_serial(void)
{
        init_serial();
        return 0;
}
void llk_serial_putc(const char c)
{
        serial_putc(c);
}
#endif
