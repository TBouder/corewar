/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 15:04:25 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_corewar_st_sti(t_vm *env, t_champions *champ, int op)
{
	op == 3 ? ft_printf("{9}----st----{0}\n") : ft_printf("{9}----sti----{0}\n");

	int		*nbr;
	int		count;

	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, op);

	champ->pc += count;
	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
	nbr[0], nbr[1], nbr[2]);
	ft_printf("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, champ->pc);

	return (op == 3 ? 10 : 25);
}
