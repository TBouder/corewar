/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ldi_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 15:58:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

void		ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
		if (IS_IND(nbr[0]))
			env->arg1 = env->map[ft_mod(champ->pc - 1 + env->arg1, M)];
		if (IS_REG(nbr[0]))
			env->arg1 = champ->reg[env->arg1];
		if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		env->sum_idx = env->arg1 + env->arg2;
		champ->reg[env->arg3] = ft_byte_to_str(
			&env->map[ft_mod(champ->pc - 1 + env->sum_idx, M)], 4);
	}
}

void		ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
		if (IS_IND(nbr[0]))
			env->arg1 = env->map[ft_mod(champ->pc - 1 + env->arg1, M)];
		else if (IS_REG(nbr[0]))
			env->arg1 = champ->reg[env->arg1];
		if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		env->sum_idx = env->arg1 + env->arg2;
		champ->reg[env->arg3] = ft_byte_to_str(
			&env->map[ft_mod(champ->pc - 1 + env->sum_idx, M)], 4);
	}
}
