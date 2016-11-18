/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/18 15:19:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include "errors.h"

# define	MAGIC_LEN 4
# define	TMP_SIZE 77
// # define	TMP_SIZE 1080
// # define	TMP_SIZE 4320
// # define	TMP_SIZE 316536
// # define	TMP_SIZE 5064589
// # define	TMP_SIZE 81033438

typedef struct	s_asm
{
	t_options	*options;
	int			fd;
	int			fd_cor;

	char		*filename;
	char		*filename_noext;
	char		*champ_name;
	char		*champ_comment;

	char		**file_content;
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
** parse.c
*/
void			ft_parse_file(t_asm *env);

/*
** ft_transform_hex.c
*/
char			*ft_transform_magic(void);
char			*ft_transform_champ_infos(char *content, size_t content_size);
void			ft_transform_size(int content, int fd);

/*
** ft_get_size.c
*/
void			ft_get_size(t_asm *env, int i);


#endif
