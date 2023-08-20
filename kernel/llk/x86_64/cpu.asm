bits 64

section .text
global hcf
hcf:
	cli ;clear interrupts
	hlt ;halt in a loop
	jmp hcf
