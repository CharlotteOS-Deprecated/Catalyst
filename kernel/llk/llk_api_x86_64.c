#ifdef __x86_64__

#include "include/llk_api.h"

#include "x86_64/include/cpu.h"
#include "x86_64/include/isa.h"
#include "x86_64/include/serial.h"

/*CPU*/
void llk_hcf(void)
{
        hcf();
}

/*Serial Port*/
int llk_init_serial(void)
{
        init_serial();
}
void llk_serial_putc(const char c)
{
        serial_putc(c);
}

#endif