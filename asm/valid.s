.name  "LEGENDARY"
.comment "THIS IS AN AWESOME COMMENT"

sti	r1, %:live, %1			;change live by the right value
sti	r1, %1, %1			;change live by the right valu.namee
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

# yolololol: live %5
# 	zjmp %:live

live:
	add	r2, r3, r2		;increment r2
