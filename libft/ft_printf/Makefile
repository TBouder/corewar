# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:48:47 by tbouder           #+#    #+#              #
#    Updated: 2016/08/23 00:25:08 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

HEADER 		=	ft_printf.h ../libft.h
PRINTF 		= 	ft_printf.c
PRINTF_CONV	= 	$(wildcard ft_conv/*.c)
PRINTF_FUNC	= 	$(wildcard ft_funcs/*.c)
PRINTF_COL	= 	$(wildcard ft_colors/*.c)
FT_IS		= 	$(wildcard ../libft/ft_is/*.c)
FT_LEN		= 	$(wildcard ../libft/ft_len/*.c)
FT_LST		= 	$(wildcard ../libft/ft_lst/*.c)
FT_MEM		= 	$(wildcard ../libft/ft_mem/*.c)
FT_NB		= 	$(wildcard ../libft/ft_nb/*.c)
FT_PRINT	= 	$(wildcard ../libft/ft_print/*.c)
FT_DBSTR	= 	$(wildcard ../libft/ft_dbstr/*.c)
FT_STR		= 	$(wildcard ../libft/ft_str/*.c)
FT_MATH		= 	$(wildcard ../libft/ft_math/*.c)
FT_HASH		= 	$(wildcard ../libft/ft_hash/*.c)
GNL			= 	$(wildcard ../libft/get_next_line/*.c)

SRC			=	$(FT_IS) $(FT_LEN) $(FT_LST) $(FT_MEM) $(FT_NB) $(FT_PRINT) \
				$(FT_STR) $(FT_DBSTR) $(FT_MATH) $(FT_HASH) $(GNL) $(PRINTF) $(PRINTF_CONV) $(PRINTF_FUNC) $(PRINTF_COL)
OBJ			=	$(notdir $(SRC:.c=.o))
OBJ			=	$(patsubst %.c,%.o, $(SRC))
JUNCK		=	$(wildcard *.gch .DS_Store */.DS_Store)


all: $(NAME)

.SILENT : $(NAME) $(OBJ)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.SILENT : clean
clean:
	rm -f $(notdir $(OBJ)) $(OBJ) $(JUNCK)

.SILENT : fclean
fclean: clean
	rm -f $(NAME)

re: fclean all
