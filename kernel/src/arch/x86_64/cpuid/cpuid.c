#include <libk/common.h>
#include "cpuid.h"
#include "utility/string.h"
#include <stdint.h>

extern bool asm_is_cpuid_available(void);
extern void asm_get_cpu_vendor_id(char dest[13]);
extern void asm_get_max_cpuid_eax(uint32_t *const dest);
extern void asm_get_cpu_addr_nbits(uint8_t *const paddr_bits, uint8_t *const vaddr_bits);

enum cpuid_status get_cpuid_info(struct cpuid_info *const dest)
{
        if(dest == nullptr)
                return INVALID_DEST;
        if(!asm_is_cpuid_available())
                return CPUID_NOT_SUPPORTED;

        //utility_memset(dest, 0, sizeof(*dest));
        asm_get_cpu_vendor_id(dest->vendor_id);
        asm_get_max_cpuid_eax(&(dest->max_cpuid_eax));
        asm_get_cpu_addr_nbits(&(dest->paddr_bits), &(dest->vaddr_bits));
        return SUCCESS;
}
