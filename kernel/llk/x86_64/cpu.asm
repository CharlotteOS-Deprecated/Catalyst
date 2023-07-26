bits 64

section .text
global hcf
hcf:
	cli ;clear interrupts
inf_loop:
	hlt ;halt in a loop
	jmp inf_loop
