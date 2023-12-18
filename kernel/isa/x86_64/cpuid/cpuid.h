#include <stdint.h>

/*This folder provides the code necessary to get information needed by kernel that comes from the CPUID instruction*/

struct cpuid_info {
        char vendor_id[13];
        uint32_t max_cpuid_eax;
        uint8_t paddr_bits;
        uint8_t vaddr_bits;
};

enum cpuid_status {
        SUCCESS = 0,
        CPUID_NOT_SUPPORTED = 1,
        INVALID_DEST = 2
};

static struct cpuid_info cpuinfo;

enum cpuid_status get_cpuid_info(struct cpuid_info *const dest);
