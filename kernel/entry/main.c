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
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "arch/api.h"
#include "arch/x86_64/cpu.h"
#include "arch/x86_64/cpuid/cpuid.h"
#include "arch/x86_64/exceptions.h"
#include "boot/requests.h"
#include "log/log.h"
#include "log/printv.h"
#include "utility/string.h"
#include "utility/type_conv.h"

static const char license_string[] =
    "Catalyst: A General Purpose OS Kernel\r\n\r\n"
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
// kernel entry point
extern void main(void)
{
	// initialize COM1
	if (isa_init_serial()) {
		isa_hcf();
	}
	log_init();

	log_puts(license_string);
	log_puts("\r\n");
	log_puts("Initializing Catalyst\r\n");
	log_puts("\r\n");

	isa_init_bsp();
	log_puts("Initialized BSP\r\n");

	// log_puts("Performing interrupt test\r\n");
	// interrupt();
	// log_puts("Returned from interrupt service routine\r\n");

	log_puts("Memory Map Response Address: ");
	log_putln(utility_u64_to_hex_str((uint64_t)memory_map_request.response, temp_str));

	log_putln("Obtaining CPU information...");
	enum cpuid_status id_err = get_cpuid_info(&cpuinfo);
	log_puts("Obtaining CPU information complete with status: ");
	switch (id_err) {
	case CPUID_NOT_SUPPORTED:
		log_putln("CPUID_NOT_SUPPORTED");
		break;
	case INVALID_DEST:
		log_putln("INVALID_DEST");
		break;
	case SUCCESS:
		log_putln("SUCCESS");
		log_puts("CPU vendor ID: ");
		log_putln(cpuinfo.vendor_id);
		log_puts("Max supported EAX value for CPUID instruction: ");
		log_putln(utility_u64_to_dec_str(cpuinfo.max_cpuid_eax, temp_str));
		log_puts("Number of significant physical address bits: ");
		log_putln(utility_u64_to_dec_str(cpuinfo.paddr_bits, temp_str));
		log_puts("Number of significant virtual address bits: ");
		log_putln(utility_u64_to_dec_str(cpuinfo.vaddr_bits, temp_str));
		break;
	}

	log_putln("Checking Limine HHDM request for response");
	if (hhdm_request.response == nullptr) {
		log_putln("Higher Half Direct Map not available");
	} else {
		log_puts("Higher Half Direct Map available at virtual address ");
		log_putln(utility_u64_to_hex_str(hhdm_request.response->offset, temp_str));
	}

	printv("Testing printv\nString: %s\nDecimal: %d\nHex: %x\nBinary: %b\n",
	       (size_t[]){(size_t)"Hello, World!", 42ull, 42ull, 42ull});
	printv("Testing without arguments.\n", nullptr);

	// We're done, just hang...
	log_putln("Initialization complete, waiting for interrupts...");
	isa_hcf();
}
