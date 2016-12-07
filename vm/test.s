.name    "Survivor"
.comment "Invincible"

; ; TEST DE LD DIRECT ET INDIRECT
; ################################
; ld %68, r2			#Met %68 dans r2 -> D
; ld 11, r7			#Met 11 dans r7 -> 0
; aff r2				#Affiche r2 -> 'D'
; aff r7				#Affiche r7 -> ''
; add r2, r7, r3		#r3 = r2 - r7 ->
; aff r3				#Affiche r3

; ; TEST DE LLD DIRECT ET INDIRECT
; ################################
lld %580, r2			#Met %580 dans r2
lld 523, r7			#Met 523 dans r7
aff r2				#Affiche r2
aff r7				#Affiche r7
sub r2, r7, r3		#r2 = r7 + r3
aff r3				#Affiche r3

; ; TEST DE ST REG
; ################################
; ld %68, r2			#Met %68 dans r2
; add r2, r1, r1		#r2 = r1 + r1
; aff r1				#Affiche r1
; aff r2				#Affiche r2
; st r2, r3				#Stock r2 dans r3
; aff r3				#Affiche r3

; ; TEST DE ST IND
; ################################
; ld %68, r2			#Met %68 dans r2
; add r2, r1, r1		#r2 = r1 + r1
; aff r1				#Affiche r1
; aff r2				#Affiche r2
; st r2, 42			#Stock r2 dans l'adresse PC + (42 % IDX_MOD)
; aff r3				#Affiche r3


; ; TEST DE STI DIRECT
; ################################
; ld %68, r2			#Met %68 dans r2
; add r2, r1, r1		#r2 = r1 + r1
; aff r1				#Affiche r1
; aff r2				#Affiche r2
; sti r2, %29, %40	#Stock r2 a l'adresse de PC + ((%29 + %40) % IDX_MOD)
; ld 66, r7			#Stock dans r7 ce qu'il y a a l'adresse PC + 66
; aff r7				#Affiche r7
