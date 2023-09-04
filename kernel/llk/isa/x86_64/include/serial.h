#ifndef SERIAL_H
#define SERIAL_H

#include <stddef.h>
#include <stdint.h>


int init_serial(void);
char serial_putc(char c);

#endif
