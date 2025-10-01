		.data
		.align 0
str1:		.asciz "Insira um inteiro positivo: "	# String para solicitar o input
str2:		.asciz "! = "	# String para imprimir o resultado
		.text
		.align 2
		.globl main
		
main:		# Instrui o usuário e recebe o input
		la a0, str1		# a0 <- endereço da str1
		li a7, 4		# Serviço 4: imprimir string
		ecall			
		li a7, 5		# Serviço 5: ler inteiro
		ecall			# a0 <- input
		mv s0, a0		# s0 <- input salvo
		# Prepara o resultado e chama a função fatorial
		li a1, 1		# a1 é inicializado para o valor de 0! = 1! = 1
		# jal <reg>, label com reg omitido usa ra
		jal ra, fatorial	# Chamada da função fatorial, t0 <- endereço da instrução seguinte ao salto
		# Exibe o resultado
		li a7, 1		# Serviço 1: imprimir inteiro
		mv a0, s0		# a0 <- valor do input
		ecall			# Sistema imprime o inteiro inicial
		li a7, 4		# Serviço 4: imprimir string
		la a0, str2		# a0 <- endereço da str2
		ecall
		mv a0, a1		# a0 <- resultado
		li a7, 1		# Serviço 1: imprimir inteiro
		ecall
		# Encerra o programa
		li a7, 10
		ecall
		
		
# Função que calcula o fatorial de um número
# a0 = número cujo fatorial será calculado
# a1 = resultado (inicializado com 1)		
fatorial:	beq a0, zero, return	# Executa o código seguinte enquanto a0 for diferente de zero
		mul a1, a1, a0		# Resultado <- Resultado x a0
		addi a0, a0, -1		# Decrementa a0
		j fatorial		# Volta para o começo
		
return:		jr ra
		