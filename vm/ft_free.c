/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 21:10:05 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_del_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
}

void			ft_clear_champ(t_vm *env, int id)
{
	t_list		*tmp;
	t_list		*prev;
	t_champions	*champ;

	tmp = env->list_champions;
	while (tmp)
	{
		champ = ((t_champions *)tmp->content);
		if (champ->champ_id == id)
		{
			if (tmp == env->list_champions)
				env->list_champions = tmp->next;
			else
				prev->next = tmp->next;
			ft_verbose_dead(env, champ);
			ft_del_champ(((t_champions *)tmp->content));
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
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
