/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 19:07:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include "errors.h"

# define	MAGIC_LEN 4
# define	TMP_SIZE 77

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm
{
	t_options		*options;
	int				fd;
	int				fd_cor;

	char			*error_val;
	int				error_int;

	char			*filename;
	char			*filename_noext;
	char			*champ_name;
	char			*champ_comment;
	int				instruct_size;

	char			**file_content;
	t_btree			*file_labels;
	int				file_len;
	// t_op			op_tab[17];

	t_label			**hash;
}					t_asm;

/*
** ft_asm_func.c
*/
int					ft_strlen_asm(char *str);
char				*ft_strinit_asm(char *str);

/*
** main.c
*/
void				ft_error_asm(t_asm *env, char *msg, int err);

/*
** ft_get_file.c
*/
void				ft_get_file_content(t_asm *env);

/*
** parse.c
*/
void				ft_parse_file(t_asm *env);
void				ft_recover_comment(t_asm *env, char *line, int i, int j);
void				ft_recover_name(t_asm *env, char *line, int i, int j);

/*
** ft_transform_hex.c
*/
char				*ft_transform_magic(void);
char				*ft_transform_champ_infos(char *content, size_t content_size);
void				ft_transform_size(int content, int fd);

/*
** ft_get_size.c
*/
void				ft_get_size(t_asm *env, int i);
int					ft_verif_label(char *str);
int					ft_get_opcode(char *opname);

/*
** ft_tools.c
*/
char				**ft_split_args(char const *s, char c);
char				**ft_split_instruct(char const *s, char c);

/*
** ft_opweight_part{1..2}.c
*/
int					ft_opweight_1(char *arg1, char *arg2, char *arg3);
int					ft_opweight_2(char *arg1, char *arg2, char *arg3);
int					ft_opweight_3(char *arg1, char *arg2, char *arg3);
int					ft_opweight_4_5(char *arg1, char *arg2, char *arg3);
int					ft_opweight_6_7_8(char *arg1, char *arg2, char *arg3);
int					ft_opweight_9_12_15(char *arg1, char *arg2, char *arg3);
int					ft_opweight_10_14(char *arg1, char *arg2, char *arg3);
int					ft_opweight_11(char *arg1, char *arg2, char *arg3);
int					ft_opweight_13(char *arg1, char *arg2, char *arg3);
int					ft_opweight_16(char *arg1, char *arg2, char *arg3);


#endif
