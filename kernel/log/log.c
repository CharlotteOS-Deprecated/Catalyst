/*
Catalyst: A General Purpose OS Kernel
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

#include <stddef.h>

#include "log.h"

#include "isa/api.h"

inline void log_putc(const char c)
{
	isa_serial_putc(c);
}

void log_puts(const char *const str)
{
	for (size_t i = 0; str[i] != '\0'; ++i) {
		log_putc(str[i]);
	}
}

void log_putln(const char* const str)
{
	log_puts(str);
	log_puts("\r\n");
}
