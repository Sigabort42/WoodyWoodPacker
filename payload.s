section .text
	global _start
_ender:
	call _starter
	msg db '...WOODY...',0xA,0
	
_start:
	jmp _ender

_starter:
	pop rsi
	mov al, 0x1
	mov dl, 0x1
	mov rdx, 0xd
	syscall
	mov rdx, 0x0
	
