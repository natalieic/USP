		.data
		.align 0
original:	.asciz "Menina risonha que ri e que sonha"
cópia:		.space 34		# Reserva um espaço de 34 bytes na memória, o suficiente
					# para a string sem espaço de precaução
		.text
		.align 2
		.globl main
main:
		la s0, original		# s0 <- endereço do 1º byte da str original
		la s1, cópia		# s1 <- endereço do 1º byte do espaço para a cópia
		
loop: 		lb t0, 0(s0)		# t0 <- um caractere da str original
		sb  t0, 0(s1)		# Carrega o conteúdo do byte no endereço de s0 para o endereço em s1 deslocado de 0 bytes
		addi s0, s0, 1
		addi s1, s1, 1
		bne t0, zero, loop	# Repete enquanto não encontrar o caractere nulo (t0 == \0)

		la a0, cópia		# Carrega no a0 o endereço da cópia
		addi a7, zero, 4	# Serviço 4 imprime string
		ecall
		addi a7, zero, 10	# Serviço 10 encerra o programa
		ecall
		
# criar um programa que lê uma string do usuário e copia para a memória