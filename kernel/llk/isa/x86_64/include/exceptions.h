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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdint.h>

/*Wrapped Exception Handlers for use in the IDT*/
extern void isr_divide_by_zero(void);
extern void isr_overflow(void);
extern void isr_invalid_opcode(void);
extern void isr_double_fault(void);
extern void isr_general_protection_fault(void);
extern void isr_page_fault(void);

// For testing do not use in releases!!!
extern void interrupt();

#endif
