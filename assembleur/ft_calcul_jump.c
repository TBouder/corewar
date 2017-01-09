/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_jump.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:53:19 by quroulon          #+#    #+#             */
/*   Updated: 2016/12/02 18:58:21 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static long		ft_calcul_jump_helper(t_asm *env, int line, int match, int pds)
{
	int			cpt;

	cpt = 0;
	line--;
	while (line > match)
	{
		cpt += env->instruct_weight[line];
		line--;
	}
	if (pds == 2)
		cpt = (cpt != 0) ? (USHRT_MAX + 1) - cpt : 0;
	else if (pds == 4)
		cpt = (cpt != 0) ? (UINT_MAX + 1) - cpt : 0;
	return (cpt);
}

long			ft_calcul_jump(t_asm *env, char *str, int line, int pds)
{
	long		cpt;
	int			match;
	char		*label;

	cpt = 0;
	match = -1;
	label = ft_strjoin(str, ":");
	ft_btreesearch_asm(env->file_labels, label, &match);
	if (match > 0 && line < match)
	{
		while (line < match)
		{
			cpt += env->instruct_weight[line];
			line++;
		}
	}
	else if (match > 0 && line > match)
		cpt = ft_calcul_jump_helper(env, line, match, pds);
	ft_strdel(&label);
	return (cpt);
}
