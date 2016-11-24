#deassembler par msa 1.8, made by joe
.name "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
.comment "111111111111111111111111111111111111111111111111111"

label00:
	fork  %:label00
	ld    %-272,r3
	live  %0
	fork  %:label00
	ld    %-272,r3
	fork  %:label00
	ld    %0,r2
	ld    %0,r4
	zjmp  %:label00
