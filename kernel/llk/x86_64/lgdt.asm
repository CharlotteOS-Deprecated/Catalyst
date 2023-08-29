bits 64

section .text
global set_gdt
set_gdt:
        mov word [rsi], 56
        mov qword [rsi + 2], rdi 
        lgdt [rsi]
        ret
global reload_segments
reload_segments:
        mov rax, 1 ; segment descriptor 1 is the kernel code segment
        shl rax, 3
        push rax
        lea rax, [rel .reload_cs]
        push rax
        retfq
.reload_cs:
        mov ax, 2 ; segment descriptor 2 is the kernel data segment
        shl ax, 3
        mov ds, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ss, ax
        ret
