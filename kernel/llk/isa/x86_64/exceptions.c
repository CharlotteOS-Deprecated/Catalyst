#include "include/exceptions.h"

#include "include/cpu.h"

#include "hlk/log/include/log.h"

void ih_double_fault(void)
{
        log_puts("A double fault has ocurred!\r\nPanicking!\r\n");
        hcf();
}
