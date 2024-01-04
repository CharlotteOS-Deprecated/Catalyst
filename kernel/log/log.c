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

#include "limine.h"
#include "log.h"

#include "arch/api.h"

#include <flanterm/flanterm.h>
#include <flanterm/backends/fb.h>

#include "boot/requests.h"

#include "utility/string.h"

static struct flanterm_context *ft_ctx = nullptr;

void log_init(void)
{
        /*Initialize the flanterm context*/
        if(fb_request.response) {
                struct limine_framebuffer *first_fb = fb_request.response->framebuffers[0];
                ft_ctx = flanterm_fb_simple_init(first_fb->address, first_fb->width, first_fb->height, first_fb->pitch);
        }
}

inline void log_putc(const char c)
{
	isa_serial_putc(c);
}

void log_puts(const char *const str)
{
	for (size_t i = 0; str[i] != '\0'; ++i) {
		log_putc(str[i]);
	}
        flanterm_write(ft_ctx, str, utility_strlen(str));
}

void log_putln(const char* const str)
{
	log_puts(str);
	log_puts("\r\n");
}
