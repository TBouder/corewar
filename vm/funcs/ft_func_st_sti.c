/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/15 16:44:06 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#define IS_GRAPH env->options->flags['g']

static int			ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

/*
** Stock la valeur de NBR[0] dans NBR[1]
*/
void	ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);

		if (IS_REG(nbr[1]))
			champ->reg[env->arg2] = champ->reg[env->arg1];
		else if (IS_IND(nbr[1]))
		{
			env->map[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->reg[env->arg1];
			env->map_owner[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->color;
		}
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;
	int		sum_idx;

	pc = champ->pc + 1;

	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		ft_printf("champ->reg[0] : %u\n", champ->reg[env->arg1]);
		ft_printf("champ->reg[0] : %x\n", champ->reg[env->arg1]);
		ft_print_memory(env->map, 80);

		if (IS_IND(nbr[1]))
			env->arg2 = env->map[(champ->pc - 1 + (env->arg2 % I)) % M];
		if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		if (IS_REG(nbr[2]))
			env->arg3 = champ->reg[env->arg3];
		sum_idx = env->arg2 + env->arg3;

		env->map[(sum_idx % I) % M] = champ->reg[env->arg1];
		env->map_owner[(sum_idx % I) % M] = champ->color;
	}
}
