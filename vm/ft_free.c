/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/22 13:07:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_del_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
}
//
// void			ft_clear_champ(t_vm *env, int id)
// {
// 	t_list		*tmp;
// 	t_list		*to_del;
// 	t_list		*prev;
// 	t_champions	*champ;
//
// 	tmp = env->list_champions;
// 	while (tmp)
// 	{
// 		champ = ((t_champions *)tmp->content);
// 		if (champ->champ_id == id)
// 		{
// 			to_del = tmp;
// 			tmp = tmp->next;
// 			if (to_del == env->list_champions)
// 				env->list_champions = to_del->next;
// 			else
// 				prev->next = to_del->next;
//
// 			ft_verbose_dead(env, champ);
// 			ft_del_champ(((t_champions *)to_del->content));
// 			free(to_del->content);
// 			to_del->content = NULL;
// 			free(to_del);
// 			to_del = NULL;
// 		}
// 		else
// 		{
// 			tmp = tmp->next;
// 			prev = tmp;
// 		}
// 	}
// }

void			ft_clear_champ(t_list **blist, int id)
{
	t_list	*current;
	t_list	*prev;

	current = *blist;
	prev = NULL;
	while (current)
	{
		if (((t_champions *)current->content)->champ_id == id)
		{
			if (prev == NULL)
				*blist = current->next;
			else
				prev->next = current->next;
			ft_del_champ((t_champions *)current->content);
			free(current->content);
			free(current);
			current = *blist;
		}
		prev = current;
		current = current->next;
	}
}

void			ft_clear_all(t_vm *env)
{
	ft_dbstrdel(env->filename);
	ft_strdel(&env->map);
	free(env->header);
	free(env->fd);
}

void			ft_error_vm(t_vm *env, char *msg, int clear)
{
	ft_printf("{9}%s{0}\n", msg);
	if (clear == 1)
		ft_clear_all(env);
	free(env->options);
	exit(1);
}
