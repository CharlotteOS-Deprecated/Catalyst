#ifndef PANIC_API_H
#define PANIC_API_H

#include "isa/include/api.h"
#include "log/include/log.h"


[[noreturn]]
inline void panic()
{
        log_puts("A kernel panic has occurred!!!");
        isa_hcf();
}


void assert([[maybe_unused]] const bool expr)
{
#ifdef ASSERT
        if (expr == false)
                panic();
#endif
}

void assert_not_null([[maybe_unused]] const void *const ptr)
{
#ifdef ASSERT
        if (ptr == nullptr)
                panic();
#endif
}


#endif
