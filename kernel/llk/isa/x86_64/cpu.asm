bits 64

section .rodata
df_message: db "A double fault has ocurred!",0x0D,0x0A,0x0
halt_msg: db "Halting!",0x0D,0x0A,0x0
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
	lea rdi, [rel halt_msg]
	call log_puts
	cli ;clear interrupt enable flag
	hlt ;halt in a loop
	jmp hcf
global inb
inb:
	mov dx, di
	in al, dx
	ret

global outb
outb:
	mov dx, di
	mov al, sil
	out dx, al
	ret

; ISRs for CPU based interrupts
global isr_double_fault
extern log_puts
extern hcf
isr_double_fault:
	lea rdi, [rel df_message]
	call log_puts
	; a double fault should not return
	call hcf
global interrupt_test
interrupt_test:
	int 0x8
	ret