#ifndef CPU_H
#define CPU_H

extern void disable_interrupts(void);
extern void enable_interrupts(void);
[[noreturn]] 
extern void hcf(void);
extern uint8_t inb(volatile uint16_t);
extern void outb(volatile uint16_t, volatile uint8_t);

#endif
