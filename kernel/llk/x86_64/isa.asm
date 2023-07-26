bits 64

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
global reg_test
reg_test:
	mov rax, 1
	mov rbx, 2
	mov rcx, 4
	mov rdx, 8
	ret