#include "llk/api/include/llk_api.h"

#if TARGET==x64_UEFI_ACPI

#include "llk/x64_uefi_acpi/include/serial.h"
#include "llk/x64_uefi_acpi/include/cpu.h"

/*Serial Port*/
int llk_init_serial(void)
{
        return init_serial();
}
void llk_serial_putc(const char c)
{
        serial_putc(c);
}

/*CPU*/
void llk_hcf(void)
{
        hcf();
}

#endif