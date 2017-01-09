.name "Oui le 2"
.comment "Le 2 ! Le 2 ? Oui le 2 ! Le 2 sur ? Oui le 2 ! Ok donc le 2 ? Oui le 2 ! Sur ? Oui le 2 ! Le 2 ? Oui le 2 !"

hello:
sti r1, %:live1, %1
live1:
live %2
ld %0, r42
fork %:catourne


live2:
sti r1, %:live2, %8
live %2
zjmp %:live2


; # ld %1, r42
;
catourne:
	; ld %220, r8
	; ld %211, r9
	;
	; ld %1, r2			;Copie le num de l'instruc live
	; st r1, r8
	; st r2, r9
	; xor r0, r0, r0
	; zjmp %:catourne


	ld %1879245020, r3	;Copie [st r3, 220]
	ld %3, r4			;Copie le num de l'instruc st
	st r3, 220
	st r4, 211

	ld %1879245024, r5	;Copie [st r3, 220]
	ld %3, r6			;Copie le num de l'instruc st
	st r5, 190
	st r6, 181

; 7003 00da
; 7003 00de

; 0070 0300 dc70 0300 dc
; 7003 00dc 0070 0300 dc

	; ld %1879310556, r5	;Copie [st r4, 220] sans le num de l'instruc
	; st r5, 220
	; st r4, 220

	; ld -36, r6
	; st r6, 41

	; ld %656, r5
	; ld %0, r5
	; ld 0, r6
	;
	; ld %1879376292, r8
	; ld %3, r9
	;
	;
	; st r5, 420
	; st r6, 414
	; st r9, 420
	; st r8, 419


	; ld %9, r5
	; ld %-55, r6
	; st r5, 42
	; st r6, 41
; # sti r1, %:hello, %-150
; ld 16, r3
; # ld 8, r4
; live %2
; zjmp %:hello
;
; ld %0, r42


# fork %:catourne
