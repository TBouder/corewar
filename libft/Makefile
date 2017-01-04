# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/05 20:24:05 by tbouder           #+#    #+#              #
#    Updated: 2017/01/03 16:44:15 by tbouder          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g
OCLINT		=	oclint
OFLAGS		=	-enable-global-analysis -rc SHORT_VARIABLE_NAME=1 \
				-rc LONG_LINE=80 -rc CYCLOMATIC_COMPLEXITY=25 -disable-rule \
				UselessParentheses -disable-rule ParameterReassignment
HEADER 		= 	libft.h get_next_line/get_next_line.h ft_printf/ft_printf.h

################################################################################
#	LIBFT
################################################################################
FT_IS		= 	ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c \
				ft_is/ft_isdigit.c ft_is/ft_ishexa.c ft_is/ft_isnumber.c \
				ft_is/ft_isprime.c ft_is/ft_isprint.c ft_is/ft_isspace.c \
				ft_is/ft_isstrnum.c ft_is/ft_isstrstr.c

FT_LEN		= 	ft_len/ft_dbstrlen.c ft_len/ft_hexalen.c ft_len/ft_linelen.c \
				ft_len/ft_nbrlen.c ft_len/ft_nbrlen_base.c ft_len/ft_strlen.c

FT_LST		= 	ft_lst/ft_lstadd.c ft_lst/ft_lstclr.c ft_lst/ft_lstcontentsize.c \
				ft_lst/ft_lstdel.c ft_lst/ft_lstdelone.c ft_lst/ft_lstend.c \
				ft_lst/ft_lstinsert.c ft_lst/ft_lstiter.c ft_lst/ft_lstlen.c \
				ft_lst/ft_lstmap.c ft_lst/ft_lstnew.c ft_lst/ft_lstprint.c \
				ft_lst/ft_lststart.c ft_lst/ft_lsttostr.c

FT_MEM		= 	ft_mem/ft_bzero.c ft_mem/ft_memalloc.c ft_mem/ft_memccpy.c \
				ft_mem/ft_memchr.c ft_mem/ft_memcmp.c ft_mem/ft_memcpy.c \
				ft_mem/ft_memdel.c ft_mem/ft_memmove.c ft_mem/ft_memset.c \
				ft_mem/ft_print_memory.c ft_mem/ft_realloc.c

FT_NB		= 	ft_nb/ft_atoi.c ft_nb/ft_atoi_base.c ft_nb/ft_atoi_hexa.c \
				ft_nb/ft_atoi_l.c ft_nb/ft_atoi_part.c ft_nb/ft_nbrcmp.c \
				ft_nb/ft_nbrlargest.c ft_nb/ft_nbrnew.c ft_nb/ft_nbrsmallest.c \
				ft_nb/ft_next_prime.c

FT_PUT		= 	ft_put/ft_nbrendl.c ft_put/ft_put_endl.c ft_put/ft_putcendl.c \
				ft_put/ft_putchar.c ft_put/ft_putchar_fd.c ft_put/ft_putendl_fd.c \
				ft_put/ft_putnbr.c ft_put/ft_putnbr_base.c ft_put/ft_putnbr_fd.c \
				ft_put/ft_putstr.c ft_put/ft_putstr_fd.c

FT_STR		= 	ft_str/ft_extract_options.c ft_str/ft_itoa.c ft_str/ft_itoa_base.c \
				ft_str/ft_itox.c ft_str/ft_strcat.c ft_str/ft_strchr.c ft_str/ft_strclr.c \
				ft_str/ft_strcmp.c ft_str/ft_strcountchar.c ft_str/ft_strcpy.c \
				ft_str/ft_strdel.c ft_str/ft_strdup.c ft_str/ft_strequ.c \
				ft_str/ft_strinit.c ft_str/ft_striter.c ft_str/ft_striteri.c \
				ft_str/ft_strjoin.c ft_str/ft_strlcat.c ft_str/ft_strmap.c \
				ft_str/ft_strmapi.c ft_str/ft_strncat.c ft_str/ft_strncmp.c \
				ft_str/ft_strncpy.c ft_str/ft_strnequ.c ft_str/ft_strnew.c \
				ft_str/ft_strnew_hex.c ft_str/ft_strnjoin.c ft_str/ft_strnstr.c \
				ft_str/ft_strrchr.c ft_str/ft_strsplit.c ft_str/ft_strstr.c \
				ft_str/ft_strsub.c ft_str/ft_strtrim.c ft_str/ft_strtrim_char.c \
				ft_str/ft_tolower.c ft_str/ft_toupper.c

FT_DBSTR	= 	ft_dbstr/ft_dbstrassign.c ft_dbstr/ft_dbstrdel.c \
				ft_dbstr/ft_dbstrnew.c ft_dbstr/ft_putdbstr.c

FT_MATH		= 	ft_math/ft_cos.c ft_math/ft_factorial.c ft_math/ft_fibonacci.c \
				ft_math/ft_pgcd.c ft_math/ft_power.c ft_math/ft_rand.c ft_math/ft_sin.c \
				ft_math/ft_sqrt.c ft_math/ft_tan.c

FT_HASH		= 	ft_hash/ft_hash_adler_thirtytwo.c ft_hash/ft_hash_djbtwo.c \
				ft_hash/ft_hash_little.c ft_hash/ft_hash_sdbm.c ft_hash/ft_hash_superfast.c

FT_BTREE	= 	ft_btree/ft_btree_print_inorder.c ft_btree/ft_btree_print_postorder.c \
				ft_btree/ft_btree_print_preorder.c ft_btree/ft_btreecmp.c \
				ft_btree/ft_btreecmp_rev.c ft_btree/ft_btreedel.c ft_btree/ft_btreenew.c \
				ft_btree/ft_btreesearch.c

FT_OVER		= 	ft_overload/ft_put.c ft_overload/ft_put_fd.c ft_overload/ft_putendl.c

LIBFT		=	$(FT_IS) $(FT_LEN) $(FT_LST) $(FT_MEM) $(FT_NB) $(FT_PUT) \
				$(FT_STR) $(FT_DBSTR) $(FT_MATH) $(FT_HASH) $(FT_BTREE) $(FT_OVER)

################################################################################
#	GET_NEXT_LINE
################################################################################
GET			= 	get_next_line/get_next_line.c
GNL			=	$(GET)

################################################################################
#	FT_PRINTF
################################################################################
PRINTF		= 	ft_printf/ft_printf.c

PRINTF_CONV	= 	ft_printf/ft_conv/ft_conv_b.c ft_printf/ft_conv/ft_conv_c.c \
				ft_printf/ft_conv/ft_conv_char_0.c ft_printf/ft_conv/ft_conv_d_i.c \
				ft_printf/ft_conv/ft_conv_f.c ft_printf/ft_conv/ft_conv_flt_0.c \
				ft_printf/ft_conv/ft_conv_hex_0.c ft_printf/ft_conv/ft_conv_hex_1.c \
				ft_printf/ft_conv/ft_conv_int_0.c ft_printf/ft_conv/ft_conv_int_1.c \
				ft_printf/ft_conv/ft_conv_o.c ft_printf/ft_conv/ft_conv_oct_0.c \
				ft_printf/ft_conv/ft_conv_oct_1.c ft_printf/ft_conv/ft_conv_p.c \
				ft_printf/ft_conv/ft_conv_percent.c ft_printf/ft_conv/ft_conv_s.c \
				ft_printf/ft_conv/ft_conv_str_0.c ft_printf/ft_conv/ft_conv_u.c \
				ft_printf/ft_conv/ft_conv_uni_0.c ft_printf/ft_conv/ft_conv_uni_1.c \
				ft_printf/ft_conv/ft_conv_wstr.c ft_printf/ft_conv/ft_conv_x.c

PRINTF_FUNC	= 	ft_printf/ft_funcs/ft_flags_0.c ft_printf/ft_funcs/ft_flags_1.c \
				ft_printf/ft_funcs/ft_printf_conv.c ft_printf/ft_funcs/ft_tools_binary.c \
				ft_printf/ft_funcs/ft_tools_itoa.c ft_printf/ft_funcs/ft_tools_nbr.c \
				ft_printf/ft_funcs/ft_tools_wchar.c

PRINTF_COL	= 	ft_printf/ft_colors/ft_colors.c
FT_PRINTF	=	$(PRINTF) $(PRINTF_CONV) $(PRINTF_FUNC) $(PRINTF_COL)

SRC			=	$(LIBFT) $(GET) $(FT_PRINTF)
OBJ			=	$(notdir $(SRC:.c=.o))


################################################################################
#	RULES
################################################################################
.SILENT : $(NAME) clean fclean oclint

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

list:
	ar t $(NAME)

oclint:
	$(OCLINT) $(OFLAGS) $(LIBFT) $(GET) $(FT_PRINTF) $(HEADER) -- c
