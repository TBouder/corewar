/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:27:24 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 12:11:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_ret_cycle() function takes an opcode as paramater and according to it,
** returns the number of cycle to perform before calling the next instruction
*/

int		ft_ret_cycle(int op)
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
	return (1);
}

void	ft_set_lives(t_vm *env, int val)
{
	int		i;

	i = 1;
	env->nb_live[0] = 0;
	while (i <= env->nb_champ)
	{
		env->nb_live[i] = val;
		i++;
	}
}

void	ft_reset_lives(t_vm *env, int val)
{
	int		i;

	i = 1;
	env->nb_live[0] = 0;
	while (i <= env->nb_champ)
	{
		if (env->nb_live[i] > 0)
			env->nb_live[i] = val;
		i++;
	}
}

int		ft_set_buffer_and_or_xor(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	else if (IS_DIR(nbr))
		return (4);
	else if (IS_IND(nbr))
		return (2);
	return (0);
}

// int		ft_mod_OLD(int nbr, int mod)
// {
// 	nbr %= mod;
// 	if (nbr < 0)
// 		return (mod + nbr);
// 	return (nbr);
// }


int		ft_mod(int nbr, int mod)
{
	if (nbr < 0)
	{
		nbr = -nbr % mod;
		return (M - nbr);
	}
	else
	{
		nbr = nbr % mod;
		return (nbr);
	}
}
