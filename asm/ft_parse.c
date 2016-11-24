/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/24 11:07:47 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_recover_comment(t_asm *env, char *line, int i, int j)
{
	while (line[i] && line[i] != '"')
	{
		if (ft_isspace(line[i]) == 0)
			ft_error_asm(env, ERR_SYNTAX_ERROR_BCOMMENT, 1);
		i++;
	}
	i++;
	j = i;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] != '"')
		ft_error_asm(env, ERR_NOCHAMP_COMMENT, 1);
	env->champ_comment = ft_strsub(line, j, i - j);
	if (ft_strlen(env->champ_comment) == 0)
		ft_error_asm(env, ERR_NOCHAMP_COMMENT, 1);
	else if (ft_strlen(env->champ_comment) > COMMENT_LENGTH)
		ft_error_asm(env, ERR_CHAMP_COMMENT_TOO_LONG, 1);
	i++;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			ft_error_asm(env, ERR_SYNTAX_ERROR_ACOMMENT, 1);
		i++;
	}
}

void		ft_recover_name(t_asm *env, char *line, int i, int j)
{
	while (line[i] && line[i] != '"')
	{
		if (ft_isspace(line[i]) == 0)
			ft_error_asm(env, ERR_SYNTAX_ERROR_BNAME, 1);
		i++;
	}
	i++;
	j = i;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] != '"')
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	env->champ_name = ft_strsub(line, j, i - j);
	if (ft_strlen(env->champ_name) == 0)
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	else if (ft_strlen(env->champ_name) > PROG_NAME_LENGTH)
		ft_error_asm(env, ERR_CHAMP_NAME_TOO_LONG, 1);
	i++;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
			ft_error_asm(env, ERR_SYNTAX_ERROR_ANAME, 1);
		i++;
	}
}

void		ft_recover_champ_infos(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strsub(env->file_content[i], 0, 5);
	if (EQU(tmp, NAME_CMD_STRING) == 1 && !env->champ_name)
	{
		ft_strdel(&tmp);
		ft_recover_name(env, env->file_content[i], 5, 0);
	}
	else
	{
		ft_strdel(&tmp);
		tmp = ft_strsub(env->file_content[i], 0, 8);
		if (EQU(tmp, COMMENT_CMD_STRING) == 1 && !env->champ_comment)
		{
			ft_strdel(&tmp);
			ft_recover_comment(env, env->file_content[i], 8, 0);
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

	ft_transform_size(env->instruct_size, fd);

	hex_string = ft_transform_champ_infos(env->champ_comment, COMMENT_LENGTH);
	write(fd, hex_string, COMMENT_LENGTH);
	ft_strdel(&hex_string);
}

void		ft_parse_file(t_asm *env)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (env->file_content[i])
	{
		if (cpt < 2)// && env->file_content[i][0] == '.')
		{
			ft_recover_champ_infos(env, i);
			cpt++;
		}
		else if (cpt >= 2 && ft_strchr(env->file_content[i], '.') == NULL)
			ft_get_size(env, i);
		else
			ft_error_asm(env, ERR_BAD_SRC_FILE, 1);
		i++;
	}
	if (ft_detect_errors(env) == 0)
		ft_put_data(env);
}
