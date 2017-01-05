# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/05 17:39:03 by tbouder          ###   ########.fr        #
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
SRC			=	main.c ft_extract_champion.c ft_init.c ft_init_helper.c ft_fight.c \
				ft_dump_mem.c ft_free.c ft_verbose.c ft_tools.c ft_verif.c \
				ft_get_flags.c ft_tools_helper.c\
				ft_func_helper.c ft_func_launcher.c \
				funcs/ft_func_live_aff.c \
				funcs/ft_func_add.c funcs/ft_func_sub.c \
				funcs/ft_func_and.c funcs/ft_func_xor.c funcs/ft_func_or.c \
				funcs/ft_func_fork.c funcs/ft_func_lfork.c \
				funcs/ft_func_zjmp.c \
				funcs/ft_func_ldi.c funcs/ft_func_lldi.c \
				funcs/ft_func_st.c funcs/ft_func_sti.c \
				funcs/ft_func_ld.c funcs/ft_func_lld.c \
				ncurse/ft_generic_ncurse.c ncurse/ft_reload_ncurse.c \
				ncurse/ft_print_ncurse.c ncurse/ft_dump_ncurse.c

OBJ			=	$(SRC:.c=.o)

################################################################################
#	RULES
################################################################################
# .SILENT: $(NAME) clean fclean $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIB) -lncurses $(CFLAGS)

main.o: vm.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean flcean

clean:
	@rm -f $(notdir $(OBJ)) $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
