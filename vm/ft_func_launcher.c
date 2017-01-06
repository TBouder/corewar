/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 23:27:37 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 14:41:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_instruct_name() function takes an op code and return the full name, as
** a string, of this opcode (No malloc).
*/

static char	*ft_instruct_name_helper(int op)
{
	if (op == ZJMP)
		return ((char *)"ZJMP");
	else if (op == LDI)
		return ((char *)"LDI");
	else if (op == STI)
		return ((char *)"STI");
	else if (op == FORK)
		return ((char *)"FORK");
	else if (op == LLD)
		return ((char *)"LLD");
	else if (op == LLDI)
		return ((char *)"LLDI");
	else if (op == LFORK)
		return ((char *)"LFORK");
	else if (op == AFF)
		return ((char *)"AFF");
	return ((char *)"INVALID INSTRUCTION");
}

static char	*ft_instruct_name(int op)
{
	if (op == LIVE)
		return ((char *)"LIVE");
	else if (op == LD)
		return ((char *)"LD");
	else if (op == ST)
		return ((char *)"ST");
	else if (op == ADD)
		return ((char *)"ADD");
	else if (op == SUB)
		return ((char *)"SUB");
	else if (op == AND)
		return ((char *)"AND");
	else if (op == OR)
		return ((char *)"OR");
	else if (op == XOR)
		return ((char *)"XOR");
	return (ft_instruct_name_helper(op));
}

/*
** The ft_call_func() function calls the correct function in the funcs folder,
** according to the opcode.
*/

static void	ft_call_func(t_vm *env, t_champions *champ, int *nbr, int op)
{
	env->arg1 = 0;
	env->arg2 = 0;
	env->arg3 = 0;
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

	if (op >= 1 && op <= 16)
	{
		if (op != LIVE && op != ZJMP && op != FORK && op != LFORK)
			nbr = ft_get_size(env, champ);
		else
		{
			nbr = ft_nbrnew(3);
			nbr[0] = 10;
		}
		count = ft_count_to_next(nbr, op);
		if (!IS_GRAPH && IS_VERBOSE)
			ft_put("[{10}%s{0}]\n", ft_instruct_name(op));
		ft_call_func(env, champ, nbr, op);
		op != ZJMP ? champ->pc += count : 0;
		champ->pc = ft_mod(champ->pc, M);
		free(nbr);
		return (ft_ret_cycle((int)env->map[champ->pc]));
	}
	champ->pc += 1;
	champ->pc = ft_mod(champ->pc, M);
	return (ft_ret_cycle((int)env->map[champ->pc]));
}
