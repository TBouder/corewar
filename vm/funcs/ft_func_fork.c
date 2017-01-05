/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 14:13:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_DIR(nbr))
		return (2);
	return (0);
}

static int	ft_edit_arg_1(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc - 1;
	if (IS_DIR(nbr[0]) && env->arg1 > MAX)
		env->arg1 = ft_mod(champ->pc + ((env->arg1 % I) - I), M);
	else if (IS_DIR(nbr[0]))
		env->arg1 = ft_mod(champ->pc + (env->arg1 % I), M);
	else
		return (0);
	return (1);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
}

void		ft_corewar_fork(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_DIR(nbr[0]))
	{
		ft_extract_args(env, pc, nbr);
		if (!ft_edit_arg_1(env, champ, nbr))
			return ;
		ft_init_champ(env, champ, champ->champ_id - 1, env->arg1);
	}
}
