/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 12:39:07 by tbouder          ###   ########.fr       */
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

void		ft_color_map(t_vm *env, t_champions *champ, int pc, char *sub_reg)
{
	pc %= M;
	// wprintw(env->notif, "PC : [%d] - [%d]\n", pc, ft_atoi_base(sub_reg, 16));
	// ft_reload_windows(env, 3);

	env->map[pc] = ft_atoi_base(sub_reg, 16);
	env->map_owner[pc] = champ->color;
	env->map_moves[pc] = champ->color;
}

void		ft_put_map_reg(t_vm *env, t_champions *champ, int i, int j)
{
	char			*reg;
	char			*begin_reg;
	char			*sub_reg;
	int				len;

	reg = ft_strinit("00000000");
	begin_reg = ft_itox((unsigned int)champ->reg[env->arg1]);
	len = ft_strlen(begin_reg);
	while (i < 8 && len)
	{
		reg[7 - i++] = begin_reg[len - 1];
		len--;
	}
	i = 0;
	// ft_printf("env->map[{9}%ld{0}]\n", (champ->pc - 1 + env->sum_idx + j));
	// wprintw(env->notif, "VALUE : [%d]\n", (champ->pc - 1 + env->sum_idx + j));
	// ft_reload_windows(env, 3);
	while (i < 8)
	{
		sub_reg = ft_strsub(reg, i, 2);
		// ft_color_map(env, champ, (unsigned int)ft_mod((champ->pc - 1 + env->sum_idx + j), M), sub_reg);
		ft_color_map(env, champ, champ->pc - 1 + ft_mod(env->sum_idx + j, I), sub_reg);
		// IS_GRAPH ? ft_color_map(env, champ, ft_mod(champ->pc - 1 + env->sum_idx + j + I, I), sub_reg) : 0;
		i += 2;
		j += 1;
		ft_strdel(&sub_reg);
	}
	ft_strdel(&begin_reg);
	ft_strdel(&reg);
}

/*
** Stock la valeur de NBR[0] dans NBR[1]
*/

void		ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		if (IS_REG(nbr[1]))
		{
			if (IS_IN_REG(env->arg2) && IS_IN_REG(env->arg1))
				champ->reg[env->arg2] = champ->reg[env->arg1];
		}
		else if (IS_IND(nbr[1]))
		{
			if (env->arg2 > MAX)
				env->sum_idx = (env->arg2 % I) - I;
			else
				env->sum_idx = env->arg2 % I;
			if (IS_IN_REG(env->arg1))
				ft_put_map_reg(env, champ, 0, 0);
		}
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/

void		ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		// wprintw(env->notif, "REG : [%d]\n", env->arg1);
		// wprintw(env->notif, "VAL 1 : [%d]\n", ft_mod(env->arg2, I));
		// wprintw(env->notif, "VAL 2 : [%d]\n", env->arg3);
		// ft_reload_windows(env, 3);

		if (IS_IND(nbr[1]) && env->arg2 > MAX)
			env->arg2 = ft_byte_to_str(&env->map[ft_mod(champ->pc + ((env->arg2 % I) - I), M)], 2);
		else if (IS_IND(nbr[1]))
			env->arg2 = ft_byte_to_str(&env->map[ft_mod(champ->pc + (env->arg2 % I), M)], 2);
		else if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		else if (IS_DIR(nbr[1]) && env->arg2 > MAX)
			env->arg2 = env->arg2 % I - I;


		if (IS_REG(nbr[2]))
			env->arg3 = champ->reg[env->arg3];
		// ft_printf("{9}%ld, %ld{0}\n", env->arg2, env->arg3);

		env->sum_idx = env->arg2 + env->arg3;
		wprintw(env->notif, "REG : [%d]\n", env->arg1);
		wprintw(env->notif, "VAL 1 : [%d]\n", env->arg2);
		wprintw(env->notif, "VAL 2 : [%d]\n", env->arg3);
		wprintw(env->notif, "sum_idx : [%d]\n", env->sum_idx);
		wprintw(env->notif, "sum_idx_mod : [%d]\n", ft_mod(env->sum_idx, I) - M);
		ft_reload_windows(env, 3);


		ft_put_map_reg(env, champ, 0, 0);
	}
}
