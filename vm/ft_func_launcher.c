/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 14:23:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_ret_cycle(int op)
{
	if (op == 16)
		return (2);
	else if (op == 2 || op == 3)
		return (5);
	else if (op == 6 || op == 7 || op == 8)
		return (6);
	else if (op == 1 || op == 4 || op == 5 || op == 13)
		return (10);
	else if (op == 9)
		return (20);
	else if (op == 10 || op == 11)
		return (25);
	else if (op == 14)
		return (50);
	else if (op == 12)
		return (800);
	else if (op == 15)
		return (1000);
	return (0);
}

static int	ft_has_next(int op)
{
	if (op == 1 || op == 9 || op == 12 || op == 15)
		return (0);
	return (1);
}

int			ft_get_args(t_vm *env, t_champions *champ, int op)
{
	int		*nbr;
	int		count;

	nbr = ft_get_size(env, champ, ft_has_next(op)); //Va, entre autre, faire +1 au pc si needed
	count = ft_count_to_next(nbr, op);
	ft_print_arg_count(nbr, count, champ->pc); ////DEBUG

	op == 1 ? ft_corewar_live(env, champ, nbr) : 0;		//LIVE
	op == 2 ? ft_corewar_ld(env, champ, nbr) : 0;		//LD
	op == 3 ? ft_corewar_st(env, champ, nbr) : 0;		//ST
	op == 4 ? ft_corewar_add(env, champ, nbr) : 0;		//ADD
	op == 5 ? ft_corewar_sub(env, champ, nbr) : 0;		//SUB
	op == 6 ? ft_corewar_and(env, champ, nbr) : 0;		//AND
	op == 7 ? ft_corewar_or(env, champ, nbr) : 0;		//OR
	op == 8 ? ft_corewar_xor(env, champ, nbr) : 0;		//XOR
	op == 9 ? ft_corewar_zjmp(env, champ, nbr) : 0;		//ZJMP
	op == 10 ? ft_corewar_ldi(env, champ, nbr) : 0;		//LDI
	op == 11 ? ft_corewar_sti(env, champ, nbr) : 0;		//STI
	op == 12 ? ft_corewar_fork(env, champ, nbr) : 0;	//FORK
	op == 13 ? ft_corewar_lld(env, champ, nbr) : 0;		//LLD
	op == 14 ? ft_corewar_lldi(env, champ, nbr) : 0;	//LLDI
	op == 15 ? ft_corewar_fork(env, champ, nbr) : 0;	//LFORK
	op == 16 ? ft_corewar_aff(env, champ, nbr) : 0;		//AFF
	champ->pc += count;

	return (ft_ret_cycle(op));
}
