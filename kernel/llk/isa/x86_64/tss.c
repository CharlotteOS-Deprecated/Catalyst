#include "include/tss.h"

#include "hlk/log/include/string.h"

#define IOPB_END_BYTE 0xFF


void setup_tss(tss_t tss, void *const rsp0)
{
        // Zero out the TSS
        memset(tss, 0, sizeof(uint32_t) * 26);
        
        // Set the value of the kernel stack
        uint64_t rsp0_uint = (uint64_t) rsp0;

        tss[1] = (uint32_t) (rsp0_uint & 0xFFFFFFFF);
        tss[2] = (uint32_t) ((rsp0_uint & 0xFFFFFFFF00000000) >> 32);

        // Set the offset of the IOPB
        tss[26] = 101 << 16;
        // Set the first byte of the IOPB to the end byte (all 1s) to signal that the IOPB will not be used
        tss[27] = 0xFF;
}
