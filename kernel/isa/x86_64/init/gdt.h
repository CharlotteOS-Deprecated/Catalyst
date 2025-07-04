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

#ifndef GDT_H
#define GDT_H

#include <stddef.h>
#include <stdint.h>

#include "isa/x86_64/init/tss.h"

#define GDT_N_ELEMENTS 7

typedef uint64_t gdt_t[GDT_N_ELEMENTS];

void setup_gdt(gdt_t gdt, tss_t tss, void *const rsp0);
void load_gdt(gdt_t gdt);

#endif
