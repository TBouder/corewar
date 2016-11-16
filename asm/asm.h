/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 18:38:33 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include <errno.h>

# define BAD_SRC_FILE "Can't read source file"
# define NO_DIR "Directories are not allowed"
# define NO_EXT "Extension .s is missing (NOEXT)"
# define EMPTY_FILE "File is empty"

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
}				t_asm;

/*
** ft_asm_func.c
*/
int				ft_strlen_asm(char *str);
char			*ft_strinit_asm(char *str);

void			ft_error_asm(t_asm *env, char *msg, int err);

void			ft_parse_file(t_asm *env);

#endif
