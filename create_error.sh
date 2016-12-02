# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_error.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/17 19:19:25 by tbouder           #+#    #+#              #
#    Updated: 2016/12/02 13:23:26 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

i="0"
# ############################################################################ #
j="0"
tab=("r4" "%4" "%:4" "4" ":4" "-4" ":-4" "%-4" "%:-4" "r-4")
# echo $1 ${tab[0]}, ${tab[1]}, ${tab[2]}, ${tab[3]}					> asm/tests/args/test_$1_$i.s

while [ $i -lt 10 ]; do
	echo ".name \"VALID NAME\"\n.comment \"VALID COMMENT\"\n4:\n $1 ${tab[$j]}"	> asm/tests/args/$1/test_$1_$i.s
	j=$[$j+1]
	i=$[$i+1]
done
# ############################################################################ #

# ############################################################################ #
j="0"
while [ $j -lt 10 ]; do
	k="0"
	while [ $k -lt 10 ]; do
		echo ".name \"VALID NAME\"\n.comment \"VALID COMMENT\"\n4:\n $1 ${tab[$j]}, ${tab[$k]}" > asm/tests/args/$1/test_$1_$i.s
		k=$[$k+1]
		i=$[$i+1]
	done
	j=$[$j+1]
done
# ############################################################################ #


# ############################################################################ #
j="0"
while [ $j -lt 10 ]; do
	k="0"
	while [ $k -lt 10 ]; do
		l="0"
		while [ $l -lt 10 ]; do
			echo ".name \"VALID NAME\"\n.comment \"VALID COMMENT\"\n4:\n $1 ${tab[$j]}, ${tab[$k]}, ${tab[$l]}" > asm/tests/args/$1/test_$1_$i.s
			i=$[$i+1]
			l=$[$l+1]
		done
		k=$[$k+1]
	done
	j=$[$j+1]
done
# ############################################################################ #
