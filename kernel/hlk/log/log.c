#include "include/log.h"

#include "../../llk/isa/include/api.h"

static void (*const log_putc)(const char) = &llk_serial_putc;

void log_puts(const char *str)
{
	while (*str != '\0') {
		log_putc(*str);
		++str;
	}
}
