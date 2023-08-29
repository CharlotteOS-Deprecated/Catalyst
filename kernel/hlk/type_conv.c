#include "hlk/include/type_conv.h"
#include "hlk/include/string.h"

#include <stdint.h>

void swap_endianness(uint8_t *bytes, size_t nbytes)
{
	uint8_t temp;
	for (size_t i = 0; i < (nbytes / 2); ++i) {
		temp = bytes[i];
		bytes[i] = bytes[nbytes - i];
		bytes[nbytes - i] = temp;
	}
}

int u64_to_bin_str(const uint64_t n, char str[66])
{
	if (str == NULL)
		return -1;
	//convert
	for (uint64_t i = 0; i < 64; ++i) {
		if ((n & (1ull << i)) != 0) {
			str[63 - i] = '1';
		} else {
			str[63 - i] = '0';
		}
	}
	//Put down the suffix and terminating null character
	memcpy(&str[64ull], "b", 2ull);
	//return success
	return 0;
}

static const char digit_array[] = "0123456789ABCDEF";

uint64_t pow(uint64_t base, uint64_t exponent)
{
	uint64_t result = 1;
	for(size_t i = 0; i < exponent; ++i) {
		result *= base;
	}
	return result;
}

int u64_to_hex_str(uint64_t n, char str[18]) {
	if (str == NULL) {
		return -1;
	}

	for (int i = 0; i < 16; i++) {
		uint64_t digit = (n >> (60 - 4 * i)) & 0xF;  // Extract each hex digit
		str[i] = digit_array[digit];
	}

	memcpy(&str[16], "h", 2);

	return 0;
}
int u64_to_dec_str(uint64_t n, char str[21]) {
	if (str == NULL) {
		return -1;
	}

	int i = 19; // Start from the end of the string
	do {
		str[i--] = digit_array[n % 10]; // Get the last digit
		n /= 10; // Remove the last digit
	} while(n != 0);

	// Shift all characters down to the start of the string
		int start = i + 1;
	for(int j = 0; j < 20 - start; j++) {
		str[j] = str[j + start];
	}

	str[20 - start] = '\0'; // Null-terminate the string

	return 0;
}
