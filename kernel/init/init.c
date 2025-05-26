#include "init.h"

#include "log/log.h"
#include "log/printf.h"

enum init_status ct_init()
{
	// Initialize the kernel
	// This function should be called before any other kernel functions
	// are called.
	// It should return INIT_SUCCESS if the initialization was successful,
	// INIT_FAILURE if there was an error, and INIT_HALT if the kernel
	// should halt.
	log_init();
	return INIT_SUCCESS;
}

enum init_status ct_deinit()
{
	// Deinitialize the kernel
	// This function should be called before the kernel is halted.
	// It should return INIT_SUCCESS if the deinitialization was successful,
	// INIT_FAILURE if there was an error, and INIT_HALT if the kernel
	// should halt.
	return INIT_SUCCESS;
}
