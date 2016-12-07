/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 16:56:21 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


int		ft_corewar_live(t_vm *env, t_champions *champ, int op)
{
	op = 0;
	int		*nbr;
	int		count;

	ft_printf("{9}----live----{0}\n");
	nbr = ft_get_size(env, champ, 0);
	count = ft_count_to_next(nbr, 1);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_aff(t_vm *env, t_champions *champ, int op)
{
	op = 0;
	int		*nbr;
	int		count;

	ft_printf("{9}----aff----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 16);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);

	if (nbr[0] == 1)
	{
		int value = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		ft_printf("{10}[%c]{0}\n", champ->reg[value] % 256);
	}

	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (2);
}
