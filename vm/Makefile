# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/09 09:18:10 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	corewar

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g
CFLAGS_EXT	=	-O3 -Wwrite-strings -Wstrict-prototypes -Wunreachable-code -Wno-missing-braces  -Wno-missing-field-initializers \
				-Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int -Werror-implicit-function-declaration -Wmain \
				-Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized \
				-Wunknown-pragmas -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
				-Wbad-function-cast -Wsign-compare -Waggregate-return -Wmissing-prototypes -Wmissing-declarations -Wformat -Wmissing-format-attribute -Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline
LDFLAGS		=	-lncurses

LIB			=	../libft/libft.a
LIBFTDIR	=	../libft

INC 		=	vm.h ft_macro.h op.h

# _GREEN		=	$'\x1b[32m'

################################################################################
#	SRC
################################################################################

SRC			=	main.c ft_extract_champion.c ft_init.c ft_init_helper.c ft_fight.c \
				ft_dump_mem.c ft_free.c ft_free_helper.c ft_verbose.c ft_tools.c ft_verif.c \
				ft_get_flags.c ft_tools_helper.c\
				ft_func_helper.c ft_func_launcher.c ft_func_buffer.c\
				funcs/ft_func_live.c funcs/ft_func_aff.c\
				funcs/ft_func_add.c funcs/ft_func_sub.c \
				funcs/ft_func_and.c funcs/ft_func_xor.c funcs/ft_func_or.c \
				funcs/ft_func_fork.c funcs/ft_func_lfork.c \
				funcs/ft_func_zjmp.c \
				funcs/ft_func_ldi.c funcs/ft_func_lldi.c \
				funcs/ft_func_st.c funcs/ft_func_sti.c \
				funcs/ft_func_ld.c funcs/ft_func_lld.c \
				ncurse/ft_generic_ncurse.c ncurse/ft_reload_ncurse.c \
				ncurse/ft_print_ncurse.c ncurse/ft_dump_ncurse.c ncurse/ft_dump_ncurse_helper.c

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
	@echo Vm : Deleted Obj files

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) Deleted

re: fclean all
