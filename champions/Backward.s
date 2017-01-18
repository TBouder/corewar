.name    "sebc"
.comment "sebc"

	st	r1, 1
	ld	%4, r3
l1:
	live	%1
	ld	1, r2
	ld %64, r7
	add r2, r7, r8
	aff r2
	aff r7
	aff r8
l3:
	ldi	3, r2, r4
	aff r4
	sti	r4, 2, r2
	add	r2, r3, r2
live: zjmp	%1
	xor	r4, r4, r4
	zjmp	%3
l2:
