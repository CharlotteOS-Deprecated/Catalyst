#ifndef TSS_H
#define TSS_H

#include <stdint.h>
#include <stddef.h>

#define TSS_N_ELEMENTS 27

typedef uint32_t tss_t[TSS_N_ELEMENTS];

void setup_tss(tss_t tss, void *const rsp0);

#endif
