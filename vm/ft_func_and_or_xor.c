/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_and_or_xor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 19:00:17 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_and_or_xor_helper(t_vm *env, t_champions *champ, int *nbr, int op)
{
	int		buffer1;
	int		buffer2;
	int		arg1;
	int		arg2;
	int		arg_reg;

	// les deux premieres verif nécessaire ?
	if (nbr[2] == 1)
	{
		buffer1 = nbr[0] == 11 ? 2 : 4;
		buffer1 = nbr[0] == 1 ? 1 : 4;
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], buffer1);
		buffer2 = nbr[1] == 11 ? 2 : 4;
		buffer2 = nbr[1] == 1 ? 1 : 4;
		arg2 = ft_byte_to_str(&env->map[champ->pc + 1 + buffer1], buffer2);
		arg_reg = ft_byte_to_str(&env->map[champ->pc + 1 + buffer1 + buffer2], 1);
		nbr[0] == 1 ? arg1 = champ->reg[arg1] : 0;
		nbr[0] == 11 ? arg1 = env->map[champ->pc + 1 + buffer1 + arg1] : 0;
		nbr[1] == 1 ? arg2 = champ->reg[arg2] : 0;
		nbr[1] == 11 ? arg2 = env->map[champ->pc + 1 + buffer1 + buffer2 + arg2] : 0;
		if (op == 6)
			champ->reg[arg_reg] = arg1 & arg2;
		else if (op == 7)
			champ->reg[arg_reg] = arg1 | arg2;
		else if (op == 8)
			champ->reg[arg_reg] = arg1 ^ arg2;
		champ->carry = champ->reg[arg_reg] == 0 ? 1 : 0;

	}

}

int		ft_corewar_and_or_xor(t_vm *env, t_champions *champ, int op)
{
	op == 6 ? ft_printf("{9}----and----{0}\n") :
	op == 7 ? ft_printf("{9}----or----{0}\n") :
	op == 8 ? ft_printf("{9}----xor----{0}\n") : 0;

	int		*nbr;
	int		count;

	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, op);
	ft_and_or_xor_helper(env, champ, nbr, op);
	champ->pc += count;

	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
	nbr[0], nbr[1], nbr[2]);
	ft_printf("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, champ->pc);
	return (6);
}
