/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/11 09:22:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include "errors.h"

# define MAGIC_LEN 4
# define U_INT unsigned int

typedef struct			s_btree_asm
{
	void				*content;
	size_t				content_size;
	int					line;
	struct s_btree_asm	*left;
	struct s_btree_asm	*right;
}						t_btree_asm;

typedef struct			s_asm
{
	t_options			*options;
	int					fd;
	int					fd_cor;

	char				*error_val;
	int					error_int;

	char				*filename;
	char				*filename_noext;
	char				*filename_new;

	char				*champ_name;
	char				*champ_comment;
	int					instruct_size;

	char				**file_content;
	int					file_len;
	int					line_nb;

	t_btree_asm			*file_labels;
	char				**opcode_next;
	int					*instruct_weight;
	int					**arg_weight;

	char				***args;
	int					opcode;
}						t_asm;

/*
** main.c
*/
void					ft_error_asm(t_asm *env, char *msg, int err);

/*
** ft_init.c
*/
void					ft_init_env(t_asm *env);
void					ft_init_parse(t_asm *env);
void					ft_init_function_tab(int (*tab[17])());

/*
** fr_free.c
*/
void					ft_clear_all(t_asm *env);

/*
** ft_verif.c
*/
char					ft_verif_extension(t_asm *env, char *source);
int						ft_verif_label(t_asm *env, char *str);

/*
** ft_btree_asm.c
*/
void					ft_btreecmp_asm(t_asm *env, t_btree_asm **tree,
							void const *content, size_t c_size);
void					ft_btree_print_inorder_asm(t_btree_asm *node);
void					ft_btreedel_asm(t_btree_asm *tree);
void					ft_btreesearch_asm(t_btree_asm *node, char *content,
							int *ret);

/*
** ft_calcul_jump.c
*/
long					ft_calcul_jump(t_asm *env, char *str, int line,
										int pds);

/*
** ft_valid_file.c
*/
int						ft_valid_label(char *str);
int						ft_valid_spaces(char *str);
void					ft_verif_valid_spaces_fail(t_asm *env, char *str);

/*
** GET : ft_get_champion.c, ft_get_file.c, ft_get_size.c
*/
void					ft_get_champ_infos(t_asm *env, int i);
void					ft_get_file_content(t_asm *env);
void					ft_get_size(t_asm *env, int i);
int						ft_get_opcode(char *opname);
int						ft_get_weight(t_asm *env, int value, int ret, int pos);
void					ft_get_opweight(t_asm *env, int opcode);

/*
** parse.c
*/
void					ft_parse_file(t_asm *env);

/*
** ft_transform_hex.c
*/
char					*ft_transform_magic(int i);
char					*ft_transform_champ_infos(char *content,
							size_t content_size);
void					ft_edit_size(unsigned int content, int fd,
											int len);

/*
** ft_write_instructions.c
*/
void					ft_write_instructions(t_asm *env);

/*
** ft_tools.c
*/
char					**ft_split_args(char const *s, char c, int size);
char					**ft_split_instruct(char const *s, char c);
void					ft_strreplace_space(char *str);
char					*ft_remove_end(char *str);

/*
** ft_opweight_part{1..2}.c
*/
int						ft_opweight_1(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_2(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_3(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_4_5(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_6_7_8(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_9_12_15(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_10_14(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_11(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_13(t_asm *env, char *arg1, char *arg2,
							char *arg3);
int						ft_opweight_16(t_asm *env, char *arg1, char *arg2,
							char *arg3);

#endif
