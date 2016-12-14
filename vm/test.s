# clear && make -C ../asm/ && rm test.cor && ../asm/asm test.s && make && ./corewar test.cor
.name    "Survivor"
.comment "Invincible"

# ; live %1
# ; live %3
# ; live %3
# ; live %3
# #LD#############################################################################
# 	; ; TEST DE LD DIRECT ET INDIRECT
# 	; ################################
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	aff r1				#Affiche r2 -> 'D'
# 	label:
# 	ld %68, r2			#Met %68 dans r2 -> 'D'
# 	ld 11, r7			#Met 11 dans r7 -> 0
# 	aff r2				#Affiche r2 -> 'D'
# 	aff r7				#Affiche r7 -> ''
# 	add r2, r7, r3		#r3 = r2 + r7 -> 0x4 + 0x44 -> 'H'
# 	aff r3				#Affiche r3 -> 'H'
# 	live %1
# 	; 1 CHAMP
# 	st r2, r3			#Stock r2 dans r3
# 	st r2, 42			#Stock r2 dans l'adresse PC + (42 % IDX_MOD)

# 	fork %3
# 	; 2 CHAMP
# 	fork %10
# 	; 3 CHAMP
# 	fork %-5
# 	st r2, 79			#Stock r2 dans r3
# 	; 4 CHAMP
# 	; fork %5
# 	; 5 CHAMP
# 	; live %5


# # 30 + 3 = 43

# # 36 + 3 = 39
# # 36 +

# # 39 +
# # 39 +
# # 39 +
# # 39 +


# 	; ; TEST DE LLD DIRECT ET INDIRECT
# 	; ################################
# 	; lld %68, r2			#Met %68 dans r2 -> D
# 	; lld 11, r7			#Met 11 dans r7 -> 0
# 	; aff r2				#Affiche r2 -> 'd'
# 	; aff r7				#Affiche r7 -> ''
# 	; add r2, r7, r3		#r3 = r2 + r7 -> 0x4 + 0x44 -> 'H'
# 	; aff r3				#Affiche r3 -> '?'
# 	; sub r2, r3, r7		#r2 = r7 - r3 -> 0x5 + 0x44 -> '?'

# #ST#############################################################################
# 	; ; TEST DE ST REG
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2 -> 'D'
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; st r2, r3			#Stock r2 dans r3
# 	; aff r3				#Affiche r3 -> 'D'
# 	; ; TEST DE ST IND
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2 -> 'D'
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; st r2, 42			#Stock r2 dans l'adresse PC + (42 % IDX_MOD)
# 	; ld 37, r3			#Met ce qu'il y a dans 37 dans r3 -> 'D'
# 	; aff r3				#Affiche r3 -> 'D'

# #STI############################################################################
# 	; ; TEST DE STI DIRECT-DIRECT
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1
# 	; aff r2				#Affiche r2
# 	; sti r2, %29, %40	#Stock r2 a l'adresse de PC + ((%29 + %40) % IDX_MOD)
# 	; ld 62, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 62
# 	; aff r7				#Affiche r7 -> 'D'
# 	; ; TEST DE STI DIRECT-REG
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1
# 	; aff r2				#Affiche r2
# 	; sti r2, %29, r2		#Stock r2 a l'adresse de PC + ((%29 + r2[VAL]) % IDX_MOD)
# 	; ld 91, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 91
# 	; aff r7				#Affiche r7 -> 'D'
# 	; ; TEST DE STI REG-REG
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1
# 	; aff r2				#Affiche r2
# 	; sti r2, r2, r2		#Stock r2 a l'adresse de PC + ((r2[VAL] + r2[VAL]) % IDX_MOD)
# 	; ld 131, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 131
# 	; aff r7				#Affiche r7 -> 'D'
# 	; ; TEST DE STI IND-REG
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1
# 	; aff r2				#Affiche r2
# 	; sti r2, 11, r2		#Stock r2 a l'adresse de PC + ((r2[VAL] + (PC + 11)) % IDX_MOD)
# 	; ld 91, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 91
# 	; aff r7				#Affiche r7 -> 'D'
# 	; ; TEST DE STI IND-REG
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1
# 	; aff r2				#Affiche r2
# 	; sti r2, 11, %29		#Stock r2 a l'adresse de PC + (((PC + 11) + %29) % IDX_MOD)
# 	; ld 51, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 51
# 	; aff r7				#Affiche r7 -> 'D'

# #LDI############################################################################
# 	; ; TEST DE LDI REG-REG
# 	; ld %-11, r2			#Met %-11 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> ''
# 	; aff r2				#Affiche r2 -> ''
# 	; ldi r2, r1, r7		# additionne r2 et r1, et va mettre la valeur a l'adresse de [r2 + r1] dans r7
# 	; aff r7				#Affiche r7 -> 'T'
# 	; ; TEST DE LDI REG-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; ldi r1, %0, r7	# additionne %0 et r1, et va mettre la valeur a l'adresse de [%0 + r1] dans r7
# 	; aff r7				#Affiche r7 -> 'd'
# 	; ; TEST DE LDI DIR-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; ldi %1, %0, r7	# additionne %1 et %0, et va mettre la valeur a l'adresse de [%1 + %0] dans r7
# 	; aff r7				#Affiche r7 -> '¤'
# 	; ; TEST DE LDI DIR-REG
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; ldi %0, r8, r7	# additionne %0 et r8, et va mettre la valeur a l'adresse de [%0 + r8] dans r7
# 	; aff r7				#Affiche r7 -> '\n'
# 	; ; TEST DE LDI IND-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; ldi 2, %1, r7		#On va chercher ce qu'il y a a l'adresse de (PC + 2 -> 18 + 2), on prend la valeur, on additionne avec la valeur dans R1 [map[pc + 2] + r1] et on met dans r7
# 	; aff r7				#Affiche r7 -> 'ä'
# 	; ; TEST DE LDI IND-REG
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; ldi 2, r1, r7		#On va chercher ce qu'il y a a l'adresse de (PC + 2 -> 18 + 2), on prend la valeur, on additionne avec la valeur dans R1 [map[pc + 2] + r1] et on met dans r7
# 	; aff r7				#Affiche r7 -> 'Ô'

# #LLDI###########################################################################
# 	; ; TEST DE LDI REG-REG
# 	; ld %-11, r2			#Met %-11 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> ''
# 	; aff r2				#Affiche r2 -> ''
# 	; lldi r2, r1, r7		# additionne r2 et r1, et va mettre la valeur a l'adresse de [r2 + r1] dans r7
# 	; aff r7				#Affiche r7 -> 'T'
# 	; ; TEST DE LDI REG-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; lldi r1, %-11, r7	# additionne %-11 et r1, et va mettre la valeur a l'adresse de [%-10 + r1] dans r7
# 	; aff r7				#Affiche r7 -> 'T'
# 	; ; TEST DE LDI DIR-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	; aff r1				#Affiche r1 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; lldi %-10, %0, r7	# additionne %-10 et %0, et va mettre la valeur a l'adresse de [%-10 + %0] dans r7
# 	; aff r7				#Affiche r7 -> 'T'
# 	; ; TEST DE LDI DIR-REG
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; lldi %-11, r1, r7	# additionne %-11 et r1, et va mettre la valeur a l'adresse de [%-10 + r1] dans r7
# 	; aff r7				#Affiche r7 -> 'T'
# 	; ; TEST DE LDI IND-DIR
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; lldi -7, %0, r7		#On va chercher ce qu'il y a a l'adresse de (PC - 7 -> 18 + 03), on prend la valeur, on additionne avec la valeur %0 [map[pc + 03] + 0] et on met dans r7
# 	; aff r7				#Affiche r7 -> 'ù'
# 	; ; TEST DE LDI IND-REG
# 	; ld %68, r2			#Met %68 dans r2
# 	; add r2, r1, r3		#r3 = r2 + r1
# 	; aff r3				#Affiche r3 -> 'E'
# 	; aff r2				#Affiche r2 -> 'D'
# 	; lldi -8, r1, r7		#On va chercher ce qu'il y a a l'adresse de (PC - 8 -> 18 + 01), on prend la valeur, on additionne avec la valeur dans R1 [map[pc + 01] + R1] et on met dans r7
# 	; aff r7				#Affiche r7 -> 'ÿ'

	################################################################################
	################################################################################
	################################################################################
	################################################################################
	################################################################################

	# ld %64, r2
	# and %5, %6, r3
	# add r3, r2, r4
	# aff r4

	#; TEST DE FORK
		ld %36, r2			# Met la valeur $ dans r2
		ld %1, r3			# Met 1 dans r3 (Pour permettre l'incrémentation)
		
		onboucle:
		aff r2				# Va afficher les diff char ascii
		add r2, r3, r2		# Incrémente r2, pour changer le char
		zjmp %:onboucle
		fork %:laba			# Créé un nouveau champion tous les 256
		add r2, r3, r2		# Sinon le carry se met a 0
		zjmp %:onboucle		# On revient au début du programme
		
		laba:
			ld %42, r2		# Normalement r2, spécifique au nouveau champ
		st r1, 10			# Save le numéro du champion
		aff r2
	#; FIN TEST

	# ; TEST DE ZJMP AVEC LABEL
	# 	ld %65, r2
	# 	laba:
	# 		st r2, 45
	# 	zjmp %3
	# 		aff r2
	# 	zjmp %:laba

	# ; TEST DE ZJMP AVEC LABEL
	# 	ld %65, r2
	# 	ld %1, r3
	# 	laba:
	# 		st r2, 45
	# 	zjmp %:test
	# 	test:
	# 		aff r2
	# 	add r2, r3, r2
	# 	zjmp %:laba
	# 	add r2, r3, r2
	# 	zjmp %:laba
		

	# ; TEST DE AND OR XOR IND
	# 	ld %65, r2 #; Met A dans r2
	# 	st r2, 45 #; Stocke du reg vers le second param
	# 	and 40, r2, r3
	# 	ld %66, r2
	# 	or 27, r2, r4
	# 	xor 21, %12, r5
	# 	aff r3	#; A
	# 	aff r4	#; C
	# 	aff r5	#; M

	# ;TEST DE AND OR XOR DIR
	# #############################
	# ld %1, r2
	# or	%68, r2, r3
	# and %69, r3, r4
	# xor	%69, r2, r5
	# aff r3
	# aff r4
	# aff r5

	# ;TEST DE LD DIRECT ET INDIRECT
	# ##############################
	# ld %35, r2			#Met %68 dans r2 -> 'D'
	# ld 9, r3			#Met 11 dans r7 -> 0
	# aff r2				#Affiche r2 -> 'D'
	# aff r3				#Affiche r7 -> ''
	# add r2, r3, r4		#r3 = r2 + r7 -> 0x7 + 0x44 -> 'K'
	# aff r4				#Affiche r3 -> 'K'

	# ;TEST DE LLD DIRECT ET INDIRECT
	# ##############################
	# lld %68, r2			#Met %68 dans r2 -> D
	# lld 11, r3			#Met 11 dans r7
	# aff r2				#Affiche r2
	# aff r3				#Affiche r7
	# sub r2, r3, r4		#r2 = r7 - r3
	# aff r4				#Affiche r3



	# ;TEST DE ST REG
	###############################
	# ld %68, r2			#Met %68 dans r2 -> 'D'
	# add r2, r1, r1		#r1 (le dernier) = r2 + r1
	# aff r1				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
	# aff r2				#Affiche r2 -> 'D'
	# st r2, r3			#Stock r2 dans r3
	# aff r3				#Affiche r3 -> 'D'

	# ;TEST DE ST IND
	# ##############################
	# ld %68, r2
	# ld %1, r3			#Met %68 dans r2 -> 'D'
	# add r2, r3, r4		#r1 (le dernier) = r2 + r1
	# aff r2				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
	# aff r4				#Affiche r2 -> 'D'
	# st r2, 42			#Stock r2 dans l'adresse PC + (42 % IDX_MOD)
	# ld 37, r5			#Met ce qu'il y a dans 37 dans r3 -> 'D'
	# aff r5				#Affiche r3


	# ;TEST DE STI DIRECT
	###############################
	# ld %68, r2			#Met %68 dans r2
	# add r2, r1, r1		#r1 (le dernier) = r2 + r1
	# aff r1				#Affiche r1
	# aff r2				#Affiche r2
	# sti r2, %29, %40	#Stock r2 a l'adresse de PC + ((%29 + %40) % IDX_MOD)
	# ld 66, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 66
	# aff r7				#Affiche r7
