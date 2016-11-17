/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/17 17:44:42 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_recover_description(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strchr(env->file_content[i], '"');
	env->champ_comment = ft_strtrim_char(tmp, '"');
	if (ft_strlen(env->champ_comment) - 1 > COMMENT_LENGTH)
		ft_error_asm(env, CHAMP_COMMENT_TOO_LONG, 1);
}

void		ft_recover_name(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strchr(env->file_content[i], '"');
	env->champ_name = ft_strtrim_char(tmp, '"');
	if (ft_strlen(env->champ_name) - 1 > PROG_NAME_LENGTH)
		ft_error_asm(env, CHAMP_NAME_TOO_LONG, 1);
}

void		ft_recover_champ_infos(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strsub(env->file_content[i], 0, 5);
	if (EQU(tmp, NAME_CMD_STRING) == 1 && !env->champ_name)
	{
		ft_recover_name(env, i);
		ft_strdel(&tmp);
	}
	else
	{
		ft_strdel(&tmp);
		tmp = ft_strsub(env->file_content[i], 0, 8);
		if (EQU(tmp, COMMENT_CMD_STRING) == 1 && !env->champ_comment)
		{
			ft_strdel(&tmp);
			ft_recover_description(env, i);
		}
		else
		{
			ft_strdel(&tmp);
			ft_error_asm(env, BAD_SRC_FILE, 1);
		}
	}
}

void		ft_parse_file(t_asm *env)
{
	int		i;

	i = 0;
	while (env->file_content[i])
	{
		if (env->file_content[i][0] == '.')
			ft_recover_champ_infos(env, i);
		i++;
	}


	/*THIS PART IS HERE TO TEST : WILL PRINT IN THE test.cor FILE*/
	{
		int		fd;
		fd = open("test.cor", O_WRONLY, O_CREAT, 0600);
		write(fd, ft_transform_magic(), MAGIC_LEN);
		write(fd, ft_transform_champ_infos(env->champ_name, PROG_NAME_LENGTH), PROG_NAME_LENGTH);
		// write(fd, "\x00", 1);
		// write(fd, "\x00", 4);
		// write(fd, "\x00", 4);
		// write(fd, "\x00", 4);
		// write(fd, ft_transform_champ_infos(env->champ_comment, COMMENT_LENGTH), COMMENT_LENGTH);
	}
}
