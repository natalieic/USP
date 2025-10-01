# motivo pra usar regs variados para os jals?
		
		.data
		.align 2
ponteiro: 	.word 0		# Ponteiro inicilizado com null
		.align 0
str_num: 	.asciz "Digite um número: "
str_op: 	.asciz "Digite uma operação (+,-,/,*,u,f): " 
str_result:	.asciz "Resultado:"
str_nl:		.asciz "\n"

		.text
		.align 2
		.globl main

main:		# Inicialização
		jal s11, recebe_num
		jal s10, empilha_num

main_loop:	# Laço de leitura e execução de operações
		jal s9, recebe_op
		jal s8, trata_op
		j main_loop
		
# Função para ler um número do usuário
# a0 = 
recebe_num:	
		li a7, 4
		la a0, str_num
		ecall 		# Imprime "Digite um número: "
		li a7, 5
		ecall 		# Lê um inteiro
		jr s11
		
		
empilha_num:	# Recebe o número em a0 e retorna ele em a1
		mv a1, a0	# a1 recebe o valor que será guardado
		li a7, 9
		li a0, 8 
		ecall 		# Aloca 8 bytes na heap para um novo nó 
		
		sw a1, 0(a0)	# Armazena o número no novo nó		
		la t1, ponteiro	# t1 <- endereço do ponteiro
		lw t2, 0(t1) 	# t2 <- valor do ponteiro (endereço do nó no topo)
		sw t2, 4(a0)	# Novo nó passa a apontar para o antigo topo
		sw a0, 0(t1)	# Ponteiro da stack recebe endereço do ultimo nó
		
		jr s10
		
		
		#retorna a op (char) em a0
recebe_op:
		li a7, 4
		la a0, str_op
		ecall #printa "Digite uma operação"
		
		li a7, 12
		ecall # lê a op
		
		mv t0, a0
		
		li a7, 4
		la a0, str_nl
		ecall
		
		mv a0, t0
		
		jr s9
		
		
		#recebe op em a0
trata_op:
		li t0, 'u'
		beq a0, t0, realiza_undo
		
		li t0, 'f'
		beq a0, t0, finaliza_programa
		
		#realiza operação matematica
		mv s0, a0 #guarda a op em s0
		jal s11, leitura_numero #retorna em a0 segundo operando
		
		la t1, node_pointer
		lw t2, 0(t1)
		lw s1, 0(t2) #primeiro operando 
		
		#"switch case" para operacoes
		li t0, '+'
		beq s0, t0, soma
		li t0, '-'
		beq s0, t0, subtrai
		li t0, '/'
		beq s0, t0, divide
		li t0, '*'
		beq s0, t0, multiplica
		
soma:
		add a0, s1, a0
		j finaliza_op_matematica
subtrai:
		sub a0, s1, a0
		j finaliza_op_matematica
divide:
		div a0, s1, a0
		j finaliza_op_matematica
multiplica:
		mul a0, s1, a0
		j finaliza_op_matematica
		
finaliza_op_matematica:
		jal s10, guarda_valor
		jal s7, exibe_no
		jr s8 #finaliza funcao
		
realiza_undo:
		la t0, node_pointer
		lw t1, 0(t0) #carrega endereco do ultimo nó 
		
		lw t2, 4(t1) #guarda em t2 penultimo nó
		sw t2, 0(t0) #guarda no ponteiro o penultimo nó
		#free ultimo nó???????
		
		jal s7, exibe_no
		jr s8 #finaliza funcao
		
finaliza_programa:
		li a7, 10
		ecall
		
		
exibe_no:
		la t0, node_pointer
		lw t1, 0(t0)
		
		la a0, str_result #imprime str_result
		li a7, 4
		ecall
		
		lw a0, 0(t1) #imprime o resultado
		li a7, 1
		ecall
		
		li a7, 4
		la a0, str_nl
		ecall
		
		jr s7 #finaliza funcao


