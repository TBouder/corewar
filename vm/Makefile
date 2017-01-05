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

OBJ			=	main.o ft_extract_champion.o ft_init.o ft_init_helper.o ft_fight.o \
				ft_dump_mem.o ft_free.o ft_verbose.o ft_tools.o ft_verif.o \
				ft_get_flags.o ft_tools_helper.o\
				ft_func_helper.o ft_func_launcher.o \
				funcs/ft_func_live_aff.o \
				funcs/ft_func_add.o funcs/ft_func_sub.o \
				funcs/ft_func_and.o funcs/ft_func_xor.o funcs/ft_func_or.o \
				funcs/ft_func_fork.o funcs/ft_func_lfork.o \
				funcs/ft_func_zjmp.o \
				funcs/ft_func_ldi.o funcs/ft_func_lldi.o \
				funcs/ft_func_st.o funcs/ft_func_sti.o \
				funcs/ft_func_ld.o funcs/ft_func_lld.o \
				ncurse/ft_generic_ncurse.o ncurse/ft_reload_ncurse.o \
				ncurse/ft_print_ncurse.o ncurse/ft_dump_ncurse.o

################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	# $(MAKE) re -C ../libft
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB) -lncurses

clean:
	# $(MAKE) clean -C ../libft
	rm -f $(notdir $(OBJ)) $(OBJ)

fclean: clean
	# $(MAKE) fclean -C ../libft
	rm -f $(NAME)

re: fclean all
