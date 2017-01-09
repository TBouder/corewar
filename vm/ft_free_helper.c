/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 09:11:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_del_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
}

static void		ft_clear_champ_helper(t_vm *env, t_list *current)
{
	((t_champions *)current->content)->alive = 0;
	((t_champions *)current->content)->pc = -1;
	env->nb_forks -= 1;
}

void			ft_clear_champ(t_vm *env, t_list **blist, int id)
{
	t_list	*current;
	t_list	*prev;

	current = *blist;
	prev = NULL;
	while (current)
	{
		if (((t_champions *)current->content)->champ_id == id)
			ft_clear_champ_helper(env, current);
		else if (((t_champions *)current->content)->champ_id == id)
		{
			if (prev == NULL)
				*blist = current->next;
			else
				prev->next = current->next;
			ft_del_champ((t_champions *)current->content);
			free(current->content);
			free(current);
			env->nb_forks -= 1;
			if (!(current = *blist))
				break ;
		}
		prev = current;
		current = current->next;
	}
}
