#ifndef LLK_API_H
#define LLK_API_H

#include <stdint.h>

/*CPU*/
/*
Disables all maskable interrupts
Preconditions: None
Postconditions: All maskable interrupts are disabled on the calling logical processor
*/
void inline llk_disable_interrupts(void);
/*
Enables all maskable interrupts
Preconditions: None
Postconditions: All maskable interrupts are enabled on the calling logical processor
*/
void inline llk_enable_interrupts(void);
/*
Initializes a logical processor.
Preconditions: None
Postconditions: The processor will be initialized and ready to execute both kernel
and userspace code
*/
void llk_init_lp(void);
/*
Halt (and catch fire)
Preconditions: None
Postconditions: The logical processor is halted until a nonmaskable interrupt occurs
Note: This function never returns
*/
[[noreturn]]
void llk_hcf(void);

/*Serial Port*/
int32_t llk_init_serial(void);
void llk_serial_putc(const char c);

/*Memory*/
void llk_init_memory(void);

#endif
