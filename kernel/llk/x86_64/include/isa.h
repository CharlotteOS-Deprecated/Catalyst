#ifndef ISA_H
#define ISA_H

#include <stdint.h>

extern uint8_t inb(volatile uint16_t);
extern void outb(volatile uint16_t, volatile uint8_t);
extern void reg_test(void);

#endif
