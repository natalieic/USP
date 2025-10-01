		.data
		.align 0
msg_pos:	.asciz " é positivo"
msg_neg:	.asciz " é negativo"
		
		.text
		.align 2
		.globl main
main:		addi a7, zero, 5 	# carrega no a7 o serviço 5, e a chamada ao sistema
		ecall 			# recebe input de um inteiro do usuário e coloca no a0
		mv s0, a0		# equivalente a addi s0, a0, zero
		
		blt s0, zero, print_neg # desvia se for negativo
		la t0, msg_pos		# se é positivo carrega o endereço da mensagem em t0
		j end			# salto para o final
		
print_neg:	la t0, msg_neg		# se é negativo, carrega o endereço da mensagem
					# correspondente em t0
					
end:		add a0, zero, s0 	# carrega pro a0 o inteiro para ser impresso
		addi a7, zero, 1	# serviço 1 imprime um inteiro
		ecall
		add a0, t0, zero	# a0 <- t0 (endereço da string)
		addi a7, zero, 4	# serviço 4 imprime uma string
		ecall
		addi a7, zero, 10	# serviço 10 encerra o programa
		ecall