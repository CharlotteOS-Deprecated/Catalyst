#ifndef ISA_TYPES_H
#define ISA_TYPES_H

/*Abstractions over ISA specific types*/

#include "isa/x86_64/memory/types.h"
#ifdef __x86_64__

typedef uint64_t paddr_t;
typedef uint64_t vaddr_t;

#endif

#endif
