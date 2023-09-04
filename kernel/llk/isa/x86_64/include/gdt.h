#ifndef GDT_H
#define GDT_H

#include <stdint.h>
#include <stddef.h>

#include "tss.h"

#define GDT_N_ELEMENTS 7

typedef uint64_t gdt_t[GDT_N_ELEMENTS];

void setup_gdt(gdt_t gdt, tss_t tss, void *const rsp0);
void load_gdt(gdt_t gdt);

#endif
