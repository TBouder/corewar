/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 00:09:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer_3(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
}

/*
** ARG1 can be DIR
*/

void		ft_corewar_zjmp(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (champ->carry == 1 && IS_DIR(nbr[0]))
	{
		ft_extract_args(env, pc, nbr);
		if (env->arg1 > MAX)
			env->arg1 = ft_mod(env->arg1, I) - I;
		else
			env->arg1 = ft_mod(env->arg1, I);
		champ->pc = ft_mod(champ->pc + env->arg1, M);
	}
	else
		champ->pc += ft_count_to_next(nbr, ZJMP);
}
