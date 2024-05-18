#ifndef LIBK_LPBUF
#define LIBK_LPBUF

#include <libk/common.h>

struct lpbuf {
	size_t size;
	uint8_t *data;
};

typedef struct lpbuf lpbuf_t;

/// @brief Initialize a buffer with a given size and data.
/// @param self The buffer to initialize, must be allocated.
/// @param size size of the data.
/// @param data pointer to the data.
extern inline void lpbuf_init(lpbuf_t *self, size_t size, void *data);

#endif // LIBK_LPBUF