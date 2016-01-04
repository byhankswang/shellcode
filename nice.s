.section .text
.globl _start
_start:
	xorl %eax, %eax
	xorl %ebx, %ebx
	movb $0x22, %eax
	movb $0x13, %ebx
	int $0x80
