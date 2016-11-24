.name  "A"
.comment "THIS IS AN AWESOME COMMENT"

sti	r1, %:live, r1			; 1 + 4 + 1 = 6
sti	r1, %:live, %1			; 1 + 4 + 4 = 9
sti	r1, %:live, %1			; 1 + 4 + 4 = 9
sti	r1, %1, %1				; 1 + 4 + 4 = 9



and r1, r2, r3
and %1, %2, r3
# sti	r1, %:yolololol, %1			#change live by the right value
# ld	%1, r3
# ld	%33, r6
# forks:
# 	add	r2, r3, r2		;increment r2
# 	xor	r2, %15, r4		;if (r4) {carry = 0}
# 	or	r2, %15, r4		;if (r4) {carry = 0}
# 	and	r2, %15, r4		;if (r4) {carry = 0}
# 	yolololol:	live 	%4
# 	zjmp	%:endwhile		;if (carry)
# 	fork	%:forks
# 	ld	%0, r4			;carry = 1
# 	zjmp	%:forks

# endwhile:
# 	ld	%0, r4			;carry = 1

sti	r1, %:live, r1			; 1 + 4 + 1 = 6
yolololol: live %5
# 	zjmp %:live

sti	r1, %:live, r1			; 1 + 4 + 1 = 6
live:
	add	r2, r3, r2		;increment r2
	zjmp	%:live


# [Codage octal]
# 	0 -> [XX]
# 	1 -> [XX][XX]

# [r]
# 	1 -> [XX]

# [IND]
# 	2 -> [XX] [XX]

# [DIR]
# 	2 -> [XX][XX]
# 	4 -> [XX][XX] [XX][XX]

# [0b64] [01] [003c] [01]			60 - 6
# [0b68] [01] [0036] [0001]		54 - 6
# [0b68] [01] [002f] [0001]		47 - 6
# [0b68] [01] [0001] [0001]		

# [0654] [01] [02] [03]
# [06a4] [0000 0001] [0000 0002] [03]

# [0b64] [01] [0011] [01]			17

# [01] [0000 0005]

# [0b64] [01] [0006] [01]			6

# [0454] [02] [03] [02]