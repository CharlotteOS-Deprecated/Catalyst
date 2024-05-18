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

#include "arch/api.h"

#include "arch/x86_64/cpu.h"
#include "arch/x86_64/gdt.h"
#include "arch/x86_64/idt.h"
#include "arch/x86_64/serial.h"
#include "arch/x86_64/tss.h"
#include "log/log.h"
#include "utility/string.h"
#include "utility/type_conv.h"

// Global Descriptor Table and Task State Segment
static gdt_t BSP_GDT;
static tss_t BSP_TSS;
static uint8_t BSP_STACK[4096];

// Interrupt Descriptor Table
static idt_t BSP_IDT;

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
void isa_init_bsp(void)
{
	// setup and load the GDT and TSS
	setup_gdt(BSP_GDT, BSP_TSS, BSP_STACK);
	// setup the IDT with execption handlers and load it
	setup_idt(BSP_IDT);
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
