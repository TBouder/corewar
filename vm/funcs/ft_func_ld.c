/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 23:50:41 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_edit_arg_2(t_vm *env, int *nbr)
{
	if (IS_REG(nbr[1]) && IN_REG(env->arg2))
		return (1);
	return (0);
}

static int	ft_edit_arg_1(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_DIR(nbr[0]))
		;
	else if (IS_IND(nbr[0]) && env->arg1 > MAX)
		env->arg1 = ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 + ((env->arg1 % I) - I), M)], 4);
	else if (IS_IND(nbr[0]))
		env->arg1 = ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 + (env->arg1 % I), M)], 4);
	else
		return (0);
	return (1);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer_2(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_2(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
}

/*
** ARG1 can be IND or DIR
** ARG2 can be REG
*/

void		ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_DIR_IND(nbr[0]) && IS_REG(nbr[1]))
	{
		ft_extract_args(env, pc, nbr);
		wprintw(env->notif, "%d\n", env->arg1);
		ft_reload_windows(env, 3);
		if (ft_edit_arg_1(env, champ, nbr) == 0)
			return ;
		if (ft_edit_arg_2(env, nbr) == 0)
			return ;
		champ->reg[env->arg2] = env->arg1;
		champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}
