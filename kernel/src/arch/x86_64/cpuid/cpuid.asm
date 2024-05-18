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

global asm_get_cpu_vendor_id
asm_get_cpu_vendor_id:
        mov r10, rbx ; save rbx as required by the ABI
        mov eax, 0x80000000
        cpuid
        mov [rdi], ebx
        mov [rdi + 4], edx
        mov [rdi + 8], ecx
        mov rbx, r10 ; restore rbx
        ret
global asm_get_max_cpuid_eax
asm_get_max_cpuid_eax:
        mov r10, rbx ; save rbx as required by the ABI
        mov eax, 0x80000000
        cpuid
        mov [rdi], eax
        mov rbx, r10 ; restore rbx
        ret

global asm_get_cpu_addr_nbits
asm_get_cpu_addr_nbits:
        mov r10, rbx ; save rbx as required by the ABI
        mov eax, 0x80000008
        cpuid
        mov [rdi], al
        mov [rsi], ah
        mov rbx, r10 ; restore rbx
        ret