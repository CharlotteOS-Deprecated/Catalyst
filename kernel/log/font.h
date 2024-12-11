#ifndef FONT_H
#define FONT_H

#include <stddef.h>
#include <stdint.h>

static const size_t FONT_WIDTH = 8;
static const size_t FONT_HEIGHT = 16;
static const size_t CHAR_COUNT = 256 * FONT_HEIGHT;
extern const uint8_t FONT[];

#endif // FONT_H
