/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 16:22:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_clear_champ(t_champions *champ)
{
	ft_strdel(&champ->name);
	ft_strdel(&champ->comment);
	ft_strdel(&champ->content);
}


void			ft_clear_all(t_vm *env)
{
	ft_dbstrdel(env->filename);
	// ft_clear_champions(env->champions, env->nb_champ);
	ft_strdel(&env->map);
	free(env->header);
	// free(env->champions);
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
