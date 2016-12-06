#deassembler par msa 1.8, made by joe
.name "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
.comment "111111111111111111111111111111111111111111111111111"

label00:
	fork  %:label00
	ld    %-272,r3
	live  %0
	fork  %:label00
	ld    %-272, r3
	fork  %:label00
	ld    %0,r2
	ld    %0,r4
	zjmp  %:label00

# sti	r1, %:live, r1			; 1 + 4 + 1 = 6
# live:
# 	live  %0
# sti	r1, %:live, r1			; 1 + 4 + 1 = 6
# sti	r1, %:live, %1			; 1 + 4 + 4 = 9
# sti	r1, %:live, %1			; 1 + 4 + 4 = 9
# live:
# 	live  %1
# sti	r1, %:live, r1			; 1 + 4 + 1 = 6


# # 0100 0000 00
# # 0b 6401 fffb 01
# # 0b 6801 fff5 0001 
# # 0b 6801 ffee 0001
# # 01 0000 0001 

# 0b64 0100 0601 
# 0100 0000 00
# 0b 6401 fffb 01
# 0b 6801 fff5 0001 
# 0b 6801 ffee 0001
# 01 0000 0001 
# 0b64 01ff e201 