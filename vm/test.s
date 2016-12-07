.name    "Survivor"
.comment "Invincible"


ld %68, r2
xor	%68, r1, r3
and %69, r3, r4
# xor	r2, r1, r3
aff r2
aff r3
aff r4






# ldi %1, %0, r1
# live	%1
# 	fork	%:f1
# 	zjmp	%:j1
# f1:
# 	ld	%44, r2
# 	zjmp	%:run
# j1:
# run:	xor	r0, r0, r0
# l1:	st	r2, 1
# 	live	%1
# 	zjmp	%:l1


# TEST DE LD DIRECT ET INDIRECT
# ################################
# ld %580, r2 ; ld %68, r2
# ld 523, r7 ; ld 11, r7
# aff r2
# aff r7
# sub r2, r7, r3
# aff r3
