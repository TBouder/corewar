.name "Oui le 2"
.comment "Le 2 ! Le 2 ? Oui le 2 ! Le 2 sur ? Oui le 2 ! Ok donc le 2 ? Oui le 2 ! Sur ? Oui le 2 ! Le 2 ? Oui le 2 !"

hello:
sti r1, %:live1, %1
live1:
	live %2
ld %0, r42
fork %:catourne1
# fork %:catourne2


live2:
sti r1, %:live2, %8
	live %2
zjmp %:live2


# ld %1, r42

catourne1:
sti r1, %:live3, %1
ld 10, r3 # Debut du live dans r3
ld 9, r4 # fin du live et saut loin avant dans r4
live3:
	live %2
zjmp %:hello
st r3, -70
st r4, -71
# sti r3, %:hello, %-25 # transformer les %:hello en valeur dir pour pouvoir se déplacer
# sti r4, %:hello, %-21

# mettre pleins de saut a avant hello
# ld %654848, r5 # 09fe00 sautes le plus loin devant

catourne2:
ld %0, r7
ld %4, r8
ld %8, r9

defense:
sti r1, %:live4, %1
ld 10, r5
ld 9, r6
live4:
	live %2
zjmp %:goodbye
sti r5, %:goodbye, r7
sti r6, %:goodbye, r8

add r8, r9, r8
add r7, r9, r7 # faire en sorte que ca finisse a zéro
zjmp %:hello
ld %0, r42 # permet de boucler dans le programme en évitant les pièges
zjmp %:defense

ld %0, r42 # permet de boucler dans le programme en évitant les pièges
zjmp %:hello
goodbye: