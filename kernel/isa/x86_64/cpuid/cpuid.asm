bits 64

section .text
global asm_is_cpuid_available
asm_is_cpuid_available:
        pushfq;save the flags to the stack
        pushfq
        pop rax
        or rax, (1 << 21);set the ID flag (bit 21)
        push rax
        popfq
        pushfq
        pop rax
        and rax, (1 << 21);check to see if the ID bit was changed
        shr rax, 21
        popfq;restore the saved flags
        ret
