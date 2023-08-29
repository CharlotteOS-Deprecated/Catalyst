#ifndef CPU_H
#define CPU_H

extern void disable_interrupts(void);
extern void enable_interrupts(void);
[[noreturn]]
extern void hcf(void);

#endif
