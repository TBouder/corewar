# clear && make -C ../asm/ && rm test.cor && ../asm/asm test.s && make && ./corewar test.cor
.name    "Survivor"
.comment "Invincible"

# ;TEST DE ZAZ
# #############################
# ld 10, r5
# ld %100, r2
# add r2, r3, r4
# aff r1
# aff r2
# aff r3
# aff r4
# aff r5


# # ;TEST DE ZJUMP
# ld %64, r2
# st r2, 20
# aff r2
# zjmp %-16
# # ici:
# ld %68, r2
# aff r2
# aff r3
# # aff r4


;TEST DE AND OR XOR IND
ld %65, r2 #; Met A dans r2
st r2, 44 #; Stocke du reg vers le second param
and r2, 39, r3 #; mettre la différence entre les adresses a partir 
#;de la valeur indirecte jusqu'a celle d'apres
or 34, r1, r4
xor 28, r1, r5
aff r3
aff r4
aff r5
aff r6
aff r6
aff r6
aff r6
aff r6
aff r6
aff r6
aff r6

# ;TEST DE AND OR XOR DIR
# #############################
# or	%68, r1, r2
# and %69, r2, r3
# xor	%69, r1, r4
# aff r2
# aff r3
# aff r4

################################################################################
# 	; ; TEST DE LD DIRECT ET INDIRECT
# 	; ################################
# 	; ld %68, r2			#Met %68 dans r2 -> 'D'
# 	; ld 11, r7			#Met 11 dans r7 -> 0
# 	; aff r2				#Affiche r2 -> 'D'
# 	; aff r7				#Affiche r7 -> ''
# 	; add r2, r7, r3		#r3 = r2 + r7 -> 0x4 + 0x44 -> 'H'
# 	; aff r3				#Affiche r3 -> 'H'

# 	; ; TEST DE LLD DIRECT ET INDIRECT
# 	; ################################
# 	; lld %68, r2			#Met %68 dans r2 -> D
# 	; lld 11, r7			#Met 11 dans r7 -> 0
# 	; aff r2				#Affiche r2 -> 'd'
# 	; aff r7				#Affiche r7 -> ''
# 	; sub r2, r7, r3		#r2 = r7 - r3 -> 0x5 + 0x44 -> '?'
# 	; aff r3				#Affiche r3 -> '?'

# ################################################################################
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

# ################################################################################
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
# ################################################################################

# 	; ; TEST DE LDI REG-REG
# 	; ################################
# 	ld %68, r2			#Met %68 dans r2
# 	add r2, r1, r1		#r1 (le dernier) = r2 + r1
# 	aff r1				#Affiche r1
# 	aff r2				#Affiche r2
# 	ldi %-10, %0, r7		#Stock r2 a l'adresse de PC + ((%29 + %68) % IDX_MOD)
# 	aff r7				#Affiche r7 -> ''
# 	; ldi %1, %0, r7		#Stocker dans r7 ce qu'il y a a l'adresse de %1 + %1

# 	################################################################################
# 	################################################################################
# 	################################################################################
# 	################################################################################
# 	################################################################################

