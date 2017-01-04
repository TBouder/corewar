/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/04 20:00:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (4);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
}

void		ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		ft_extract_args(env, pc, nbr);
		if (IS_DIR(nbr[0]) && IS_IN_REG(env->arg2))
			champ->reg[env->arg2] = env->arg1;
		else if (IS_IND(nbr[0]) && IS_IN_REG(env->arg2))
			champ->reg[env->arg2] =
				env->map[ft_mod(champ->pc - 1 + env->arg1, M)];
		if (IS_IN_REG(env->arg2))
			champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}

void		ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		ft_extract_args(env, pc, nbr);
		if (IS_DIR(nbr[0]) && IS_IN_REG(env->arg2))
			champ->reg[env->arg2] = env->arg1;
		else if (IS_IND(nbr[0]) && IS_IN_REG(env->arg2))
		{
			// wprintw(env->notif, "ARG1 : %d\n", env->arg1);
			// ft_reload_windows(env, 3);

			if (env->arg1 > 32768)
				champ->reg[env->arg2] = env->map[ft_mod(champ->pc - 1 +
				((env->arg1 % I) - I), M)];
			else
				champ->reg[env->arg2] = env->map[ft_mod(champ->pc - 1 +
				(env->arg1 % I), M)];
		}
		if (IS_IN_REG(env->arg2))
			champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}
