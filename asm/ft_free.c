/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:02:26 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/01 13:44:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_dbnbrdel(int **nbr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		free(nbr[i]);
		i++;
	}
	free(nbr);
}

void	ft_clear_all(t_asm *env)
{
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_new);
	ft_strdel(&env->filename_noext);
	ft_strdel(&env->champ_name);
	ft_strdel(&env->champ_comment);
	ft_btreedel_asm(env->file_labels);
	ft_strdel(&env->error_val);
	ft_dbstrdel(env->args);
	ft_dbstrdel(env->opcode_next);
	ft_dbnbrdel(env->arg_weight, env->file_len);
	free(env->instruct_weight);
}
