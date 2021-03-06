/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/10 19:55:34 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_edit_arg_3(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_DIR(nbr[2]) && env->arg3 > MAX)
		env->arg3 = env->arg3 % I - I;
	else if (IS_DIR(nbr[2]))
		;
	else if (IS_REG(nbr[2]) && IN_REG(env->arg3))
		env->arg3 = champ->reg[env->arg3];
	else
		return (0);
	return (1);
}

static int	ft_edit_arg_2(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_DIR(nbr[1]) && env->arg2 > MAX)
		env->arg2 = env->arg2 % I - I;
	else if (IS_DIR(nbr[1]))
		;
	else if (IS_IND(nbr[1]) && env->arg2 > MAX)
		env->arg2 = ft_byte_to_str(env,
			ft_mod(champ->pc + ((env->arg2 % I) - I), M), 2);
	else if (IS_IND(nbr[1]))
		env->arg2 = ft_byte_to_str(env,
			ft_mod(champ->pc + (env->arg2 % I), M), 2);
	else if (IS_REG(nbr[1]))
		env->arg2 = champ->reg[env->arg2];
	else
		return (0);
	return (1);
}

static int	ft_edit_arg_1(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_REG(nbr[0]) && IN_REG(env->arg1))
		env->arg1 = champ->reg[env->arg1];
	else
		return (0);
	return (1);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer_4(nbr[0]);
	env->arg1 = ft_byte_to_str(env, pc, env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_4(nbr[1]);
	env->arg2 = ft_byte_to_str(env, pc, env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_4(nbr[2]);
	env->arg3 = ft_byte_to_str(env, pc, env->buf);
}

/*
** Somme des valeurs de NBR[1] + NBR[2] comme adresse pour valeur de NBR[0]
** ARG1 can be REG
** ARG2 can be DIR, IND or REG
** ARG3 can be DIR or REG
*/

void		ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		// ft_printf ("reg => {10}%d, %d, %d{0}\n", env->arg1, env->arg2, env->arg3);
		// ft_printf ("champ => {10}%d, %d, %d{0}\n", champ->reg[env->arg1], champ->reg[env->arg2], champ->reg[env->arg3]);
		if (!ft_edit_arg_1(env, champ, nbr))
			return ;
		if (!ft_edit_arg_2(env, champ, nbr))
			return ;
		if (!ft_edit_arg_3(env, champ, nbr))
			return ;
		env->sum_idx = env->arg2 + env->arg3;
		ft_put_map_reg(env, champ, 0, 0);
	}
}
