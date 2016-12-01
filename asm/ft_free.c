/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:02:26 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/01 15:42:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_dbnbrdel(int **nbr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size && nbr && nbr[i])
	{
		free(nbr[i]);
		i++;
	}
	free(nbr);
}

void	ft_trpstrdel(char ***str, int size)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (i < size)
	{
		ft_dbstrdel(str[i]);
		i++;
	}
	free(str);
}

void	ft_clear_all(t_asm *env)
{
	ft_trpstrdel(env->args, env->file_len);
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_new);
	ft_strdel(&env->filename_noext);
	ft_strdel(&env->champ_name);
	ft_strdel(&env->champ_comment);
	ft_btreedel_asm(env->file_labels);
	ft_strdel(&env->error_val);
	ft_dbstrdel(env->opcode_next);
	ft_dbnbrdel(env->arg_weight, env->file_len);
	free(env->instruct_weight);
	ft_strdel(&env->filename_new);
}
