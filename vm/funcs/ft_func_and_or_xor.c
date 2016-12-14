/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_and_or_xor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/14 16:56:00 by quroulon         ###   ########.fr       */
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

void	ft_and_or_xor_helper(t_vm *env, t_champions *champ, int *nbr, int op)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
		
		if (IS_IND(nbr[0]) == 1)
			env->arg1 = env->map[(champ->pc - 1 + (env->arg1 % I)) % M];
		else if (IS_REG(nbr[0]))
			env->arg1 = champ->reg[env->arg1];

		if (IS_IND(nbr[1]) == 1)
			env->arg2 = env->map[(champ->pc - 1 + (env->arg2 % I)) % M];
		else if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];

		op == 6 ? champ->reg[env->arg3] = env->arg1 & env->arg2 : 0;
		op == 7 ? champ->reg[env->arg3] = env->arg1 | env->arg2 : 0;
		op == 8 ? champ->reg[env->arg3] = env->arg1 ^ env->arg2 : 0;


		int k = champ->carry;
		champ->carry = champ->reg[env->arg3] != 0 ? 1 : 0;
		if (champ->carry != k)
			ft_printf("{10}new Carry = %d{0}\n", champ->carry);


	}
}

void		ft_corewar_and(t_vm *env, t_champions *champ, int *nbr)
{
	ft_and_or_xor_helper(env, champ, nbr, 6);
}

void		ft_corewar_or(t_vm *env, t_champions *champ, int *nbr)
{
	ft_and_or_xor_helper(env, champ, nbr, 7);
}

void		ft_corewar_xor(t_vm *env, t_champions *champ, int *nbr)
{
	ft_and_or_xor_helper(env, champ, nbr, 8);
}
