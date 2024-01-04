#include "boot/requests.h"
#include "limine.h"

#include <stddef.h>

[[maybe_unused]]
struct limine_memmap_request memory_map_request = {
        .id = LIMINE_MEMMAP_REQUEST,
        .revision = 0,
        .response = nullptr
};

[[maybe_unused]]
struct limine_framebuffer_request fb_request = {
        .id = LIMINE_FRAMEBUFFER_REQUEST,
        .revision = 0,
        .response = nullptr
};

[[maybe_unused]]
struct limine_hhdm_request hhdm_request = {
        .id = LIMINE_HHDM_REQUEST,
        .revision = 0,
        .response = nullptr
};
