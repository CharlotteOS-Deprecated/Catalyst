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


global isr_double_fault
extern ih_double_fault
isr_double_fault:
        ;this call does not return so there is no reason to put an iretq at the end of this function
        call ih_double_fault