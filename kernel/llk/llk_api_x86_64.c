#ifdef __x86_64__

#include "include/llk_api.h"

#include "x86_64/include/cpu.h"
#include "x86_64/include/gdt.h"
#include "x86_64/include/isa.h"
#include "x86_64/include/serial.h"

#include "../hlk/include/log.h"
#include "../hlk/include/string.h"
#include "../hlk/include/type_conv.h"

static uint64_t gdt[7];

/*CPU*/
void inline llk_disable_interrupts(void)
{
        disable_interrupts();
}
void inline llk_enable_interrupts(void)
{
        enable_interrupts();
}
[[noreturn]]
void llk_hcf(void)
{
        hcf();
}
void llk_init_lp(void)
{
        setup_gdt(gdt);
        log_puts("Global Descriptor Table:\r\n");
        llk_hcf();
        for (size_t i = 0; i < 7; ++i) {
                memset(temp_str, '\0', 1024);
                u64_to_hex_str(gdt[i], temp_str);
                log_puts(temp_str);
                log_puts("\r\n");
        }
}

/*Serial Port*/
int32_t llk_init_serial(void)
{
        init_serial();
        return 0;
}
void llk_serial_putc(const char c)
{
        serial_putc(c);
}

/*Memory*/
void llk_init_memory(void)
{
}

#endif
