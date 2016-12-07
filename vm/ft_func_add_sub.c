/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_add_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 00:35:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_corewar_add(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----ADD----{0}\n");
	int		arg1;
	int		arg2;
	int		arg3;

	if (nbr[0] == 1 && nbr[1] == 1 && nbr[2] == 1)
	{
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		arg2 = ft_byte_to_str(&env->map[champ->pc + 2], 1);
		arg3 = ft_byte_to_str(&env->map[champ->pc + 3], 1);
		champ->reg[arg3] = champ->reg[arg1] + champ->reg[arg2];
		champ->carry = (champ->reg[arg3] == 0) ? 1 : 0;

		ft_printf("{10}r%d{0} = {10}r%d{0} + {10}r%d{0}\n", arg3, arg1, arg2);
		ft_printf("[{10}0x%x{0}] = [{10}0x%x{0}] + [{10}0x%x{0}]\n", champ->reg[arg3], champ->reg[arg1], champ->reg[arg2]);
		ft_printf("[{10}%c{0}] = [{10}%c{0}] + [{10}%c{0}]\n", champ->reg[arg3], champ->reg[arg1], champ->reg[arg2]);
	}
}

void	ft_corewar_sub(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----SUB----{0}\n");
	int		arg1;
	int		arg2;
	int		arg3;

	if (nbr[0] == 1 && nbr[1] == 1 && nbr[2] == 1)
	{
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		arg2 = ft_byte_to_str(&env->map[champ->pc + 2], 1);
		arg3 = ft_byte_to_str(&env->map[champ->pc + 3], 1);
		champ->reg[arg3] = champ->reg[arg1] - champ->reg[arg2];
		champ->carry = (champ->reg[arg3] == 0) ? 1 : 0;

		ft_printf("{10}r%d{0} = {10}r%d{0} - {10}r%d{0}\n", arg3, arg1, arg2);
		ft_printf("[{10}0x%x{0}] = [{10}0x%x{0}] - [{10}0x%x{0}]\n", champ->reg[arg3], champ->reg[arg1], champ->reg[arg2]);
		ft_printf("[{10}%c{0}] = [{10}%c{0}] - [{10}%c{0}]\n", champ->reg[arg3], champ->reg[arg1], champ->reg[arg2]);
	}
}
