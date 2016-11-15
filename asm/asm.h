/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:02:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 14:39:49 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include <errno.h>

typedef struct		s_asm
{
	t_options		*options;
	int				fd;

	char			*filename;
	char			*filename_noext;
	char			*champ_name;
	char			*champ_comment;

	char			**file_content;
	int				file_len;
}					t_asm;

void				ft_parse_file(t_asm *env);

#endif
