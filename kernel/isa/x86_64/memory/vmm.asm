bits 64

section .text
global asm_get_active_pgmap_paddr
asm_get_active_pgmap_paddr:
        mov rax, cr3
        ret