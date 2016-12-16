/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/16 18:32:13 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#define IS_GRAPH env->options->flags['g']

static int			ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

void				ft_put_map_reg(t_vm *env, t_champions *champ, int i, int j)
{
	char			*reg;
	char			*begin_reg;
	char			*sub_reg;
	int				len;

	reg = ft_strinit("00000000");
	begin_reg = ft_itox((unsigned int)champ->reg[env->arg1]);
	len = ft_printf("%!x", (unsigned int)champ->reg[env->arg1]);
	while (i < 8 && len)
	{
		reg[7 - i] = begin_reg[len - 1];
		i++;
		len--;
	}

	i = 0;
	while (i < 8)
	{
		sub_reg = ft_strsub(reg, i, 2);
		env->map[(champ->pc - 1 + env->sum_idx + j) % M] = ft_atoi_base(sub_reg, 16);
		i += 2;
		j += 1;
	}
}

/*
** Stock la valeur de NBR[0] dans NBR[1]
*/
void	ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
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
			champ->reg[env->arg2] = champ->reg[env->arg1];
		else if (IS_IND(nbr[1]))
		{
			ft_put_map_reg(env, champ, 0, 0);
			env->sum_idx = env->arg2 % I;
			// env->map[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->reg[env->arg1];
			env->map_owner[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->color;
		}
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
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


		if (IS_IND(nbr[1]))
			env->arg2 = env->map[(champ->pc - 1 + (env->arg2 % I)) % M];
		else if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		if (IS_REG(nbr[2]))
			env->arg3 = champ->reg[env->arg3];
		env->sum_idx = env->arg2 + env->arg3;

		ft_put_map_reg(env, champ, 0, 0);
	}
}
