/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_add_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 11:47:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_add_sub_helper(t_vm *env, t_champions *champ, int *nbr, int sub)
{
	int		arg1;
	int		arg2;
	int		arg3;

	if (nbr[0] == 1 && nbr[1] == 1 && nbr[2] == 1)
	{
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		arg2 = ft_byte_to_str(&env->map[champ->pc + 2], 1);
		arg3 = ft_byte_to_str(&env->map[champ->pc + 3], 1);
		if (sub == 1)
			champ->reg[arg3] += champ->reg[arg1] + champ->reg[arg2];
		else
			champ->reg[arg3] += champ->reg[arg1] - champ->reg[arg2];
		champ->carry = (champ->reg[arg3] == 0) ? 1 : 0;
	}
	else
	{
		ft_printf("BIG ERROR LOLOLOLOLOL\n");/////////
		exit(0);
	}
}

int		ft_corewar_add_sub(t_vm *env, t_champions *champ, int opcode)
{
	opcode == 4 ? ft_printf("{9}----add----{0}\n") : ft_printf("{9}----sub----{0}\n");
	int		*nbr;
	int		count;

	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, opcode);
	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n", nbr[0], nbr[1], nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	ft_add_sub_helper(env, champ, nbr, opcode == 4 ? 1 : -1);
	champ->pc += count;
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);

}
