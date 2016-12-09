/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 16:25:01 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	ft_put("{9}----ST----{0}\n");
	int		buffer;
	int		arg1;
	int		arg2;

	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		buffer = ft_set_buffer(nbr[1]);
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		arg2 = ft_byte_to_str(&env->map[champ->pc + 2], buffer);


		if (IS_REG(nbr[1]))
		{
			ft_put("{10}r%d{0} = {10}r%d{0}\n", arg2, arg1);
			ft_put("{10}r%d{0} = {10}%d{0}\n", arg2, champ->reg[arg1]);
			champ->reg[arg2] = champ->reg[arg1];
		}
		else if (IS_IND(nbr[1]))
		{
			ft_put("env->map[{10}%d{0}] = {10}r%d{0}\n",
				champ->pc + buffer + (arg2 % IDX_MOD), arg1);
			ft_put("env->map[{10}%d{0}] = {10}%d{0}\n",
				champ->pc + buffer + (arg2 % IDX_MOD), champ->reg[arg1]);
			ft_printf("%d, %d, %d, %d\n", champ->pc, buffer, arg2, arg2 % IDX_MOD);
			env->map[champ->pc + buffer + (arg2 % IDX_MOD)] = champ->reg[arg1];
		}
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----STI----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum_idx;

	pc = champ->pc + 1;

	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		arg1 = ft_byte_to_str(&env->map[pc], 1);
		pc++;

		buffer = ft_set_buffer(nbr[1]);
		arg2 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;

		buffer = ft_set_buffer(nbr[2]);
		arg3 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;

		sum_idx = arg2 + arg3;

		ft_put("\033[104mMAP[%d + %d] == [%c]{0}\n", pc, (sum_idx % IDX_MOD), env->map[pc + (sum_idx % IDX_MOD)]);

		env->map[pc + (sum_idx % IDX_MOD)] = champ->reg[arg1];

		ft_put("\033[104mMAP[%d + %d] == [%c]{0}\n", pc, (sum_idx % IDX_MOD), env->map[pc + (sum_idx % IDX_MOD)]);

	}
}
