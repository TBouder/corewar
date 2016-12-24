/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/24 18:58:57 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_DIR(nbr))
		return (2);
	return (0);
}

void	ft_corewar_fork(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_DIR(nbr[0]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		if (env->arg1 > 32768)
			env->arg1 = (champ->pc + ((env->arg1 % I) - I)) % M;
		else
			env->arg1 = (champ->pc + (env->arg1 % I)) % M;
		ft_add_champion(env, champ, champ->champ_id - 1, env->arg1);
	}
}

void	ft_corewar_lfork(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_DIR(nbr[0]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		env->arg1 = (champ->pc + env->arg1) % M;
		ft_add_champion(env, champ, champ->champ_id - 1, env->arg1);
	}
}
