bits 64

section .text
global disable_interrupts
disable_interrupts:
	cli
	ret
global enable_interrupts
enable_interrupts:
	sti
	ret
global hcf
hcf:
	cli ;clear interrupt enable flag
	hlt ;halt in a loop
	jmp hcf
