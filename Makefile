# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/09 09:28:30 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

export		CC		=	gcc
export		CFLAGS	=	-Wall -Werror -Wextra

ASM_DIR		=	assembleur/
VM_DIR		=	vm/
LIBFT_DIR	=	libft/

ASM_EXEC	=	asm
VM_EXEC		=	corewar

################################################################################
#	RULES
################################################################################

.PHONY: all libft asm vm clean fclean re

all: libft asm vm

libft:
	@$(MAKE) -C $(LIBFT_DIR)

asm:
	@$(MAKE) -C $(ASM_DIR)
	@cp $(ASM_DIR)$(ASM_EXEC) .

vm:
	@$(MAKE) -C $(VM_DIR)
	@cp $(VM_DIR)$(VM_EXEC) .



clean: clean_libft clean_asm clean_vm

clean_libft:
	@$(MAKE) clean -C $(LIBFT_DIR)

clean_asm:
	@$(MAKE) clean -C $(ASM_DIR)

clean_vm:
	@$(MAKE) clean -C $(VM_DIR)



fclean: fclean_libft fclean_asm fclean_vm

fclean_libft:
	@$(MAKE) fclean -C $(LIBFT_DIR)

fclean_asm:
	@$(MAKE) fclean -C $(ASM_DIR)
	@rm -f $(ASM_DIR)$(ASM_EXEC)

fclean_vm:
	@$(MAKE) fclean -C $(VM_DIR)
	@rm -f $(VM_EXEC)

re: fclean all
