# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/03 16:23:18 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	corewar

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

LIB			=	../libft/libft.a

HEADER 		=	asm.h

################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean

all: $(NAME)

$(NAME):
	$(MAKE) -C ../libft
	$(MAKE) -C asm
	$(MAKE) -C vm

clean:
	$(MAKE) clean -C ../libft
	$(MAKE) clean -C asm
	$(MAKE) clean -C vm

fclean: clean
	$(MAKE) fclean -C ../libft
	$(MAKE) fclean -C asm
	$(MAKE) fclean -C vm

re: fclean all
