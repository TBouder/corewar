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


# ld %1, r42

catourne:
sti r1, %:live3, %1
ld 10, r3
ld 9, r4
live3:
	live %2
zjmp %:hello
sti r3, %:hello, %-25
sti r4, %:hello, %-21

ld %0, r42
zjmp %:hello


# fork %:catourne

