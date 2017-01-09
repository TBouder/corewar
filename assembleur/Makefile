# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/08 21:46:45 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	asm

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LDFLAGS		=

LIB			=	../libft/libft.a
LIBFTDIR	=	../libft

INC 		=	asm.h errors.h op.h

_RED		=	\033[0;31m
_GREEN		=	\033[0;32m
_BLUE		=	\033[0;36m
_RESET		=	\033[0;m
_WHITE		=	\033[0;37m

################################################################################
#	SRC
################################################################################

SRC			=	main.c ft_asm_func.c ft_parse.c ft_transform_hex.c ft_get_size.c \
				ft_opweight_part1.c ft_opweight_part2.c ft_tools.c ft_get_file.c \
				ft_init.c ft_free.c ft_verif.c ft_get_champion.c ft_btree_asm.c \
				ft_get_weight.c ft_write_instructions.c ft_valid_file.c \
				ft_calcul_jump.c

OBJ			=	$(SRC:%.c=%.o)

################################################################################
#	RULES
################################################################################

.PHONY: clean flcean re all

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "$(_GREEN)Creation of exe $@$(_RESET)"

%.o: %.c $(INC)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "Compilation of $<"

$(LIB):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -f $(OBJ)
	@echo "$(_RED)Asm : Deleted Obj files$(_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)$(NAME) Deleted$(_RESET)"

re: fclean all
