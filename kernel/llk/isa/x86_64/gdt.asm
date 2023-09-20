; Catalyst: A Standalone General Purpose OS Kernel
; Copyright (C) 2023  Mohit D. Patel (mdpatelcsecon)

; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program.  If not, see https://www.gnu.org/licenses/

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
global load_tss
load_tss:
        mov ax, 5
        shl ax, 3
        ltr ax
        ret