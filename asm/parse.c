/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/15 18:34:00 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_recover_description(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strchr(env->file_content[i], '"');
	env->champ_comment = ft_strtrim_char(tmp, '"');
	tmp = NULL;
}

void		ft_recover_name(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strchr(env->file_content[i], '"');
	env->champ_name = ft_strtrim_char(tmp, '"');
	tmp = NULL;
}

void		ft_recover_champ_infos(t_asm *env, int i)
{
	char	*tmp;

	tmp = ft_strsub(env->file_content[i], 0, 5);
	if (EQU(tmp, ".name") == 1 && !env->champ_name)
		ft_recover_name(env, i);
	else
	{
		ft_strdel(&tmp);
		tmp = ft_strsub(env->file_content[i], 0, 8);
		if (EQU(tmp, ".comment") == 1 && !env->champ_comment)
			ft_recover_description(env, i);
	}
	ft_strdel(&tmp);
}

// void		ft_get_command(t_asm *env, int i)
// {
	// if ()
// }

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
}
