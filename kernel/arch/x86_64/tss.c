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

#include "arch/x86_64/tss.h"

#include "utility/string.h"

#define IOPB_END_BYTE 0xFF


void setup_tss(tss_t tss, void *const rsp0)
{
        // Zero out the TSS
        utility_memset(tss, 0, sizeof(uint32_t) * 27);

        // Set the value of the kernel stack
        uint64_t rsp0_uint = (uint64_t) rsp0;

        tss[1] = (uint32_t) (rsp0_uint & 0xFFFFFFFF);
        tss[2] = (uint32_t) ((rsp0_uint & 0xFFFFFFFF00000000) >> 32);

        // Set the offset of the IOPB
        tss[26] = 104 << 16;
        // Set the first byte of the IOPB to the end byte (all 1s) to signal that the IOPB will not be used
        tss[27] = 0xFF;
}
