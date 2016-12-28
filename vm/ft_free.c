/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/28 23:02:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_del_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
}

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
		if (!current)
			break ;
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
