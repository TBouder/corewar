/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ldi_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 12:42:19 by tbouder          ###   ########.fr       */
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

static void	ft_extract_args(t_vm *env, int pc, int *nbr)
{
	env->buf = ft_set_buffer(nbr[0]);
	env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[1]);
	env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
	pc += env->buf;
	env->buf = ft_set_buffer(nbr[2]);
	env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);
}

static int	ft_edit_args(t_vm *env, t_champions *champ, int *nbr)
{
	if (IS_IND(nbr[0]))
		env->arg1 = env->map[ft_mod(ft_mod(champ->pc - 1 + env->arg1, I), M)];
	else if (IS_REG(nbr[0]) && IS_IN_REG(env->arg1))
		env->arg1 = champ->reg[env->arg1];
	else
		return (0);
	if (IS_REG(nbr[1]) && IS_IN_REG(env->arg2))
		env->arg2 = champ->reg[env->arg2];
	return (1);
}

void		ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);
		if (ft_edit_args(env, champ, nbr) == 0)
			return ;

			// wprintw(env->notif, "Reg : [%d]\n", env->arg3);
			// wprintw(env->notif, "First : [%d]\n", env->arg1);
			// wprintw(env->notif, "Second : [%d]\n", env->arg2);

		env->sum_idx = env->arg1 + env->arg2;
		// ft_put("{10}%d vs %d{0}\n", env->sum_idx, ft_mod(env->sum_idx, I));
		// exit (0);
		// wprintw(env->notif, "Sum : [%d]\n", env->sum_idx);
		// wprintw(env->notif, "Sum_mod : [%d]\n", ft_mod(champ->pc - 1 + env->sum_idx, M));
		ft_reload_windows(env, 3);

		champ->reg[env->arg3] = ft_byte_to_str(&env->map[ft_mod(champ->pc - 1 + env->sum_idx, M)], 4);
	}
}

void		ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		ft_extract_args(env, pc, nbr);

		if (IS_IND(nbr[0]))
			env->arg1 = env->map[ft_mod(champ->pc - 1 + env->arg1, M)];
		else if (IS_REG(nbr[0]) && IS_IN_REG(env->arg1))
			env->arg1 = champ->reg[env->arg1];
		if (IS_REG(nbr[1]) && IS_IN_REG(env->arg2))
			env->arg2 = champ->reg[env->arg2];

		// if (ft_edit_args(env, champ, nbr) == 0)
			// return ;
		env->sum_idx = env->arg1 + env->arg2;
		champ->reg[env->arg3] = ft_byte_to_str(
			&env->map[ft_mod(champ->pc - 1 + env->sum_idx, M)], 4);
	}
}
