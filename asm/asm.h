/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/16 14:21:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include <errno.h>

# define BAD_SRC_FILE "Can't read source file"
# define NO_DIR "Directories are not allowed"
# define NO_EXT "Extension .s is missing (NOEXT)"
# define EMPTY_FILE "File is empty"
# define CHAMP_NAME_TOO_LONG "Champion name too long (Max length 128)" // TODO NAME_LENGTH
# define CHAMP_COMMENT_TOO_LONG "Champion comment too long (Max length 2048)" // TODO COMMENT_LENGTH

typedef struct	s_asm
{
	t_options	*options;
	int			fd;

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

void			ft_error_asm(t_asm *env, char *msg, int err);

void			ft_parse_file(t_asm *env);

#endif
