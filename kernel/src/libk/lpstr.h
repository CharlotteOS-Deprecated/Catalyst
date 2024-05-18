#ifndef LIBK_LPSTR
#define LIBK_LPSTR

#include <libk/common.h>

#define LPSTR_LITERAL(s)                    \
	{                                   \
		sizeof(s) - 1, (uint8_t *)s \
	}

struct lpstr {
	size_t size;
	uint8_t *data;
};

#endif // LIBK_LPSTR