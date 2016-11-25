/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/25 16:13:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include "errors.h"

# define	MAGIC_LEN 4
# define	TMP_SIZE 77

typedef struct	s_asm
{
	t_options	*options;
	int			fd;
	int			fd_cor;

	char		*error_val;
	int			error_int;

	char		*filename;
	char		*filename_noext;
	char		*filename_new;

	char		*champ_name;
	char		*champ_comment;
	int			instruct_size;

	char		**file_content;
	int			line_nb;

	t_btree		*file_labels;
	int			*instruct_weight;
	char		**args;
	int			file_len;
	// t_op		op_tab[17];
}				t_asm;

/*
** ft_asm_func.c
*/
int				ft_strlen_asm(char *str);
char			*ft_strinit_asm(char *str);

/*
** main.c
*/
void			ft_error_asm(t_asm *env, char *msg, int err);

/*
** ft_init.c
*/
void			ft_init_env(t_asm *env);
void			ft_init_function_tab(int (*tab[17])());

/*
** fr_free.c
*/
void			ft_clear_all(t_asm *env);

/*
** ft_verif.c
*/
char			ft_verif_extension(t_asm *env, char *source);
int				ft_verif_label(t_asm *env, char *str);



/*
** GET : ft_get_champion.c, ft_get_file.c, ft_get_size.c
*/
void			ft_get_champ_infos(t_asm *env, int i);
void			ft_get_file_content(t_asm *env);
void			ft_get_size(t_asm *env, int i);
int				ft_get_opcode(char *opname);

/*
** parse.c
*/
void			ft_parse_file(t_asm *env);
void			ft_recover_comment(t_asm *env, char *line, int i, int j);
void			ft_recover_name(t_asm *env, char *line, int i, int j);

/*
** ft_transform_hex.c
*/
char			*ft_transform_magic(void);
char			*ft_transform_champ_infos(char *content, size_t content_size);
void			ft_transform_size(int content, int fd);


/*
** ft_tools.c
*/
char			**ft_split_args(char const *s, char c);
char			**ft_split_instruct(char const *s, char c);

/*
** ft_opweight_part{1..2}.c
*/
int				ft_get_line_weight(t_asm *env, int opcode, int value, int ret);
int				ft_opweight_1(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_2(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_3(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_4_5(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_6_7_8(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_9_12_15(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_10_14(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_11(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_13(t_asm *env, char *arg1, char *arg2, char *arg3);
int				ft_opweight_16(t_asm *env, char *arg1, char *arg2, char *arg3);


#endif
