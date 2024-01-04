#ifndef ISA_TYPES_H
#define ISA_TYPES_H

/*Abstractions over ISA specific types*/

#ifdef __x86_64__

typedef paddr_t uint64_t;
typedef vaddr_t uint64_t;

#endif

#endif
