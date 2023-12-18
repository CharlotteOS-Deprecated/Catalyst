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

#ifndef STRING_H
#define STRING_H

#include <stdint.h>
#include <stddef.h>

#define utility_memcpy memcpy
#define utility_memset memset
#define utility_memmove memmove
#define utility_memcmp memcmp
#define utility_strlen strlen

size_t strlen(const char *str);

/*DO NOT CHANGE THE NAMES OF THESE FUNCTIONS THEY ARE REQUIRED BY THE COMPILER!!!*/

extern void *memcpy(void *dest, const void *src, size_t n);
extern void *memset(void *s, int c, size_t n);
extern void *memmove(void *dest, const void *src, size_t n);
extern int memcmp(const void *s1, const void *s2, size_t n);



#endif
