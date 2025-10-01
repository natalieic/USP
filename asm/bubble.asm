            .data
            .align 2
ptr:        .word 0         # Ponteiro para o início do vetor
            .align 0
str1:       .asciz "Insira o tamanho do vetor: "
str2:       .asciz "Digite o vetor: "
            .text
            .align 2
            .globl main
main:       # Imprime strings de entrada e recebe o input
            li a7, 4        	# Serviço 4: imprimir string
            la a0, str1     	# a0 <- endereço da string a ser impressa
            ecall
            li a7, 5        	# Serviço 5: ler inteiro
            ecall           	# a0 <- inteiro lido
            mv s0, a0       	# s0 <- tamanho do vetor
            # Aloca memória para o vetor
            li t1, 4
            mul a0, a0, t1	# a0 <- qtd bytes a serem alocados
            li a7, 9        	# Serviço 9: reservar espaço na memória dinâmica
            ecall
            mv t1, a0       	# t1 <- endereço do primeiro byte do bloco de memória reservado
            la t2, ptr
            sw t1, 0(t2)    	# Conteúdo de t1 (endereço do vetor) é armazenado no endereço de ptr
            mv t0, s0       	# Copia o tamanho do vetor pra t0
            li a7, 4        	# Serviço 4: imprimir string
            la a0, str2     	# a0 <- endereço da string a ser impressa
            ecall
            li a7, 11
            li a0, 10
            ecall
read_loop:  # Laço que lê e armazena os inteiros do vetor 
            beq t0, zero, sort
            li a7, 5
            ecall
            sw a0, 0(t1)
            addi t1, t1, 4
            addi t0, t0, -1
            j read_loop

sort:       # Ordena os inteiros
            addi s1, s0, -1 # s1 <- tamanho do vetor menos um
            mv t0, zero     # t0 <- zero
            la t2, ptr
            lw t1, 0(t2)    # t1 <- endereço do vetor
            li t3, 4
            mul t3, t3, s1  # t3 <- qtd bytes do vetor
            add t5, t3, t1  # t5 <- final do vetor 
outer_loop: bge t0, s1, final
            addi t0, t0, 1
            lw t1, 0(t2)
inner_loop: bge t1, t5, outer_loop
            lw t3, 0(t1)
            lw t4, 4(t1)
            addi t1, t1, 4
            blt t3, t4 inner_loop
            sw t4, -4(t1)
            sw t3 0(t1)
            j inner_loop

final:      la t2, ptr
            lw s1, 0(t2)
imprime:    beq s0, zero, encerra
            li a7, 1
            lw a0, 0(s1)
            ecall
            li a7, 11
            li a0, 32
            ecall
            addi s1, s1, 4
            addi s0, s0, -1
            j imprime

encerra:    li a7, 10
            ecall


