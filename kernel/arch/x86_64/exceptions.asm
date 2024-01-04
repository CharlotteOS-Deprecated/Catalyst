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


; ISRs for CPU based interrupts a.k.a. exceptions

bits 64

section .bss
bsp_int_regs: resq 16

section .text

save_int_regs:
        mov [rel bsp_int_regs + 0 * 8], rax
        mov [rel bsp_int_regs + 1 * 8], rbx
        mov [rel bsp_int_regs + 2 * 8], rcx
        mov [rel bsp_int_regs + 3 * 8], rdx
        mov [rel bsp_int_regs + 4 * 8], rsi
        mov [rel bsp_int_regs + 5 * 8], rdi
        mov [rel bsp_int_regs + 6 * 8], rsp
        mov [rel bsp_int_regs + 7 * 8], rbp
        mov [rel bsp_int_regs + 8 * 8], r8
        mov [rel bsp_int_regs + 9 * 8], r9
        mov [rel bsp_int_regs + 10 * 8], r10
        mov [rel bsp_int_regs + 11 * 8], r11
        mov [rel bsp_int_regs + 12 * 8], r12
        mov [rel bsp_int_regs + 13 * 8], r13
        mov [rel bsp_int_regs + 14 * 8], r14
        mov [rel bsp_int_regs + 15 * 8], r15
        ret
restore_int_regs: 
        mov rax, [rel bsp_int_regs + 0 * 8]
        mov rbx, [rel bsp_int_regs + 1 * 8]
        mov rcx, [rel bsp_int_regs + 2 * 8]
        mov rdx, [rel bsp_int_regs + 3 * 8]
        mov rsi, [rel bsp_int_regs + 4 * 8]
        mov rdi, [rel bsp_int_regs + 5 * 8]
        mov rsp, [rel bsp_int_regs + 6 * 8]
        mov rbp, [rel bsp_int_regs + 7 * 8]
        mov r8, [rel bsp_int_regs + 8 * 8]
        mov r9, [rel bsp_int_regs + 9 * 8]
        mov r10, [rel bsp_int_regs + 10 * 8]
        mov r11, [rel bsp_int_regs + 11 * 8]
        mov r12, [rel bsp_int_regs + 12 * 8]
        mov r13, [rel bsp_int_regs + 13 * 8]
        mov r14, [rel bsp_int_regs + 14 * 8]
        mov r15, [rel bsp_int_regs + 15 * 8]
        ret

extern get_int_error_code

global isr_divide_by_zero
extern ih_divide_by_zero
isr_divide_by_zero:
        call save_int_regs
        call ih_divide_by_zero
        call restore_int_regs
        iretq

global isr_overflow
extern ih_overflow
isr_overflow:
        call save_int_regs
        call ih_overflow
        call restore_int_regs
        iretq

global isr_invalid_opcode
extern ih_invalid_opcode
isr_invalid_opcode:
        call save_int_regs
        call ih_invalid_opcode
        call restore_int_regs
        iretq

global isr_double_fault
extern ih_double_fault
isr_double_fault:
        call get_int_error_code
        mov rdi, rax ; move the return of the last call into the argument of the next
        ;this call does not return so there is no reason to put an iretq at the end of this function
        call ih_double_fault

global isr_general_protection_fault
extern ih_general_protection_fault
isr_general_protection_fault:
        call save_int_regs
        call get_int_error_code
        mov rdi, rax ; move the return of the last call into the argument of the next
        call ih_general_protection_fault
        call restore_int_regs
        iretq

global isr_page_fault
extern ih_page_fault
isr_page_fault:
        call save_int_regs
        call get_int_error_code
        mov rdi, rax ; move the return of the last call into the argument of the next
        call ih_page_fault
        call restore_int_regs
        iretq

global interrupt
interrupt:
        int 0
        ret