/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_add_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 20:15:41 by tbouder          ###   ########.fr       */
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
		ft_printf("LOLILOL {10}[%d]{0} LOLILOL\n", champ->reg[arg3]);
		champ->carry = (champ->reg[arg3] == 0) ? 1 : 0;
	}
	else
	{
		ft_printf("BIG ERROR LOLOLOLOLOL\n");/////////
		exit(0);
	}
}

int		ft_corewar_add(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----add----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 4);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	ft_add_sub_helper(env, champ, nbr, 1);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_sub(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----sub----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 5);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	ft_add_sub_helper(env, champ, nbr, -1);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}
