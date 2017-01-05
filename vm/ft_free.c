/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 16:38:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_del_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
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
		{
			((t_champions *)current->content)->alive = 0;
			((t_champions *)current->content)->pc = -1;
			env->nb_forks -= 1;
		}
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

void			ft_clear_all_champs(t_list **begin_list)
{
	t_list	*free_list;
	t_list	*temp;

	if (begin_list != NULL)
	{
		free_list = *begin_list;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			temp->content_size = 0;
			ft_del_champ((t_champions *)temp->content);
			free(temp->content);
			temp->content = NULL;
			free(temp);
		}
		*begin_list = NULL;
	}
}

void			ft_clear_all(t_vm *env)
{
	ft_lstclr(&env->champs);
	ft_dbstrdel(env->filename);
	ft_strdel(&env->map);
	free(env->map_owner);
	free(env->map_moves);
	free(env->header);
	free(env->fd);
	ft_clear_all_champs(&env->list_champions);
	free(env->list_champions);
	ft_strdel(&env->winner->name);
	free(env->winner);
	IS_GRAPH ? ft_clear_ncurse(env) : 0;
}

void			ft_error_vm(t_vm *env, char *msg, int clear)
{
	ft_printf("{9}%s{0}\n", msg);
	if (clear == 1)
		ft_clear_all(env);
	free(env->options);
	free(env->fake_id);
	exit(1);
}
