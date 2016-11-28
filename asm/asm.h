/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/28 19:41:51 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include "errors.h"

# define	MAGIC_LEN 4

typedef struct		s_asm
{
	t_options		*options;			//Flags
	int				fd;					//FD
	int				fd_cor;				//FD pour le fichier final

	char			*error_val;			//Contenu de l'erreur a afficher
	int				error_int;			//Valeur de l'errur

	char			*filename;			//Nom du fichier
	char			*filename_noext;	//Nom du fichier sans extension
	char			*filename_new;		//Nom du fichier avec l'ext .cor

	char			*champ_name;		//Nom du champion
	char			*champ_comment;		//Comment du champion
	int				instruct_size;		//Taille totale du fichier

	char			**file_content;		//Toutes les lignes valides
	int				file_len;			//Nombre de ligne du fichier
	int				line_nb;			//Ligne courante

	t_btree			*file_labels;		//Liste de tous les labels custom
	char			**opcode_next;		//Machin apres l'opcode
	int				**arg_weight;		//Poids de chaque arg de chaque ligne

	char			**args;				//Buffer temp pour les args (norme)
	int				opcode;				//Buffer temp pour les poids (norme)
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
** ft_init.c
*/
void				ft_init_env(t_asm *env);
void				ft_init_function_tab(int (*tab[17])());

/*
** fr_free.c
*/
void				ft_clear_all(t_asm *env);

/*
** ft_verif.c
*/
char				ft_verif_extension(t_asm *env, char *source);
int					ft_verif_label(t_asm *env, char *str);

/*
** GET : ft_get_champion.c, ft_get_file.c, ft_get_size.c
*/
void				ft_get_champ_infos(t_asm *env, int i);
void				ft_get_file_content(t_asm *env);
void				ft_get_size(t_asm *env, int i);
int					ft_get_opcode(char *opname);

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
char				*ft_transform_size_helper(int content, size_t content_size);

/*
** ft_write_instructions.c
*/
void				ft_write_instructions(t_asm *env);

/*
** ft_tools.c
*/
char				**ft_split_args(char const *s, char c);
char				**ft_split_instruct(char const *s, char c);

/*
** ft_opweight_part{1..2}.c
*/
int					ft_get_line_weight(t_asm *env, int value, int ret, int pos);
int					ft_opweight_1(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_2(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_3(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_4_5(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_6_7_8(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_9_12_15(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_10_14(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_11(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_13(t_asm *env, char *arg1, char *arg2, char *arg3);
int					ft_opweight_16(t_asm *env, char *arg1, char *arg2, char *arg3);

#endif
