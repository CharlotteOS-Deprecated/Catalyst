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

section .text

extern get_int_error_code

global isr_divide_by_zero
extern ih_divide_by_zero
isr_divide_by_zero:
        call ih_divide_by_zero
        iretq

global isr_overflow
extern ih_overflow
isr_overflow:
        call ih_overflow
        iretq

global isr_invalid_opcode
extern ih_invalid_opcode
isr_invalid_opcode:
        call ih_invalid_opcode
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
        call get_int_error_code
        mov rdi, rax ; move the return of the last call into the argument of the next
        call ih_general_protection_fault
        iretq

global isr_page_fault
extern ih_page_fault
isr_page_fault:
        call get_int_error_code
        mov rdi, rax ; move the return of the last call into the argument of the next
        call ih_page_fault
        iretq

global interrupt
interrupt:
        int 0x4
        ret