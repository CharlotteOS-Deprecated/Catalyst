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

#ifndef LLK_API_H
#define LLK_API_H

#include <stdint.h>

/*CPU*/
/*
Disables all maskable interrupts
Preconditions: None
Postconditions: All maskable interrupts are disabled on the calling logical processor
*/
void inline llk_disable_interrupts(void);
/*
Enables all maskable interrupts
Preconditions: None
Postconditions: All maskable interrupts are enabled on the calling logical processor
*/
void inline llk_enable_interrupts(void);
/*
Initializes a logical processor.
Preconditions: None
Postconditions: The processor will be initialized and ready to execute both kernel
and userspace code
*/
void llk_init_lp(void);
/*
Halt (and catch fire)
Preconditions: None
Postconditions: The logical processor is halted until a nonmaskable interrupt occurs
Note: This function never returns
*/
[[noreturn]]
void llk_hcf(void);

/*Serial Port*/
int32_t llk_init_serial(void);
void llk_serial_putc(const char c);

/*Memory*/
void llk_init_memory(void);

#endif
