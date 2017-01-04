/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 15:59:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (4);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

void		ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		if (IS_DIR(nbr[0]))
			champ->reg[env->arg2] = env->arg1;
		else if (IS_IND(nbr[0]))
			champ->reg[env->arg2] =
				env->map[ft_mod(champ->pc - 1 + env->arg1, M)];
		champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}

void		ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		if (IS_DIR(nbr[0]))
			champ->reg[env->arg2] = env->arg1;
		else if (IS_IND(nbr[0]))
		{
			if (env->arg1 > MAX)
			{
				ft_printf("{9}%ld{0}\n", ft_mod(champ->pc - 1 + ((env->arg1 % I) - I), M));
				champ->reg[env->arg2] = ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 +
				((env->arg1 % I) - I), M)], 4);
			}
			else
			{
				ft_printf("{14}%ld{0}\n", ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 +
				(env->arg1 % I), M)], 4));
				champ->reg[env->arg2] = ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 +
				(env->arg1 % I), M)], 4);
			}
		}
		champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}
