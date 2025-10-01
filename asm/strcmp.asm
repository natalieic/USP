		.data
		.align 0
buffer1:	.space 30
buffer2:	.space 30
maior:		.asciz " > "
menor:		.asciz " < "
igual:		.asciz " = "
		.text
		.align 2
		.globl main
main:		
		li a7, 8
		la a0, buffer1
		li a1, 30
		ecall
		la a0, buffer2
		ecall
		li a1, 10
		la a0, buffer1
		jal trimLF
		la a0, buffer2
		jal trimLF
		la t1, buffer1
		la t2, buffer2
		li t3, 1		
		
cmp_loop:	beq t3, zero, print_eq
		lb t3, 0(t1)
		lb t4, 0(t2)
		addi t1, t1, 1
		addi t2, t2, 1
		beq t3, t4, cmp_loop
		blt t3, t4, print_menor
		j print_maior
		
print_eq:	li a7, 4
		la a0, buffer1
		ecall
		la a0, igual
		ecall
		j final
		
print_maior:	li a7, 4
		la a0, buffer1
		ecall
		la a0, maior
		ecall
		j final
		
print_menor:	li a7, 4
		la a0, buffer1
		ecall
		la a0, menor
		ecall
		
final:		la a0, buffer2
		ecall
		li a7, 10
		ecall
		
trimLF:		lb t0, 0(a0)
		addi a0, a0, 1
		bne t0, a1, trimLF
		sb zero, -1(a0)
		
return:		jr ra
		
		
		
		