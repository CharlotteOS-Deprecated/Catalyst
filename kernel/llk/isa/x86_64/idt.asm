bits 64

section .text
global set_idt
set_idt:
        lidt [rdi]
        ret