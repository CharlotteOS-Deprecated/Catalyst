/*freestanding headers*/
#include <stdint.h>
#include <stddef.h>

/*llk isa subsystem*/
#include "llk/isa/include/api.h"

/*hlk logging subsystem*/
#include "log/include/string.h"
#include "log/include/type_conv.h"
#include "log/include/log.h"

//kernel entry point
void catalyst_main(void)
{
	//initialize COM1
	if (llk_init_serial()) {
		llk_hcf();
	}
	log_puts("Starting Catalyst Kernel\r\n");

	llk_init_lp();
	log_puts("Initialized BSP\r\n");
	// We're done, just hang...
	log_puts("Halting...\r\n");
	llk_hcf();
}
