# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    corewar_tests.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 19:19:25 by tbouder           #+#    #+#              #
#    Updated: 2017/01/03 20:32:55 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

ft_arg ()
{
	# make -C $EXEC/ fclean && make -C $EXEC/
	while [ $# -ne 0 ];do
		if [ "$1" = "leaks" ]; then
			leaks="OK"
		elif [ "$1" = "file" ]; then
			file="OK"
		elif [ "$1" = "name" ]; then
			name="OK"
		elif [ "$1" = "comment" ]; then
			comment="OK"
		elif [ "$1" = "content_comma" ]; then
			content_comma="OK"
		elif [ "$1" = "content_instruct" ]; then
			content_instruct="OK"
		elif [ "$1" = "arg" ]; then
			arg_ok="OK"
			ARG=$2
		elif [ "$1" = "offi" ]; then
			offi="OK"
		elif [ "$1" = "vm" ]; then
			vm="OK"
		fi
		shift
	done
}

ft_leaks()
{
	ASM=$1
	shift
	if [[ $leaks = "OK" ]]; then
		sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp -q $ASM $@
	else
		$ASM $@
	fi
}

echo '   ____ ___  ____  _______        ___    ____    '
echo '  / ___/ _ \|  _ \| ____\ \      / / \  |  _ \   '
echo ' | |  | | | | |_) |  _|  \ \ /\ / / _ \ | |_) |  '
echo ' | |__| |_| |  _ <| |___  \ V  V / ___ \|  _ <   '
echo '  \____\___/|_| \_\_____|  \_/\_/_/   \_\_| \_\  '
echo 'quroulon@student.42.fr      tbouder@student.42.fr'

# name="NULL"
ft_arg $@

ASM=./asm/asm
COREWAR=./vm/corewar
if [ "$file" = "OK" ]; then
	echo "\033[44m\033[1mFILE ERROR (empty, not valid, not file, not .s, dev/null, etc.)\033[0m"
	echo "\033[41m\033[1m ---> ./asm\033[0m"							&& ft_leaks $ASM
	echo "\n\033[41m\033[1m ---> ./asm ..\033[0m" 						&& ft_leaks $ASM ..
	echo "\n\033[41m\033[1m ---> ./asm 1\033[0m" 						&& ft_leaks $ASM 1
	echo "\n\033[41m\033[1m ---> ./asm empty\033[0m" 					&& ft_leaks $ASM empty
	echo "\n\033[41m\033[1m ---> ./asm /dev/null\033[0m" 				&& ft_leaks $ASM /dev/null
	echo "\n\033[41m\033[1m ---> ./asm /dev/random\033[0m" 				&& ft_leaks $ASM /dev/random
	echo "\n\033[41m\033[1m ---> ./asm ""\033[0m" 						&& ft_leaks $ASM ""
	echo "\n\033[41m\033[1m ---> ./asm NULL\033[0m" 					&& ft_leaks $ASM NULL
	echo "\n\033[41m\033[1m ---> ./asm main.c\033[0m" 					&& ft_leaks $ASM main.c
	echo "\n\033[41m\033[1m ---> ./asm main.c Makefile\033[0m" 			&& ft_leaks $ASM main.c Makefile
	echo "\n\033[41m\033[1m ---> ./asm tests/test.s\033[0m" 			&& ft_leaks $ASM tests/test.s
	echo "\n\033[41m\033[1m ---> ./asm tests/empty.s main.c\033[0m" 	&& ft_leaks $ASM tests/empty.s main.c
	echo "\n\033[41m\033[1m ---> ./asm main.c empty.s\033[0m" 			&& ft_leaks $ASM main.c tests/empty.s
	echo "\n\033[41m\033[1m ---> ./asm tests/empty.s valid.s\033[0m" 	&& ft_leaks $ASM tests/empty.s tests/valid.s
	echo "\n\033[41m\033[1m ---> ./asm tests/empty.s\033[0m" 			&& ft_leaks $ASM tests/empty.s
fi

if [ "$name" = "OK" ]; then
	echo "\n\n\033[44m\033[1mCHAMPION ERROR (name)\033[0m"
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name00.s (no name line)\033[0m"						&& ft_leaks $ASM asm/tests/error_name00.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name01.s (only .name)\033[0m"						&& ft_leaks $ASM asm/tests/error_name01.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name02.s (.name \"\")\033[0m"						&& ft_leaks $ASM asm/tests/error_name02.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name03.s (.name 'name')\033[0m"						&& ft_leaks $ASM asm/tests/error_name03.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name04.s (.name '')\033[0m"							&& ft_leaks $ASM asm/tests/error_name04.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name05.s (.name \"name\"\"\")\033[0m"				&& ft_leaks $ASM asm/tests/error_name05.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name06.s (.name \"name\"\")\033[0m"					&& ft_leaks $ASM asm/tests/error_name06.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name07.s (.name \"name)\033[0m"						&& ft_leaks $ASM asm/tests/error_name07.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name08.s (.name name)\033[0m"						&& ft_leaks $ASM asm/tests/error_name08.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name09.s (.name \"name\" ,)\033[0m"					&& ft_leaks $ASM asm/tests/error_name09.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name10.s (.name \"name\" 	o)\033[0m"				&& ft_leaks $ASM asm/tests/error_name10.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name11.s (.name o \"name\")\033[0m"					&& ft_leaks $ASM asm/tests/error_name11.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name12.s (.name , \"name\")\033[0m"					&& ft_leaks $ASM asm/tests/error_name12.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name13.s (.name name\")\033[0m"						&& ft_leaks $ASM asm/tests/error_name13.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name14.s (.name \"\" \"name\")\033[0m"				&& ft_leaks $ASM asm/tests/error_name14.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name15.s (.name \"\"name\")\033[0m"					&& ft_leaks $ASM asm/tests/error_name15.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name16.s (.name after instructions)\033[0m"			&& ft_leaks $ASM asm/tests/error_name16.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name17.s (2 fois .name)\033[0m"						&& ft_leaks $ASM asm/tests/error_name17.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name18.s (.name a la fin)\033[0m"					&& ft_leaks $ASM asm/tests/error_name18.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_name19.s (name \"name\")\033[0m"						&& ft_leaks $ASM asm/tests/error_name19.s
fi

if [ "$comment" = "OK" ]; then
	echo "\n\n\033[44m\033[1mCHAMPION ERROR (comment)\033[0m"
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment00.s (no comment line)\033[0m"				&& ft_leaks $ASM asm/tests/error_comment00.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment01.s (only .comment)\033[0m"					&& ft_leaks $ASM asm/tests/error_comment01.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment02.s (.comment \"\")\033[0m"					&& ft_leaks $ASM asm/tests/error_comment02.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment03.s (.comment 'comment')\033[0m"				&& ft_leaks $ASM asm/tests/error_comment03.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment04.s (.comment '')\033[0m"					&& ft_leaks $ASM asm/tests/error_comment04.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment05.s (.comment \"comment\"\"\")\033[0m"		&& ft_leaks $ASM asm/tests/error_comment05.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment06.s (.comment \"comment\"\")\033[0m"			&& ft_leaks $ASM asm/tests/error_comment06.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment07.s (.comment \"comment)\033[0m"				&& ft_leaks $ASM asm/tests/error_comment07.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment08.s (.comment comment)\033[0m"				&& ft_leaks $ASM asm/tests/error_comment08.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment09.s (.comment \"comment\" ,)\033[0m"			&& ft_leaks $ASM asm/tests/error_comment09.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment10.s (.comment \"comment\" 	o)\033[0m"		&& ft_leaks $ASM asm/tests/error_comment10.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment11.s (.comment o \"comment\")\033[0m"			&& ft_leaks $ASM asm/tests/error_comment11.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment12.s (.comment , \"comment\")\033[0m"			&& ft_leaks $ASM asm/tests/error_comment12.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment13.s (.comment comment\")\033[0m"				&& ft_leaks $ASM asm/tests/error_comment13.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment14.s (.comment \"\" \"comment\")\033[0m"		&& ft_leaks $ASM asm/tests/error_comment14.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment15.s (.comment \"\"comment\")\033[0m"			&& ft_leaks $ASM asm/tests/error_comment15.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment16.s (.comment after instructions)\033[0m"	&& ft_leaks $ASM asm/tests/error_comment16.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment17.s (2 fois .comment)\033[0m"				&& ft_leaks $ASM asm/tests/error_comment17.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment18.s (.comment a la fin)\033[0m"				&& ft_leaks $ASM asm/tests/error_comment18.s
	echo "\n\033[41m\033[1m ---> ./asm tests/error_comment19.s (comment \"comment\")\033[0m"			&& ft_leaks $ASM asm/tests/error_comment19.s
fi

if [ "$content_comma" = "OK" ]; then
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_00.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_00.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_01.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_01.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_02.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_02.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_03.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_03.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_04.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_04.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_05.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_05.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_06.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_06.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_comma_07.s  \033[0m"				&& ft_leaks $ASM asm/tests/content/error_comma_07.s
fi

if [ "$content_instruct" = "OK" ]; then
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_00.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_00.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_01.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_01.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_02.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_02.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_03.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_03.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_04.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_04.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_05.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_05.s
	echo "\n\033[41m\033[1m ---> ./asm tests/content/error_instruct_06.s  \033[0m"			&& ft_leaks $ASM asm/tests/content/error_instruct_06.s
fi

if [ "$arg_ok" = "OK" ]; then
	i="0"
	while [ $i -lt 1110 ]; do

		if [ "$offi" = "OK" ]; then
			./corewar-exemple/asm asm/tests/args/$ARG/test_$(echo $ARG)_$(echo $i).s | grep "Writing"
		else
			ft_leaks $ASM asm/tests/args/$ARG/test_$(echo $ARG)_$(echo $i).s | grep "Writing"
		fi
		i=$[$i+1]
	done
fi

if [ "$vm" = "OK" ]; then
	echo "\033[44m\033[1mVM NO CHAMPS\033[0m"
	echo "\033[41m\033[1m ---> ./corewar\033[0m"					&& ft_leaks $COREWAR
	echo "\033[41m\033[1m ---> ./corewar ..\033[0m"					&& ft_leaks $COREWAR ..
	echo "\033[41m\033[1m ---> ./corewar 1\033[0m"					&& ft_leaks $COREWAR 1
	echo "\033[41m\033[1m ---> ./corewar empty\033[0m"				&& ft_leaks $COREWAR empty
	echo "\033[41m\033[1m ---> ./corewar /dev/null\033[0m"			&& ft_leaks $COREWAR /dev/null
	echo "\033[41m\033[1m ---> ./corewar /dev/random\033[0m"		&& ft_leaks $COREWAR /dev/random
	echo "\033[41m\033[1m ---> ./corewar ""\033[0m"					&& ft_leaks $COREWAR ""
	echo "\033[41m\033[1m ---> ./corewar NULL\033[0m"				&& ft_leaks $COREWAR NULL
	echo "\033[41m\033[1m ---> ./corewar vm/main.c\033[0m"			&& ft_leaks $COREWAR vm/main.c
	echo "\033[41m\033[1m ---> ./corewar valid.s\033[0m"			&& ft_leaks $COREWAR valid.s
	echo "\033[41m\033[1m ---> ./corewar vm/test.cor\033[0m"		&& ft_leaks $COREWAR vm/test.cor
	echo "\033[41m\033[1m ---> ./corewar vm/testfile.cor\033[0m"	&& ft_leaks $COREWAR vm/testfile.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n\033[0m" 				&& ft_leaks $COREWAR -n
	echo "\n\033[41m\033[1m ---> ./corewar -d\033[0m" 				&& ft_leaks $COREWAR -d
	echo "\n\033[41m\033[1m ---> ./corewar -dump\033[0m" 			&& ft_leaks $COREWAR -dump
	echo "\n\033[41m\033[1m ---> ./corewar -g\033[0m" 				&& ft_leaks $COREWAR -g
	echo "\n\033[41m\033[1m ---> ./corewar -v\033[0m" 				&& ft_leaks $COREWAR -v

# ############################################################################ #

	echo "\n\033[44m\033[1mVM TOO MANY CHAMPS\033[0m"
	echo "\033[41m\033[1m ---> ./corewar 5 champs\033[0m"	&& ft_leaks $COREWAR valid.cor valid.cor valid.cor valid.cor valid.cor
	echo "\033[41m\033[1m ---> ./corewar 6 champs\033[0m"	&& ft_leaks $COREWAR valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor
	echo "\033[41m\033[1m ---> ./corewar 7 champs\033[0m"	&& ft_leaks $COREWAR valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor
	echo "\033[41m\033[1m ---> ./corewar 8 champs\033[0m"	&& ft_leaks $COREWAR valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor valid.cor

# ############################################################################ #

	echo "\n\033[44m\033[1mVM WITH -n\033[0m"
	echo "\n\033[41m\033[1m ---> ./corewar -n valid.cor\033[0m"		&& ft_leaks $COREWAR -n valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n -1 valid.cor\033[0m"	&& ft_leaks $COREWAR -n -1 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n e valid.cor\033[0m"	&& ft_leaks $COREWAR -n e valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n -n valid.cor\033[0m"	&& ft_leaks $COREWAR -n -n valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n 1 valid.cor -n valid.cor\033[0m" \
		&& ft_leaks $COREWAR -n 1 valid.cor -n valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n 1 valid.cor -n 2 valid.cor -n valid.cor\033[0m" \
		&& ft_leaks $COREWAR -n 1 valid.cor -n 2 valid.cor -n valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n 1 valid.cor -n 2 valid.cor -n 3 valid.cor -n valid.cor\033[0m" \
		&& ft_leaks $COREWAR -n 1 valid.cor -n 2 valid.cor -n 3 valid.cor -n valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n 1 valid.cor -n 2 valid.cor -n valid.cor -n 3 valid.cor\033[0m" \
		&& ft_leaks $COREWAR -n 1 valid.cor -n 2 valid.cor -n valid.cor -n 3 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -n 1 valid.cor -n 1 valid.cor\033[0m" \
		&& ft_leaks $COREWAR -n 1 valid.cor -n 1 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar valid.cor -n 1 valid.cor\033[0m" \
		&& ft_leaks $COREWAR valid.cor -n 1 valid.cor

# ############################################################################ #

	echo "\n\033[44m\033[1mVM WITH -d & -dump\033[0m"
	echo "\n\033[41m\033[1m ---> ./corewar -d valid.cor\033[0m"					&& ft_leaks $COREWAR -d valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -d -1 valid.cor\033[0m"				&& ft_leaks $COREWAR -d -1 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -d e valid.cor\033[0m"				&& ft_leaks $COREWAR -d e valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -d -n 5 valid.cor\033[0m"			&& ft_leaks $COREWAR -d -n 5 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -dump valid.cor\033[0m"				&& ft_leaks $COREWAR -dump valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -dump -1 valid.cor\033[0m"			&& ft_leaks $COREWAR -dump -1 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -dump e valid.cor\033[0m"			&& ft_leaks $COREWAR -dump e valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -dump -n 5 valid.cor\033[0m"			&& ft_leaks $COREWAR -dump -n 5 valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -d 10 valid.cor -d valid.cor\033[0m"	&& ft_leaks $COREWAR -d 10 valid.cor -d valid.cor
	echo "\n\033[41m\033[1m ---> ./corewar -d 10 valid.cor -d valid.cor\033[0m"	&& ft_leaks $COREWAR -d 10 valid.cor -d 2 valid.cor

	# ./corewar -g -n 99 ../valid.cor -n 50 ../valid.cor -n 8 ../valid.cor -n 1 ../valid.cor OKAY a chaque fois
# ############################################################################ #


	# echo "\n\033[41m\033[1m ---> ./corewar -n\033[0m" 		&& ft_leaks $COREWAR -n
	# echo "\n\033[41m\033[1m ---> ./corewar -n\033[0m" 		&& ft_leaks $COREWAR -n
fi
