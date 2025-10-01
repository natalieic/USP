		.data
		.align 0
str1:		.asciz "Insira o tamanho do vetor: "
str2:		.asciz "Digite o vetor:"
		.align 2
ptr:		.word 0			# Inicializa o ponteiro do vetor
		.text
		.align 2
		.globl main
main:		# Imprime str1
		li a7, 4		# Serviço 4: imprimir string
		la a0, str1		# a0 <- endereço da str1
		ecall
		# Recebe tamanho do vetor
		li a7, 5		# Serviço 5: ler inteiro
		ecall			# a0 <- input
		mv s0, a0		# s0 <- a0 = tamanho do vetor
		# Aloca bloco de memória
		li a7, 9		# Serviço 9: Sbrk (alocação de memória na heap)
		li t0, 4
		mul a0, a0, t0		# a0 <- nº de bytes a serem alocados
		ecall
		mv s1, a0		# s1 <- endereço do 1º byte do bloco de momória alocado
		# Imprime str2 e uma quebra de linha
		li a7, 4		# Serviço 4: imprimir string
		la a0, str2		# a0 <- endereço da str2
		ecall
		li a7, 11		# Serviço 11: imprimir caractere
		li a0, 10		# ao <- valor ascii de '\n'
		ecall
		# Prepara para ler o vetor
		mv t1, s1		# t1 <- endereço do vetor
		addi t0, zero, 0	# t0 <- 0 (contador)
		li a7, 5		# Serviço 5: ler inteiro
loop_ler:	# Recebe e armazena os inteiros
		beq t0, s0, chama_func	# Se já leu todos os inteiros, desvia, senão, entra no laço
		ecall			# Lê um inteiro
		sw a0, 0(t1)		# Guarda na posição de memória em t1
		addi t1, t1, 4		# Incrementa a posição
		addi t0, t0, 1		# Incrementa o contador
		j loop_ler		# Repete
chama_func:	# Chamada à função bubble_sort
		mv a0, s1		# a0 <- endereço do vetor
		mv a1, s0		# a1 <- tamanho do vetor
		jal bubble_sort
		# Prepara para imprimir o vetor
		li a7, 11		# Serviço 11: imprimir caractere
		li a0, 10		# a0 <- valor ascii de '\n'
		ecall
		mv t1, s1		# t1 <- endereço do vetor
		mv t0, s0		# t0 (contador) <- tamanho do vetor
loop_imprimir:	# Imprime o vetor ordenado
		beq t0, zero, fim	# Se já imprimiu tudo, desvia para fim, senão, entra e imprime
		li a7, 1		# Serviço 1: imprimir inteiro
		lw a0, 0(t1)		# a0 <- conteúdo da posição de memória em t1
		ecall
		li a7, 11		# Serviço 11: imprimir caractere
		li a0, 32		# a0 <- valor ascii de [espaço]
		ecall
		addi t1, t1, 4		# Incrementa a posição de memória
		addi t0, t0, -1		# Decrementa o contador
		j loop_imprimir		# Repete
fim:		# Encerra o programa
		li a7, 10
		ecall
	
# Função que ordena um vetor de inteiros pelo algoritmo Bubble Sort
# a0 = endereço do vetor
# a1 = tamanho do vetor	
bubble_sort:	# Calcula o endereço do último byte do vetor
		li t3, 4
		mv t4, a1
		mul t3, t3, t4		# t3 <- tamanho do vetor em bytes
		add t3, t3, a0		# t3 <- endereço do final do vetor
		li t0, 1		# t0 (contador) <- 1
percorre:	# Controle da qunatidade de vezes que o vetor deve ser percorrido
		beq t0, a1, retorno	# Se já percorreu o vetor todas as vezes, retorna
		addi t0, t0, 1		# Incrementa o contador
		addi t3, t3, -4		#
		mv t1, a0		# t1 <- endereço do vetor
swap:		# Compara os elementos dois a dois e troca se necessário
		bge t1, t3, percorre	# Se o endereço analisado está além do vetor, desvia para o laço externo
		lw t4, 0(t1)		# Recupera um int
		lw t5, 4(t1)		# Recupera o int adjacente
		addi t1, t1, 4		# Incrementa o endereço
		blt t4, t5, swap	# Se t4 < t5, não troca e repete para o próximo endereço
		sw t4, 0(t1)		# Senão, troca as posiçoes dos inteiros no vetor
		sw t5, -4(t1)
		j swap			# Volta para o início do loop interno
retorno: jr ra
		
		
		