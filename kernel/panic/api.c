#include <stdbool.h>
#include "arch/api.h"
#include "log/log.h"

void panic(void) {
	log_puts("A kernel panic has occurred, halting system.\n");
	isa_hcf();
}

void assert([[maybe_unused]] bool expr) {
	#ifdef ASSERT
		if (expr == false)
			panic();
	#endif
}

void assert_not_null([[maybe_unused]] const void *const ptr) {
	#ifdef ASSERT
		if (ptr == nullptr)
			panic();
	#endif
}
