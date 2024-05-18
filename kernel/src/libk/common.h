#ifndef LIBK_COMMON
#define LIBK_COMMON

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define UNUSED(x) (void)(x)

#define nullptr NULL
#define true 1
#define false 0

/// @brief Get length of a null-terminated string.
/// @param str The string to get the length of.
/// @param max The maximum length of the string, size is -1 if no null is found by max.
/// @return The length of the string or -1.
extern size_t cstrlen(const char *str, size_t max);

#endif // LIBK_COMMON
