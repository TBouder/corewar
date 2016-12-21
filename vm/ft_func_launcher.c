/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 12:22:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_ret_cycle() function takes an opcode as paramater and according to it,
** returns the number of cycle to perform before calling the next instruction
*/
int			ft_ret_cycle(int op)
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

/*
** The ft_instruct_name() function takes an op code and return the full name, as
** a string, of this opcode (No malloc).
*/
static char	*ft_instruct_name_helper(int op)
{
	if (op == ZJMP)
		return ("ZJMP");
	else if (op == LDI)
		return ("LDI");
	else if (op == STI)
		return ("STI");
	else if (op == FORK)
		return ("FORK");
	else if (op == LLD)
		return ("LLD");
	else if (op == LLDI)
		return ("LLDI");
	else if (op == LFORK)
		return ("LFORK");
	else if (op == AFF)
		return ("AFF");
	return ("INVALID INSTRUCTION");
}

char		*ft_instruct_name(int op)
{
	if (op == LIVE)
		return ("LIVE");
	else if (op == LD)
		return ("LD");
	else if (op == ST)
		return ("ST");
	else if (op == ADD)
		return ("ADD");
	else if (op == SUB)
		return ("SUB");
	else if (op == AND)
		return ("AND");
	else if (op == OR)
		return ("OR");
	else if (op == XOR)
		return ("XOR");
	return (ft_instruct_name_helper(op));
}

/*
** The ft_call_func() function calls the correct function in the funcs folder,
** according to the opcode.
*/
static void	ft_call_func(t_vm *env, t_champions *champ, int *nbr, int op)
{
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
}

/*
** The ft_get_args() function gets the args of the argument and calls the
** function to perform the instruction, after what, moves the PC.
*/
int			ft_get_args(t_vm *env, t_champions *champ, int op)
{
	int		*nbr;
	int		count;

	if (op != LIVE && op != ZJMP && op != FORK && op != LFORK)
		nbr = ft_get_size(env, champ);
	else
	{
		nbr = ft_nbrnew(3);
		nbr[0] = 10;
	}
	count = ft_count_to_next(nbr, op);

	!IS_GRAPH && IS_VERBOSE ? ft_put("[{10}%s{0}]\n", ft_instruct_name(op)) : 0;

	ft_call_func(env, champ, nbr, op);

	if (op != ZJMP)
		champ->pc += count;

	IS_GRAPH ? ft_reload_windows(env, 1) : 0;
	return (ft_ret_cycle((int)env->map[champ->pc]));
}
