	.data
		.align 2
node_pointer: 	.word 0 # ponteiro inicilizado com null
		.align 0
str_op_leitura:	.space 4
str_num: 	.asciz "Digite um número: "
str_op: 	.asciz "Digite uma operação (+,-,/,*,u,f): " 
str_op_invalida:.asciz "Operação invalida\n"
str_result:	.asciz "Resultado:"
str_nl:		.asciz "\n"

	.text
	.align 2
	.globl main
	
main:
	# incicialização
	jal leitura_numero
	jal guarda_valor

operacoes:
	jal leitura_op

	li t0, 'u'
	beq a0, t0, realiza_undo
	
	li t0, 'f'
	beq a0, t0, finaliza_programa
	
	# prepara para realizar operação matematica
	mv s0, a0 # guarda a op em s0
	
	# "switch case" para operacoes
	li t0, '+'
	beq s0, t0, soma
	li t0, '-'
	beq s0, t0, subtrai
	li t0, '/'
	beq s0, t0, divide
	li t0, '*'
	beq s0, t0, multiplica
	j op_invalida #caso base
	
soma:
	jal prepara_op
	add a0, a1, a0
	j finaliza_op_matematica
subtrai:
	jal prepara_op
	sub a0, a1, a0
	j finaliza_op_matematica
divide:
	jal prepara_op
	div a0, a1, a0
	j finaliza_op_matematica
multiplica:
	jal prepara_op
	mul a0, a1, a0
	j finaliza_op_matematica
	
finaliza_op_matematica:
	jal  guarda_valor
	jal  exibe_no
	j operacoes #retorna ao inicio do loop
	
op_invalida:
	la a0, str_op_invalida
	li a7, 4
	ecall #imprime "op invalida"
	j operacoes 

realiza_undo:
	la t0, node_pointer
	lw t1, 0(t0) # carrega endereco do ultimo nó da lista
	lw t2, 4(t1) # guarda em t2 o penultimo nó 
	
	bne t2, zero, final_undo #caso so tenha uma celula, ela é preservada
	sw zero, 0(t1) #zera o valor(resultado) da ultima celula
	jal  exibe_no
	j operacoes #retorna ao inicio do loop
final_undo:
	sw t2, 0(t0) # guarda no ponteiro base o penultimo nó
	jal  exibe_no
	j operacoes #retorna ao inicio do loop
	 
finaliza_programa:
	li a7, 10
	ecall
	j operacoes # mantém loop de leitura e tratamento das operacoes


# retorna o número lido em a0
leitura_numero:
	li a7, 4
	la a0, str_num
	ecall # printa "Digite um número"
	
	li a7, 5
	ecall # lê o numero
	
	jr ra

# recebe o número em a0
# retorna número em a1
guarda_valor:
	mv a1, a0 # a1 recebe o valor que será guardado
	li a0, 8 
	li a7, 9
	ecall # aloca 8 bytes para um novo nó 
	sw a1, 0(a0) # número é armazenado no novo nó 
	la t1, node_pointer # t1 recebe endereco do ponteiro
	lw t2, 0(t1) # t1 recebe valor do ponteiro (ultimo nó)
	sw t2, 4(a0) # ponteiro do novo nó recebe posicao do penultimo nó
	sw a0, 0(t1) # ponteiro da stack recebe endereço do ultimo nó
	jr ra

# retorna a op (char) em a0
leitura_op:
	li a7, 4
	la a0, str_op
	ecall # printa "Digite uma operação"
	
	li a7, 8
	la a0, str_op_leitura
	li a1, 3 #le no max 3 caracteres
	ecall # lê a op
	
	lb t0, 1(a0) #prox byte da op
	lb t2, 0(a0) #byte da op
	li t1, '\n'
	bne t0, t1, printa_nl #garante correta formatacao da impressao
	
	mv a0, t2
	jr ra
	
printa_nl:
	li a7, 4
	la a0, str_nl
	ecall
	
	mv a0, t2
	jr ra


#funcao sem entradas ou saidas nos registradores
exibe_no:
	la a0, str_result # imprime str_result
	li a7, 4
	ecall
	
	la t0, node_pointer
	lw t1, 0(t0)
	lw a0, 0(t1) #acessa valor do ultimo no da lista
	li a7, 1
	ecall #imprime o resultado
	
	li a7, 4
	la a0, str_nl
	ecall #printa nl
	
	jr ra # finaliza a função


#retorna segundo operando em a0 (numero lido)
#retorna primeiro operando em a1 (resultado anterior)
prepara_op:
	addi sp, sp, -4 #aloca espaço na pilha para ra
    	sw ra, 0(sp) #guarda ra
	
	jal leitura_numero # retorna em a0 o segundo operando
	la t1, node_pointer
	lw t2, 0(t1)
	lw a1, 0(t2) # primeiro operando 
	
	lw ra, 0(sp) 
	addi sp, sp, 4 #desaloca espaco para ra 
	jr ra