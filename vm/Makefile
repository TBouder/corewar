# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/12/20 23:09:55 by tbouder          ###   ########.fr        #
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
SRC			=	main.c ft_extract_champion.c ft_init.c ft_fight.c \
				ft_dump_mem.c ft_free.c \
				ft_func.c ft_func_launcher.c \
				funcs/ft_func_live_aff.c \
				funcs/ft_func_add_sub.c \
				funcs/ft_func_and_or_xor.c \
				funcs/ft_func_forks.c \
				funcs/ft_func_zjmp.c \
				funcs/ft_func_ldi_lldi.c \
				funcs/ft_func_st_sti.c \
				funcs/ft_func_ld_lld.c \
				ncurse/ft_map_ncurse.c ncurse/ft_reload_windows.c

OBJ			=	main.o ft_extract_champion.o ft_init.o ft_fight.o \
				ft_dump_mem.o ft_free.o \
				ft_func.o ft_func_launcher.o \
				funcs/ft_func_live_aff.o \
				funcs/ft_func_add_sub.o \
				funcs/ft_func_and_or_xor.o \
				funcs/ft_func_forks.o \
				funcs/ft_func_zjmp.o \
				funcs/ft_func_ldi_lldi.o \
				funcs/ft_func_st_sti.o \
				funcs/ft_func_ld_lld.o \
				ncurse/ft_map_ncurse.o ncurse/ft_reload_windows.o

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
	rm -f $(OBJ)

fclean: clean
	# $(MAKE) fclean -C ../libft
	rm -f $(NAME)

re: fclean all
