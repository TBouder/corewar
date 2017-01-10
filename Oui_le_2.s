.name "Oui le 2"
.comment "Le 2 ! Le 2 ? Oui le 2 ! Le 2 sur ? Oui le 2 ! Ok donc le 2 ? Oui le 2 ! Sur ? Oui le 2 ! Le 2 ? Oui le 2 !"

hello:
# sti r1, %:live1, %1
st r1, 6
# live1:
	live %222
ld %0, r15
fork %:forcopy

st r1, 6
live %222
fork %:forjump

# sti r1, %:live2, %8
live1:
st r1, 6
	live %222
zjmp %:live1

forcopy:
st r1, 6
live %222
fork %:forlive
ld %-209, r11
# ld %-131, r11
ld %190056971, r10 # 0b54 0a0b
ld %0, r15
zjmp %:endtheworld


forlive:
ld %-204, r11
# ld %-126, r11
ld %16777216, r10 # 0100 0000
ld %0, r15
zjmp %:endtheworld


forjump:
ld %-200, r11
# ld %-122, r11
# ld %17432376, r10 # 0109 ff38
# ld %50986818, r10 # 0309 ff38
ld %34209572, r10 # 0209 ff24
ld %0, r15
zjmp %:endtheworld


endtheworld:
sti r10, r11, r0
# zjmp %:hello
zjmp %-214
   




# fork %:expelliarmus
# # fork %:catourne2


# live2:
# sti r1, %:live2, %8
# # st r1, 6
# 	live %2
# zjmp %:live2


# # ld %1, r42

# expelliarmus:
# sti r1, %:live3, %1
# # st r1, 16
# ld %0, r0 # 42991616 == 0290 0000 0000 00
# ld -7, r5
# ld 10, r3 # Debut du live dans r3
# ld 9, r4 # fin du live et saut loin avant dans r4
# live3:
# 	live %2
# zjmp %:hello
# # st r3, -70
# # st r4, -71
# sti r3, %:hello, %-8
# sti r4, %:hello, %-4
# sti r5, %:hello, %-15
# # mettre pleins de saut a avant hello
# # ld %654848, r5 # 09fe00 sautes le plus loin devant

# # catourne2:
# # ld %0, r7
# # ld %4, r8
# # ld %8, r9

# # defense:
# # sti r1, %:live4, %1
# # ld 10, r5
# # ld 9, r6
# # live4:
# # 	live %2
# # zjmp %:goodbye
# # sti r5, %:goodbye, r7
# # sti r6, %:goodbye, r8

# # add r8, r9, r8
# # add r7, r9, r7 # faire en sorte que ca finisse a zéro
# # zjmp %:hello
# # ld %0, r42 # permet de boucler dans le programme en évitant les pièges
# # zjmp %:defense

# ld %0, r42 # permet de boucler dans le programme en évitant les pièges
# zjmp %:hello
# goodbye:

# sti r1, r2, %15
# sti r1, %15, %15
# sti r1, -200, %15

# sti r1, r2, r3
# sti r1, %15, r3
# sti r1, -200, r3

