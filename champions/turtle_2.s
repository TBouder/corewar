.name 		"turtle_2"
.comment	"Just a second one"

entry:
sti			r1, %:zork, %1
sti			r1, %:ardef, %1
sti			r1, %:avdef, %1
sti			r1, %:entry_l1, %1
ld			%0, r16
fork		%:zork

entry_l1:
live		%42
ld			%439025904, r2
ld			%0, r16
fork		%:avdef

################################################################################

ardef:
live		%42
# ld			%31, r3 				#; 
# ld			%1, r4
# sub			r3, r4, r5
# sti			r5, %:stop, %0

# ld			%-400, r6 				#; 
# ld			%5, r7
# add			r6, r7, r6


# st			r2, r6

# ld			%:stop, r5
# zjmp		%:ardef


st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
st			r2, -400
zjmp		%:ardef

################################################################################

zork:
live		%42
zjmp		%:zork

################################################################################

avdef:
live		%42
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
st			r2, 400
zjmp		%:avdef

################################################################################

stop:

