bits 64

section .text
global load_idt
load_idt:
        lidt [rdi]
        ret