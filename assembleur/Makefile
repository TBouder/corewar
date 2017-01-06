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

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
LDFLAGS		=

LIB			=	../libft/libft.a
LIBFTDIR	=	../libft

HEADER 		=	asm.h errors.h op.h

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
	@echo Creation of exe $(NAME)

%.o: %.c $(INC)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Compilation of $<

$(LIB):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@rm -f $(OBJ)
	@echo Asm : Deleted Obj files

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) Deleted 

re: fclean all
