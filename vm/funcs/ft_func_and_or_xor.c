/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_and_or_xor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/04 14:38:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	ft_and_or_xor_helper(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_IND(nbr[0]) == 1)
	{
		if (env->arg1 > 32768)
			env->arg1 = env->map[
				ft_mod(champ->pc - 1 + ((env->arg1 % I) - I), M)];
		else
			env->arg1 = env->map[ft_mod(champ->pc - 1 + (env->arg1 % I), M)];
	}
	else if (IS_REG(nbr[0]) && IS_IN_REG(env->arg1))
		env->arg1 = champ->reg[env->arg1];
	if (IS_IND(nbr[1]) == 1)
	{
		if (env->arg2 > 32768)
			env->arg2 = env->map[
				ft_mod(champ->pc - 1 + ((env->arg2 % I) - I), M)];
		else
			env->arg2 = env->map[ft_mod(champ->pc - 1 + (env->arg2 % I), M)];
	}
	else if (IS_REG(nbr[1]) && IS_IN_REG(env->arg2))
		env->arg2 = champ->reg[env->arg2];
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer_and_or_xor(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_and_or_xor(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_and_or_xor(nbr[2]);
	env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
}

void		ft_corewar_and(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		ft_and_or_xor_helper(env, champ, nbr);
		if (IS_IN_REG(env->arg3))
		{
			champ->carry = champ->reg[env->arg3] == 0 ? 1 : 0;
			champ->reg[env->arg3] = env->arg1 & env->arg2;
		}
	}
}

void		ft_corewar_or(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		ft_and_or_xor_helper(env, champ, nbr);
		if (IS_IN_REG(env->arg3))
		{
			champ->carry = champ->reg[env->arg3] == 0 ? 1 : 0;
			champ->reg[env->arg3] = env->arg1 | env->arg2;
		}
	}
}

void		ft_corewar_xor(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		ft_and_or_xor_helper(env, champ, nbr);
		if (IS_IN_REG(env->arg3))
		{
			champ->carry = champ->reg[env->arg3] == 0 ? 1 : 0;
			champ->reg[env->arg3] = env->arg1 ^ env->arg2;
		}
	}
}
