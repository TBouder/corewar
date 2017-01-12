/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 15:22:14 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** ARG3 can be REG
*/

static int	ft_edit_arg_3(t_vm *env, int *nbr)
{
	if (IS_REG(nbr[2]) && IN_REG(env->arg3))
		return (1);
	return (0);
}

/*
** ARG2 can be DIR, IND or REG
*/

static int	ft_edit_arg_2(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc - 1;
	if (IS_DIR(nbr[1]))
		;
	else if (IS_IND(nbr[1]))
		env->arg2 = env->map[ft_mod(pc + env->arg2, M)];
	else if (IS_REG(nbr[1]) && IN_REG(env->arg2))
		env->arg2 = champ->reg[env->arg2];
	else
		return (0);
	return (1);
}

/*
** ARG1 can be DIR, IND or REG
*/

static int	ft_edit_arg_1(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc - 1;
	if (IS_DIR(nbr[0]))
		;
	else if (IS_IND(nbr[0]))
		env->arg1 = env->map[ft_mod(pc + env->arg1, M)];
	else if (IS_REG(nbr[0]) && IN_REG(env->arg1))
		env->arg1 = champ->reg[env->arg1];
	else
		return (0);
	return (1);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer_2(nbr[0]);
	env->arg1 = ft_byte_to_str(env, pc, env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_2(nbr[1]);
	env->arg2 = ft_byte_to_str(env, pc, env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_2(nbr[2]);
	env->arg3 = ft_byte_to_str(env, pc, env->buf);
}

/*
** ARG1 can be DIR, IND or REG
** ARG2 can be DIR, IND or REG
** ARG3 can be REG
*/

void		ft_corewar_or(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		if (!ft_edit_arg_1(env, champ, nbr))
			return ;
		if (!ft_edit_arg_2(env, champ, nbr))
			return ;
		if (!ft_edit_arg_3(env, nbr))
			return ;
		champ->carry = champ->reg[env->arg3] == 0 ? 1 : 0;
		champ->reg[env->arg3] = env->arg1 | env->arg2;
	}
}
