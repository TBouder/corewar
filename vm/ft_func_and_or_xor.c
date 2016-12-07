/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_and_or_xor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 12:00:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_and_or_xor_helper(void)
{
	;
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
	ft_and_or_xor_helper();
	champ->pc += count;

	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
	nbr[0], nbr[1], nbr[2]);
	ft_printf("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, champ->pc);
	return (6);
}
