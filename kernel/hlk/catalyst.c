/*compiler and bootloader includes*/
#include <stdint.h>
#include <stddef.h>
#include "../limine/limine.h"

/*architecture specific setup*/
#include "llk/api/include/llk_api.h"

/*architecture independent includes*/
#include "hlk/include/string.h"
#include "hlk/include/type_conv.h"
#include "hlk/include/log.h"

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.
static volatile struct limine_framebuffer_request framebuffer_request = 
{
	.id = LIMINE_FRAMEBUFFER_REQUEST,
	.revision = 0
};

//kernel entry point
void catalyst_main(void)
{
	//initialize COM1
	if (llk_init_serial()) {
		llk_hcf();
	}
	log_puts("Starting Catalyst Kernel\r\n");

	// Ensure we got a framebuffer.
	if (framebuffer_request.response == NULL
		|| framebuffer_request.response->framebuffer_count < 1) {
		llk_hcf();
	}

	log_puts("Received framebuffer from Limine\r\n");

/* 	// Fetch the first framebuffer.
	struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

	// Note: we assume the framebuffer model is RGB with 32-bit pixels.
	for (size_t i = 0; i < 1000; i++) {
		uint32_t *fb_ptr = framebuffer->address;
		fb_ptr[i * (framebuffer->pitch / 4) + i] = 0x00ffffff;
	} */
halt:
	// We're done, just hang...
	log_puts("Halting...\r\n");
	llk_hcf();
}
