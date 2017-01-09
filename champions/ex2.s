.name "zork"
.comment "just a basic living prog"

; l2:
	fork	%10
	sti	r1, -42, %0
	; and	r1, %0, r1
live:
	live	%0
	; zjmp	%0
