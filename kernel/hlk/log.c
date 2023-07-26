#include "hlk/include/log.h"

#include "llk/include/llk_api.h"

void log_puts(const char *str)
{
	while (*str != '\0') {
		llk_serial_putc(*str);
		++str;
	}
}
