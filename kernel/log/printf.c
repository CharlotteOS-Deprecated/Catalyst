#include "printf.h"

#include "log.h"
#include "utility/type_conv.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

void printf(const char *__restrict format, ...)
{
	va_list args;
	va_start(args, format);

	if (!format)
		return; // Null check

	size_t count = 0ull;

	while (format[count] != '\0') {
		if (format[count] == '%') {
			count++;

			// Handle %% escape
			if (format[count] == '%') {
				log_putc('%');
				++count;
				continue;
			}

			switch (format[count]) {
			case 's': {
				const char *str = va_arg(args, const char *const);
				if (str)
					log_puts(str);
				else
					log_puts("(null)");
				break;
			}
			case 'd': {
				log_puts(
				    utility_u64_to_dec_str(va_arg(args, const uint64_t), temp_str));
				break;
			}
			case 'x': {

				log_puts(
				    utility_u64_to_hex_str(va_arg(args, const uint64_t), temp_str));
				break;
			}
			case 'b': {
				// Print binary representation
				log_puts(
				    utility_u64_to_bin_str(va_arg(args, const uint64_t), temp_str));
				break;
			}
			default:
				// for unknown format specifier, print it as is
				log_putc('%');
				log_putc(format[count]);
				log_puts("\r\n");
				break;
			}
		} else {
			log_putc(format[count]);
		}
		++count;
	}
	va_end(args);
}
