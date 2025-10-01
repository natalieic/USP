		.data
		.align 2
ptr:		.word 0
		.align 0
buffer:		.space 50
		.text
		.align 2
		.globl main
main:		# Recebe a string do usuário
		li a7, 8		# Serviço 8: ler string
		la, a0, buffer		# a0 <- endereço do destino
		li a1, 49		# a1 <- máximo de bytes a serem lidos
		ecall
		# Conta o tamanho da string
		li t3, 10
		la t1, buffer
		li t0, 0
loop_conta:	lb t2, 0(t1)
		addi t1, t1, 1
		addi t0, t0, 1
		bne t2, t3, loop_conta
		
		sb zero, -1(t1)
		mv t0, s0		# s0 <- tamanho da string
		# Aloca a segunda string
		li a7, 9
		mv a0, s0
		ecall
		mv s1, a0		# s1 <- endereço da revstr
		la t2, ptr
		sw s1, 0(t2)
		add t2, s1, s0
		addi t2, t2, -1		# t2 <- endereço do último byte da rev
		sb zero, 0(t2)
		addi t2, t2, -1
		la t1, buffer

inverte:	lb t0, 0(t1)
		beqz t0, imprime
		sb t0, 0(t2)
		addi t1, t1, 1
		addi t2, t2, -1
		j inverte
		
imprime:	li a7, 4
		addi a0, t2, 1
		ecall
		
		li a7 10
		ecall
		
		
		
		
		
		
		
		