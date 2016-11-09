# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2016/11/09 17:17:21 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME 		= 	asm
#
# CC			= 	gcc
# CFLAGS		= 	-Wall -Werror -Wextra
#
# LIB			=	../libft/libft.a
#
# HEADER 		=	asm.h

################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean

all: $(NAME)

$(NAME):
	# $(MAKE) -C ../libft
	$(MAKE) -C asm

clean:
	# $(MAKE) clean -C ../libft
	$(MAKE) clean -C asm

fclean: clean
	# $(MAKE) fclean -C ../libft
	$(MAKE) fclean -C asm

re: fclean all
