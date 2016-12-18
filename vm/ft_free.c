/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:12:52 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/16 19:36:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_clear_champions(t_champions **champions, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&champions[i]->name);
		ft_strdel(&champions[i]->comment);
		ft_strdel(&champions[i]->content);
		champions[i]->magic = 0;
		champions[i]->prog_size = 0;
		i++;
	}
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
