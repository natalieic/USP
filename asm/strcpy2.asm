		.data
		.align 0
input:		.space 200		# Reserva um espaço de 300 bytes na memória para a string de entrada e sua cópia

		.text
		.align 2
		.globl main
main:
		la s0, input		# s0 <- endereço do 1º byte da str original
		addi s2, zero, 10	# s2 <- valor ascii para quebra de linha
		addi a7, zero, 12	# Serviço 12 recebe um caractere no a0
read_loop:
		ecall			# Lê o input
		mv t0, a0		# Move o caractere para t0
		sb t0, 0(s0)		# Escreve na memória
		addi s0, s0, 1		# Incrementa a posição
		bne t0, s2, read_loop	# Repete enquanto não recebe '\n'
		
		mv s1, s0		# s1 <- próximo byte disponível para a cópia
		sb zero, -1(s0)		# '\n' é substituído por '\0'
		la s0, input		# s0 <- endereço do primeiro byte da str input
		
copy_loop: 	lb t0, 0(s0)		# t0 <- um caractere da str original
		sb  t0, 0(s1)		# Carrega o conteúdo do byte no endereço de s0 para o endereço em s1 deslocado de 0 bytes
		addi s0, s0, 1
		addi s1, s1, 1
		bne t0, zero, copy_loop	# Repete enquanto não encontrar o caractere nulo (t0 == \0)

		mv a0, s0
		addi a7, zero, 4	# Serviço 4 imprime string
		ecall
		addi a7, zero, 10	# Serviço 10 encerra o programa
		ecall