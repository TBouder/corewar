/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/15 16:53:16 by tbouder          ###   ########.fr       */
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

void		ft_parse_file(t_asm *env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (env->file_content[i])
	{
		if (EQU(ft_strsub(env->file_content[i], 0, 5), ".name"))
			ft_printf("{10}NAME{0}\n");
		if (EQU(ft_strsub(env->file_content[i], 0, 8), ".comment"))
			ft_printf("{10}COMMENT{0}\n");

		// if (env->file_content[i][0] == '.')
		// {
		// 	tmp = ft_strsub(env->file_content[i], 0, 5);
		// 	if (ft_strequ(tmp, ".name") == 1 && !env->champ_name)
		//
		// 		ft_recover_name(env, i);
		// 	else// if ()
		// 	{
		// 		tmp = ft_strsub(env->file_content[i], 0, 8);
		// 		if (ft_strequ(tmp, ".comment") == 1 && !env->champ_comment)
		// 			ft_recover_description(env, i);
		// 	}
		// 	// else
		// 	ft_strdel(&tmp);
		//
		// }
		i++;
	}
}
