/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 18:03:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (2);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer(nbr[0]);
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
			champ->pc = ft_mod(champ->pc + ((env->arg1 % I) - I), M);
		else
			champ->pc = ft_mod(champ->pc + (env->arg1 % I), M);
	}
	else
		champ->pc += ft_count_to_next(nbr, ZJMP);
}
