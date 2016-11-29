# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/11/29 17:49:07 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	corewar

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

LIB			=	../libft/libft.a

HEADER 		=	vm.h

################################################################################
#	SRC
################################################################################
SRC			=	main.c ft_func_part1.c ft_extract_champion.c ft_init.c
OBJ			=	main.o ft_func_part1.o ft_extract_champion.o ft_init.o

################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	# $(MAKE) re -C ../libft
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	# $(MAKE) clean -C ../libft
	rm -f $(OBJ)

fclean: clean
	# $(MAKE) fclean -C ../libft
	rm -f $(NAME)

re: fclean all
