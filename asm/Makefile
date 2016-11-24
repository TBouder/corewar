# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/11/24 09:49:05 by quroulon         ###   ########.fr        #
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
SRC			=	main.c ft_asm_func.c ft_parse.c ft_transform_hex.c ft_get_size.c\
				ft_opweight_part1.c ft_opweight_part2.c ft_tools.c ft_get_file.c
OBJ			=	main.o ft_asm_func.o ft_parse.o ft_transform_hex.o ft_get_size.o\
				ft_opweight_part1.o ft_opweight_part2.o ft_tools.o ft_get_file.o

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
