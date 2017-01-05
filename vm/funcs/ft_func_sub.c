/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:46:31 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 17:52:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (4);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[2]);
	env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
}

/*
** ARG1 can be REG
** ARG2 can be REG
** ARG3 can be REG
*/

void		ft_corewar_sub(t_vm *env, t_champions *champ, int *nbr)
{
	int			pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		if (IN_REG(env->arg1) && IN_REG(env->arg2) && IN_REG(env->arg3))
		{
			champ->reg[env->arg3] = champ->reg[env->arg1]
				- champ->reg[env->arg2];
			champ->carry = (champ->reg[env->arg3] == 0) ? 1 : 0;
		}
	}
}
