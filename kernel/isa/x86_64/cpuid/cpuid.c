#include "cpuid.h"
#include <stdint.h>

extern bool asm_is_cpuid_available(void);
extern void asm_get_cpu_vendor_id(char dest[13]);
extern void asm_get_cpu_addr_nbits(uint8_t *const paddr_bits, uint8_t *const vaddr_bits);

enum cpuid_err get_cpuid_info(struct cpuid_info *const dest)
{
        if(dest == nullptr)
                return INVALID_DEST;
        if(!asm_is_cpuid_available())
                return CPUID_NOT_SUPPORTED;

        //asm_get_cpu_vendor_id(dest->vendor_id);
        //asm_get_cpu_addr_nbits(&dest->paddr_bits, &dest->vaddr_bits);
        return SUCCESS;
}
