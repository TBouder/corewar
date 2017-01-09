/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 18:11:10 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

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
	env->buf = ft_set_buffer_4(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer_4(nbr[1]);
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
