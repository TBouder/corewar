.name  "A"
.comment "THIS IS AN AWESOME COMMENT"

sti	r1, %:live, r1			; 1 + 4 + 1 = 6
sti	r1, %:live, %1			; 1 + 4 + 4 = 9
sti	r1, %:live, %1			; 1 + 4 + 4 = 9
sti	r1, %1, %1				; 1 + 4 + 4 = 9

and r1, r2, r3
and %1, %2, r3
sti	r1, %:yolololol, %1			#change live by the right value
ld	%1, r3
ld	%33, r6
forks:
	add	r2, r3, r2		;increment r2
	xor	r2, %15, r4		;if (r4) {carry = 0}
	or	r2, %15, r4		;if (r4) {carry = 0}
	and	r2, %15, r4		;if (r4) {carry = 0}
	yolololol:	live 	%4
	zjmp	%:endwhile		;if (carry)
	fork	%:forks
	ld	%0, r4			;carry = 1
	zjmp	%:forks
endwhile:
	ld	%0, r4			;carry = 1

sti	r1, %:live, r5			; 1 + 4 + 1 = 6
yolololol: live %5
 	zjmp %:live

sti	r1, %:live, r1			; 1 + 4 + 1 = 6
live:
	add	r2, r3, r2		;increment r2
	zjmp	%:live
