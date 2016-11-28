.name "zork"
.comment "just a basic living prog"

l2:
sti	r1, %:l2, %22
sti	r1, %:l2, r1
sti	r1, %:l2, %1
sti	r1, %1, %1


# 	and	r1,%0,r1
# # live:	live	%1
	# zjmp	%:l2
