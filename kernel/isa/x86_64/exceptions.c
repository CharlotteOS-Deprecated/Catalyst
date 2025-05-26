#include "isa/x86_64/exceptions.h"

// freestanding
#include <stddef.h>

// in-module
#include "cpu.h"

// out-of-module
#include "log/log.h"
#include "panic/api.h"
#include "lib/string.h"
#include "lib/type_conv.h"

/*
Raw Exception Handlers

These have no forward declarations because they are only ever called from assembly
*/

void ih_divide_by_zero(void)
{
	log_puts("A divide by zero exception has occurred in kernelspace!\r\nPanicking!\r\n");
	panic();
}

void ih_overflow(void)
{
	log_puts("An overflow exception occurred!\r\n");
}

void ih_invalid_opcode(void)
{
	log_puts("An invalid opcode exception occurred!\r\n");
	panic();
}

void ih_general_protection_fault(const uint64_t int_err_code)
{
	log_puts("A general protection fault has occurred\r\n");
	log_puts("Error Code: ");
	char temp_str[21];
	utility_u64_to_dec_str(int_err_code, temp_str);
	log_puts(temp_str);
	log_puts("\r\n");

	panic();
	// TODO: Handle actual cases that can cause GP exceptions
}

void ih_double_fault(const uint64_t int_err_code)
{
	(void)int_err_code; // This value is always 0 and so not needed
	log_puts("A double fault has ocurred!\r\nPanicking!\r\n");
	panic();
}

void ih_page_fault(const uint64_t int_err_code)
{
	log_puts("A page fault has occurred\r\n");
	log_puts("Error Code: ");
	char temp_str[21];
	utility_memset(temp_str, 0, 21);
	utility_u64_to_hex_str(int_err_code, temp_str);
	log_puts(temp_str);
	log_puts("\r\n");
	get_regs();
	log_puts("Registers:\r\n");
	for (size_t i = 0; i < 16; ++i) {
		utility_memset(temp_str, 0, 21);
		utility_u64_to_hex_str(g_cpu_regs[i], temp_str);
		log_puts(temp_str);
		log_puts("\r\n");
	}
	panic();
}
