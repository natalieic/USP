		.data
		.align 0
message:	.asciz "Hello World!"

		.text
		.align 2
		.globl main
main:
		la a0, message
		addi a7, zero, 4
		ecall
		
		addi a7, zero, 10
		ecall