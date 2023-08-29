/*compiler and bootloader includes*/
#include <stdint.h>
#include <stddef.h>
#include "../../limine/limine.h"

/*hardware specific setup*/
#include "llk/include/llk_api.h"

/*architecture independent includes*/
#include "hlk/include/string.h"
#include "hlk/include/type_conv.h"
#include "hlk/include/log.h"

//kernel entry point
void catalyst_main(void)
{
	//initialize COM1
	if (llk_init_serial()) {
		llk_hcf();
	}
	log_puts("Starting Catalyst Kernel\r\n");

	//llk_init_lp();
	log_puts("Initialized BSP\r\n");
	// We're done, just hang...
	log_puts("Halting...\r\n");
	llk_hcf();
}
