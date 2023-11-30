#include "boot/include/requests.h"

#include <stddef.h>

[[maybe_unused]]
struct limine_memmap_request memory_map_request = {
        .id = LIMINE_MEMMAP_REQUEST,
        .revision = 0,
        .response = nullptr
};
