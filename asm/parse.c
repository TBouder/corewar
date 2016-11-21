/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/21 15:39:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_recover_description(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strchr(env->file_content[i], '"');
	env->champ_comment = ft_strtrim_char(tmp, '"');
	if (ft_strlen(env->champ_comment) - 1 > COMMENT_LENGTH)
		ft_error_asm(env, ERR_CHAMP_COMMENT_TOO_LONG, 1);
}

void		ft_recover_name(t_asm *env, int i)
{
	char	*tmp;
	int		nb_quote;

	tmp = ft_strchr(env->file_content[i], '"');
	if (!tmp || (nb_quote = ft_strcountchar(tmp, '"')) != 2 || (nb_quote == 2 && ft_strlen(tmp) == 2))
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	env->champ_name = ft_strtrim_char(tmp, '"');
	if (ft_strlen(env->champ_name) - 1 > PROG_NAME_LENGTH)
		ft_error_asm(env, ERR_CHAMP_NAME_TOO_LONG, 1);
}

void		ft_recover_champ_infos(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strsub(env->file_content[i], 0, 5);
	if (EQU(tmp, NAME_CMD_STRING) == 1 && !env->champ_name)
	{
		ft_strdel(&tmp);
		ft_recover_name(env, i);
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
			ft_error_asm(env, ERR_BAD_SRC_FILE, 1);
		}
	}
}

int			ft_detect_errors(t_asm *env)
{
	if (!env->champ_name)
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	else if (!env->champ_comment)
		return (1); //ERROR NO CHAMP COMMENT
	return (0);
}

void		ft_put_data(t_asm *env)
{
	int		fd;
	char	*hex_string;

	fd = open("test.cor", O_WRONLY, O_CREAT, 0600);

	hex_string = ft_transform_magic();
	write(fd, hex_string, MAGIC_LEN);
	ft_strdel(&hex_string);

	hex_string = ft_transform_champ_infos(env->champ_name, PROG_NAME_LENGTH);
	write(fd, hex_string, PROG_NAME_LENGTH);
	ft_strdel(&hex_string);

	ft_printf("[{10}%d{0}]\n", env->instruct_size);
	ft_transform_size(env->instruct_size, fd);

	hex_string = ft_transform_champ_infos(env->champ_comment, COMMENT_LENGTH);
	write(fd, hex_string, COMMENT_LENGTH);
	ft_strdel(&hex_string);
}

void		ft_parse_file(t_asm *env)
{
	int		i;

	i = 0;
	while (env->file_content[i])
	{
		if (env->file_content[i][0] == '.')
			ft_recover_champ_infos(env, i);
		else
			ft_get_size(env, i);
		i++;
	}
	if (ft_detect_errors(env) == 0)
		ft_put_data(env);
}
