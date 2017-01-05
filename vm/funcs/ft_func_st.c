/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 15:41:36 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

static int	ft_edit_arg_2(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_REG(nbr[1]) && IN_REG(env->arg2))
	{
		champ->reg[env->arg2] = env->arg1;
		return (-1);
	}
	else if (IS_IND(nbr[1]) && env->arg2 > MAX)
		env->sum_idx = (env->arg2 % I) - I;
	else if (IS_IND(nbr[1]))
		env->sum_idx = env->arg2 % I;
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
	env->buf = ft_set_buffer(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
}

/*
** Stock la valeur de NBR[0] dans NBR[1]
** ARG1 can be REG
** ARG1 can be IND or REG
*/

void		ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_IND_REG(nbr[1]))
	{
		ft_extract_args(env, pc, nbr);
		if (!ft_edit_arg_1(env, champ, nbr))
			return ;
		if (!ft_edit_arg_2(env, champ, nbr))
			return ;
		ft_put_map_reg(env, champ, 0, 0);
	}
}
