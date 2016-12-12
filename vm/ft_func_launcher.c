/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 18:50:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_ret_cycle(int op)
{
	if (op == AFF)
		return (2);
	else if (op == LD || op == ST)
		return (5);
	else if (op == AND || op == OR || op == XOR)
		return (6);
	else if (op == LIVE || op == ADD || op == SUB || op == LLD)
		return (10);
	else if (op == ZJMP)
		return (20);
	else if (op == LDI || op == STI)
		return (25);
	else if (op == LLDI)
		return (50);
	else if (op == FORK)
		return (800);
	else if (op == LFORK)
		return (1000);
	return (0);
}

static int	ft_has_next(int op)
{
	if (op == LIVE || op == ZJMP || op == FORK || op == LFORK)
		return (0);
	return (1);
}

int			ft_get_args(t_vm *env, t_champions *champ, int op)
{
	int		*nbr;
	int		count;

	if (op != LIVE)
		nbr = ft_get_size(env, champ, ft_has_next(op)); //Va, entre autre, faire +1 au pc si needed
	else
	{
		nbr = ft_nbrnew(1);
		nbr[0] = 10;
	}
	count = ft_count_to_next(nbr, op);
	ft_print_arg_count(nbr, count, champ->pc); ////DEBUG

	op == LIVE ? ft_corewar_live(env, champ, nbr) : 0;
	op == LD ? ft_corewar_ld(env, champ, nbr) : 0;
	op == ST ? ft_corewar_st(env, champ, nbr) : 0;
	op == ADD ? ft_corewar_add(env, champ, nbr) : 0;
	op == SUB ? ft_corewar_sub(env, champ, nbr) : 0;
	op == AND ? ft_corewar_and(env, champ, nbr) : 0;
	op == OR ? ft_corewar_or(env, champ, nbr) : 0;
	op == XOR ? ft_corewar_xor(env, champ, nbr) : 0;
	op == ZJMP ? ft_corewar_zjmp(env, champ, nbr) : 0;
	op == LDI ? ft_corewar_ldi(env, champ, nbr) : 0;
	op == STI ? ft_corewar_sti(env, champ, nbr) : 0;
	op == FORK ? ft_corewar_fork(env, champ, nbr) : 0;
	op == LLD ? ft_corewar_lld(env, champ, nbr) : 0;
	op == LLDI ? ft_corewar_lldi(env, champ, nbr) : 0;
	op == LFORK ? ft_corewar_fork(env, champ, nbr) : 0;
	op == AFF ? ft_corewar_aff(env, champ, nbr) : 0;
	champ->pc += count;

	return (ft_ret_cycle(op));
}
