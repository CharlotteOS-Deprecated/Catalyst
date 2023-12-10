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


#include "string.h"

// GCC and Clang reserve the right to generate calls to the following
// 4 functions even if they are not directly called.
// Implement them as the C specification mandates.
// DO NOT remove or rename these functions, or stuff will eventually break!
// They CAN be moved to a different .c file.

extern void *memcpy(void *dest, const void *src, size_t n)
{
	uint8_t *pdest = (uint8_t *)dest;
	const uint8_t *psrc = (const uint8_t *)src;

	for (size_t i = 0; i < n; i++) {
		pdest[i] = psrc[i];
	}

	return dest;
}

extern void *memset(void *s, int c, size_t n)
{
	uint8_t *p = (uint8_t *)s;

	for (size_t i = 0; i < n; i++) {
		p[i] = (uint8_t)c;
	}

	return s;
}

extern void *memmove(void *dest, const void *src, size_t n)
{
	uint8_t *pdest = (uint8_t *)dest;
	const uint8_t *psrc = (const uint8_t *)src;

	if (src > dest) {
		for (size_t i = 0; i < n; i++)
		{
			pdest[i] = psrc[i];
		}
	} else if (src < dest) {
		for (size_t i = n; i > 0; i--) {
			pdest[i-1] = psrc[i-1];
		}
	}

	return dest;
}

extern int memcmp(const void *s1, const void *s2, size_t n)
{
	const uint8_t *p1 = (const uint8_t *)s1;
	const uint8_t *p2 = (const uint8_t *)s2;

	for (size_t i = 0; i < n; i++) {
		if (p1[i] != p2[i]) {
			return p1[i] < p2[i] ? -1 : 1;
		}
	}

	return 0;
}
