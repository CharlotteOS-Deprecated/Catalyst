#ifndef TYPE_CONV_H
#define TYPE_CONV_H

#include <stdint.h>

static char temp_str[1024];

int u64_to_bin_str(const uint64_t n, char str[66]);
int u64_to_hex_str(const uint64_t n, char str[18]);
int u64_to_dec_str(const uint64_t n, char str[21]);

#endif
