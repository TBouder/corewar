# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/12/27 14:46:22 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	asm

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

LIB			=	../libft/libft.a

HEADER 		=	asm.h

################################################################################
#	SRC
################################################################################
SRC			=	main.c ft_asm_func.c ft_parse.c ft_transform_hex.c ft_get_size.c \
				ft_opweight_part1.c ft_opweight_part2.c ft_tools.c ft_get_file.c \
				ft_init.c ft_free.c ft_verif.c ft_get_champion.c ft_btree_asm.c \
				ft_get_weight.c ft_write_instructions.c ft_valid_file.c \
				ft_calcul_jump.c
OBJ			=	main.o ft_asm_func.o ft_parse.o ft_transform_hex.o ft_get_size.o \
				ft_opweight_part1.o ft_opweight_part2.o ft_tools.o ft_get_file.o \
				ft_init.o ft_free.o ft_verif.o ft_get_champion.o ft_btree_asm.o \
				ft_get_weight.o ft_write_instructions.o ft_valid_file.o \
				ft_calcul_jump.o

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
