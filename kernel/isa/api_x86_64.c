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

#include "isa/api.h"

#include "drivers/uart/ns16550/serial.h"
#include "isa/x86_64/cpu.h"
#include "isa/x86_64/gdt.h"
#include "isa/x86_64/idt.h"
#include "isa/x86_64/tss.h"
#include "log/log.h"
#include "lib/string.h"
#include "lib/type_conv.h"

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

/*Port I/O*/
inline uint8_t isa_port_in(const uint16_t port)
{
	return inb(port);
}
inline void isa_port_out(const uint16_t port, const uint8_t data)
{
	outb(port, data);
}

#endif
