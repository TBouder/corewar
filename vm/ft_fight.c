/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:23 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 16:07:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_one_isalive(t_vm *env)
{
	int		i;

	i = 0;
	while (i < env->nb_champ)
	{
		if (env->champions[i].exist == TRUE)
		{
			if (env->champions[i].is_alive == TRUE)
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_witch_isalive(t_vm *env)
{
	int		i;

	i = 0;
	while (i < env->nb_champ)
	{
		if (env->champions[i].exist == TRUE)
		{
			if (env->champions[i].is_alive == FALSE)
				env->champions[i].exist = FALSE; //MORT DU PROGRAMME
		}
		i++;
	}
}

void	ft_fight(t_vm *env)
{
	while (ft_one_isalive(env))
	{
		if (env->to_die == CYCLE_TO_DIE)
		{
			ft_witch_isalive(env);
			env->to_die = 0;
		}
			;
	}
}
