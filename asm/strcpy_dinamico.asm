		.data
		.align 0
str_space:	.space 80		# Reserva 80 bytes para o input do usuário
		.align 2
p:		.word 0			# Inicializa o ponteiro p com zero

		.text
		.align 2
		.globl main
main:		# Recebe a string do usuário
		la s0, str_space	# s0 <- endereço do 1º byte do espaço reservado para a string
		li s2, 10		# s2 <- valor ascii para a quebra de linha
		li t1, 0		# Inicialização do contador t1
		li a7, 12		# Serviço 12 para ler caracteres
read_loop:
		ecall			# Caracter é recebido no a0
		sb a0, 0(s0)		# Armazena o caracter
		addi s0 , s0, 1		# Incrementa para endereçar o próximo byte
		addi t1, t1, 1		# Incrementa o contador
		bne a0, s2, read_loop	# Repete enquanto a0 não receber a quebra de linha
		
		sb zero, -1(s0)		# Substitui o \n por \0
		# Reserva espaço na heap para a cópia
		la t2, p		# t2 <- endereço de p
		li a7, 9		# Serviço 9 chama a função srbk que aloca um bloco de memória na heap
		mv a0, t1		# a0 <- nº de bytes a serem reservados
		ecall		
		sw a0, 0(t2)		# p <- endereço do 1º byte da região alocada
		# Preparação para copiar a string
		la s0, str_space	# s0 <- endereço da str original
		la t2, p		# t2 <- endereço de p
		lw s1, 0(t2)		# s1 <- p = endereço do espaço da cópia	
copy_loop:
		lb t0, 0(s0)		# t0 <- caracter da str original
		sb t0, 0(s1)		# Caracter em t0 é armazenado na posição em s1
		addi s0, s0, 1		# Incrementa para endereçar os próximos bytes
		addi s1, s1, 1
		bne t0, zero, copy_loop	# Copia enquanto t0 não for o caracter nulo
		
		# Imprime a cópia
		lw a0 0(t2)		# a0 <- endereço da cópia
		li a7, 4		# Serviço 4 para imprimir string
		ecall
		# Encerra o programa
		li a7, 10
		ecall
		
