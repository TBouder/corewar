# clear && make -C ../asm/ && rm test.cor && ../asm/asm test.s && make && ./corewar test.cor
.name    "Survivor"
.comment "Invincible"

;TEST DE ZAZ
#############################
ld %100, r2
add r2, r3, r4
aff r1
aff r2
aff r3
aff r4


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


# ;TEST DE AND OR XOR IND
# ld %65, r2 #; Met A dans r2
# st r2, 45 #; Stocke du reg vers le second param
# and r2, 40, r3 #; mettre la différence entre les adresses a partir de la valeur indirecte jusqu'a celle d'apres
# or 35, r1, r4
# xor 29, r1, r5
# aff r3
# aff r4
# aff r5

# ;TEST DE AND OR XOR DIR
# #############################
# or	%68, r1, r2
# and %69, r2, r3
# xor	%69, r1, r4
# aff r2
# aff r3
# aff r4

# ;TEST DE LD DIRECT ET INDIRECT
###############################
# ld %68, r2			#Met %68 dans r2 -> 'D'
# ld 11, r7			#Met 11 dans r7 -> 0
# aff r2				#Affiche r2 -> 'D'
# aff r7				#Affiche r7 -> ''
# add r2, r7, r3		#r3 = r2 + r7 -> 0x7 + 0x44 -> 'K'
# aff r3				#Affiche r3 -> 'K'

# ;TEST DE LLD DIRECT ET INDIRECT
###############################
# lld %68, r2			#Met %68 dans r2 -> D
# lld44 11, r7			#Met 11 dans r7
# aff r2				#Affiche r2
# aff r7				#Affiche r7
# sub r2, r7, r3		#r2 = r7 - r3
# aff r3				#Affiche r3



# ;TEST DE ST REG
###############################
# ld %68, r2			#Met %68 dans r2 -> 'D'
# add r2, r1, r1		#r1 (le dernier) = r2 + r1
# aff r1				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
# aff r2				#Affiche r2 -> 'D'
# st r2, r3			#Stock r2 dans r3
# aff r3				#Affiche r3 -> 'D'

# ;TEST DE ST IND
###############################
# ld %68, r2			#Met %68 dans r2 -> 'D'
# add r2, r1, r1		#r1 (le dernier) = r2 + r1
# aff r1				#Affiche r1 -> 'D' + 1 (code user) -> 'E'
# aff r2				#Affiche r2 -> 'D'
# st r2, 42			#Stock r2 dans l'adresse PC + (42 % IDX_MOD)
# ld 37, r3			#Met ce qu'il y a dans 37 dans r3 -> 'D'
# aff r3				#Affiche r3


# ;TEST DE STI DIRECT
###############################
# ld %68, r2			#Met %68 dans r2
# add r2, r1, r1		#r1 (le dernier) = r2 + r1
# aff r1				#Affiche r1
# aff r2				#Affiche r2
# sti r2, %29, %40	#Stock r2 a l'adresse de PC + ((%29 + %40) % IDX_MOD)
# ld 66, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 66
# aff r7				#Affiche r7
