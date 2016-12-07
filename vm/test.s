.name    "Survivor"
.comment "Invincible"


lld %580, r2
lld 560, r2
lld 561, r2
lld 562, r2
lld 563, r2
lld 564, r2
lld 565, r2
lld 566, r2
lld 567, r2
lld 568, r2
lld 569, r2
; lld 523, r7
; aff r1
aff r2
aff r7
; add r1, r2, r3
sub r2, r7, r3
aff r3






	; ldi %1, %0, r1
	; live	%1
; 	fork	%:f1
; 	zjmp	%:j1
; f1:
; 	ld	%44, r2
; 	zjmp	%:run
; j1:
; run:	xor	r0, r0, r0
; l1:	st	r2, 1
; 	live	%1
; 	zjmp	%:l1


; TEST DE LD DIRECT ET INDIRECT
################################
; ld %580, r2 ;ld %68, r2
; ld 523, r7 ;ld 11, r7
; aff r2
; aff r7
; sub r2, r7, r3
; aff r3
