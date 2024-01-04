#include "vmm.h"



enum vmm_status vmm_attach_frame(pagemap_table_t *const pml4, const vaddr_t page_addr, const paddr_t frame_addr)
{
        if (page_addr == nullptr || frame_addr == 0ul)
                return INVALID_ARGUMENT;
        if ((uint64_t) page_addr % 4096ul || frame_addr % 4096ul)
                return INVALID_ALIGNMENT;
        
        /*Attach the frame at the requested address in the page tables*/
        (void) pml4;
        return SUCCESS;
}
