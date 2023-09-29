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
        // GDT and TSS
        setup_gdt(gdt, tss, &bsp_stack[1024]);
        log_puts("Global Descriptor Table:\r\n");
        for (size_t i = 0; i < 7; ++i) {
                memset(temp_str, '\0', 1024);
                u64_to_hex_str(gdt[i], temp_str);
                log_puts(temp_str);
                log_puts("\r\n");
        }
        load_gdt(gdt);

        // IDT with entries for exceptions
        memset(idt, 0, IDT_N_ELEMENTS * GATE_DESC_SZ);
        
        //set_gate_descriptor(idt, 0, &isr_double_fault, 1 << 3, TRAP_GATE, true);
        // install the double fault handler at vector 8
        set_gate_descriptor(idt, 8, &isr_double_fault, 1 << 3, TRAP_GATE, true);
        set_gate_descriptor_present_bit(idt, 8, true);
        log_puts("Interrupt Descriptor Table\r\n");
        for (size_t i = 0; i < 512; i+=8) {
                memset(temp_str, '\0', 1024);
                u64_to_hex_str(*((uint64_t*) &idt[i]), temp_str);
                log_puts(temp_str);
                log_puts("\r\n");
        }

        idt_desc_t idt_desc;
        make_idt_desc(idt_desc, idt);
        load_idt(idt_desc);

        log_puts("Double Fault Present Bit: ");
        log_puts(is_gate_descriptor_present(idt, 8) ? "set" : "cleared");
        log_puts("\r\n");
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
