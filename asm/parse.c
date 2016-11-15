/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/15 16:51:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_parse_file(t_asm *env)
{
	int		i;

	i = 0;
	while (env->file_content[i])
	{
		if (EQU(ft_strsub(env->file_content[i], 0, 5), ".name"))
			ft_printf("{10}NAME{0}\n");
		if (EQU(ft_strsub(env->file_content[i], 0, 8), ".comment"))
			ft_printf("{10}COMMENT{0}\n");

		// if (ft_strchr(env->file_content[i], '.'))
		// 	ft_printf("{9}parse{0}\n");
		i++;
	}
}
