# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/12/07 23:47:28 by tbouder          ###   ########.fr        #
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
				ft_func.c ft_func_launcher.c ft_func_live_aff.c \
				\
				ft_func_add_sub.c ft_func_and_or_xor.c ft_func_forks.c \
				ft_func_zjmp.c ft_func_ldi_lldi.c ft_func_st_sti.c ft_func_ld_lld.c
OBJ			=	main.o ft_extract_champion.o ft_init.o ft_fight.o \
				ft_func.o ft_func_launcher.o ft_func_live_aff.o \
				\
				ft_func_add_sub.o ft_func_and_or_xor.o ft_func_forks.o \
				ft_func_zjmp.o ft_func_ldi_lldi.o ft_func_st_sti.o ft_func_ld_lld.o

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
