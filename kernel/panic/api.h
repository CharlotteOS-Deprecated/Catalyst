#ifndef PANIC_API_H
#define PANIC_API_H

void panic(void);
void assert([[maybe_unused]] const bool expr);
void assert_not_null([[maybe_unused]] const void *const ptr);

#endif
