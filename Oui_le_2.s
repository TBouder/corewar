.name "Oui le 2"
.comment "Le 2 ! Le 2 ? Oui le 2 ! Le 2 sur ? Oui le 2 ! Ok donc le 2 ? Oui le 2 ! Sur ? Oui le 2 ! Le 2 ? Oui le 2 !"

hello:
st r1, 6
live %222
zjmp %3
fork %:forcopy

st r1, 6
live %222
fork %:forjump


sti r1, %:live3, %1
# st r1, 16
ld %0, r0
ld -7, r5
ld 10, r3
ld 9, r4
live3:
	live %2
zjmp %-5
# st r3, -70
# st r4, -71
sti r3, %:hello, %-8
sti r4, %:hello, %-4
sti r5, %:hello, %-15

fork %:hello
ld %0, r15

live1:
st r1, 6
	live %222
zjmp %:live1

forcopy:
st r1, 6
live %222
fork %:forlive

ld %13, r11
ld %190056971, r10
ld %0, r15
zjmp %:endtheworld


forlive:
ld %18, r11
ld %16777216, r10
ld %0, r15
zjmp %:endtheworld


forjump:
ld %22, r11
ld -169, r10
ld %0, r15
zjmp %:endtheworld


endtheworld:
sti r10, r11, r0
zjmp %8
   