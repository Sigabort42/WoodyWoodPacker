section .text
        global _start

_start:
        mov al, 0x1
        mov dl,0x1
        lea rsi, [rel msg]
        mov rdx, msg_len
        syscall

	mov rax, 0x11111111
	jmp rax
align 8
        msg     db '...WOODY.',0x0a,0
	msg_len equ $ - msg
