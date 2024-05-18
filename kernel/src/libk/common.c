#include <libk/common.h>

size_t cstrlen(const char *str, size_t max)
{
    size_t len = 0;
    while (len < max && str[len] != '\0')
    {
	if (len >= max - 1)
	    return -1;
	len++;
    }
    return len;
}
