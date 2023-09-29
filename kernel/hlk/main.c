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

/*freestanding headers*/
#include <stdint.h>
#include <stddef.h>

/*llk isa subsystem*/
#include "llk/isa/include/api.h"

/*hlk logging subsystem*/
#include "log/include/string.h"
#include "log/include/type_conv.h"
#include "log/include/log.h"

static const char license_string[] = \
	"Catalyst: A Standalone General Purpose OS Kernel\r\n\r\n"
	"Copyright (C) 2023  Mohit D. Patel (mdpatelcsecon)\r\n\r\n"

	"This program is free software: you can redistribute it and/or modify\r\n"
	"it under the terms of the GNU General Public License as published by\r\n"
	"the Free Software Foundation, either version 3 of the License, or\r\n"
	"(at your option) any later version.\r\n"

	"This program is distributed in the hope that it will be useful,\r\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\r\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\r\n"
	"GNU General Public License for more details.\r\n"

	"You should have received a copy of the GNU General Public License\r\n"
	"along with this program. If not, see https://www.gnu.org/licenses/\r\n\r\n";

//kernel entry point
void main(void)
{
	//initialize COM1
	if (llk_init_serial()) {
		llk_hcf();
	}
	log_puts(license_string);
	log_puts("\r\n");
	log_puts("Initializing Catalyst\r\n");
	log_puts("\r\n");

	llk_init_lp();
	log_puts("Initialized BSP\r\n");
	// We're done, just hang...
	log_puts("Halting...\r\n");
	llk_hcf();
}
