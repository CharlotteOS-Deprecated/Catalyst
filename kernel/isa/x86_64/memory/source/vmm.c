#include "include/vmm.h"

int32_t vmm_attach_frame(const vaddr_t page_addr, const paddr_t frame_addr)
{
        if (page_addr == nullptr || frame_addr == 0ul)
                return INVALID_ARGUMENT;
        if ((uint64_t) page_addr % 4096ul || frame_addr % 4096ul)
                return INVALID_ALIGNMENT;
        
        /*Attach the frame at the requested address in the page tables*/

        return SUCCESS;
}
