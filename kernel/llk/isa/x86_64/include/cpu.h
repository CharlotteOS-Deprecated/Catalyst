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

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// Global used to return from get_regs so that no general purpose registers
// are used as out parameters and no memory need be allocated
extern uint64_t g_cpu_regs[16];

// Interrupt flag set/clear
extern void disable_interrupts(void);
extern void enable_interrupts(void);

// I/O Ports
extern uint8_t inb(volatile uint16_t);
extern void outb(volatile uint16_t, volatile uint8_t);

// Save CPU registers to a global array
extern void get_regs(void);

// Get interrupt error code
extern uint64_t get_int_error_code(void);

// Halt and catch fire aka panic
[[noreturn]]
extern void hcf(void);

#endif
