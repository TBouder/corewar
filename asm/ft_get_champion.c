/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:27:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 12:33:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_get_comment(t_asm *env, char *line, int i, int j)
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

static void		ft_get_name(t_asm *env, char *line, int i, int j)
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

void			ft_get_champ_infos(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strsub(env->file_content[i], 0, 5);
	if (EQU(tmp, NAME_CMD_STRING) == 1 && !env->champ_name)
	{
		ft_strdel(&tmp);
		ft_get_name(env, env->file_content[i], 5, 0);
	}
	else
	{
		ft_strdel(&tmp);
		tmp = ft_strsub(env->file_content[i], 0, 8);
		if (EQU(tmp, COMMENT_CMD_STRING) == 1 && !env->champ_comment)
		{
			ft_strdel(&tmp);
			ft_get_comment(env, env->file_content[i], 8, 0);
		}
		else
		{
			ft_strdel(&tmp);
			ft_error_asm(env, ERR_BAD_SRC_FILE, 1);
		}
	}
}
