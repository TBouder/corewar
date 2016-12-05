.name "zork"
.comment "just a basic living prog"

; l2:
	lfork	%0
	sti	r1, -42, %0
	; and	r1, %0, r1
live:
	live	%0
	; zjmp	%0
