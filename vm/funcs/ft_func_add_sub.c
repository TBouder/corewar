/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_add_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 12:48:51 by tbouder          ###   ########.fr       */
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

void	ft_corewar_add(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----ADD----{0}\n");
	int			pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		champ->reg[env->arg3] = (champ->reg[env->arg1] + champ->reg[env->arg2]) % I;
		champ->carry = (champ->reg[env->arg3] != 0) ? 1 : 0;
	}
}

void	ft_corewar_sub(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----SUB----{0}\n");
	int			pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		champ->reg[env->arg3] = (champ->reg[env->arg1] - champ->reg[env->arg2]) % I;
		champ->carry = (champ->reg[env->arg3] != 0) ? 1 : 0;
	}
}