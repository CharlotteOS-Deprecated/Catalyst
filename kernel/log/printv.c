#include "printv.h"
#include "log.h"
#include "utility/type_conv.h"
#include <stddef.h>

void printv(const char *const format, void *const args)
{
	if (!format)
		return; // Null check

	size_t count = 0ull, argnum = 0ull;

	while (format[count] != '\0') {
		if (format[count] == '%') {
			count++;

			// Handle %% escape
			if (format[count] == '%') {
				log_putc('%');
				count++;
				continue;
			}

			switch (format[count]) {
			case 's': {
				const char *str = ((const char *const *)args)[argnum];
				if (str)
					log_puts(str);
				else
					log_puts("(null)");
				break;
			}
			case 'd': {
				log_puts(utility_u64_to_dec_str(
				    ((const uint64_t *const)args)[argnum], temp_str));
				break;
			}
			case 'x': {
				log_puts(utility_u64_to_hex_str(
				    ((const uint64_t *const)args)[argnum], temp_str));
				break;
			}
			case 'b': {
				log_puts(utility_u64_to_bin_str(
				    ((const uint64_t *const)args)[argnum], temp_str));
				break;
			}
			default:
				log_puts("printv: Encountered Unknown format specifier %");
				log_putc(format[count]);
				log_puts("\r\n");
				break; // Handle unknown format specifiers
			}
			argnum++;
		} else {
			log_putc(format[count]);
		}
		count++;
	}
}
