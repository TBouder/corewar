/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 12:26:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define ST_IND_1		pc + (arg2 % IDX_MOD) //Depart de l'instruction suivant
#define ST_IND_2		pc - buffer + (arg2 % IDX_MOD) //PC sur le dernier argument
#define ST_IND_3		(arg2 % IDX_MOD) //Position sans prendre en compte le PC
#define ST_IND_4		champ->pc + 1 + (arg2 % IDX_MOD) //Depart du premier arg
#define ST_IND_5		champ->pc - 1 + (arg2 % IDX_MOD) //Depart de l'instruction courante
#define ST_IND_OLD		champ->pc + buffer + (arg2 % IDX_MOD) //Avant ces defines

#define STI_IND_1		pc + (sum_idx % IDX_MOD) //Depart de l'instruction suivant
#define STI_IND_2		pc - buffer + (sum_idx % IDX_MOD) //PC sur le dernier argument
#define STI_IND_3		(sum_idx % IDX_MOD) //Position sans prendre en compte le PC
#define STI_IND_4		champ->pc + 1 + (sum_idx % IDX_MOD) //Depart du premier arg
#define STI_IND_5		champ->pc - 1 + (sum_idx % IDX_MOD) //Depart de l'instruction courante
#define STI_IND_OLD		pc + (sum_idx % IDX_MOD) //Avant ces defines

#define STI_ARG_1		pc + (arg2 % IDX_MOD) //Depart de l'instruction suivant
#define STI_ARG_2		pc - buffer + (arg2 % IDX_MOD) //PC sur le dernier argument
#define STI_ARG_3		(arg2 % IDX_MOD) //Position sans prendre en compte le PC
#define STI_ARG_4		champ->pc + 1 + (arg2 % IDX_MOD) //Depart du premier arg
#define STI_ARG_5		champ->pc - 1 + (arg2 % IDX_MOD) //Depart de l'instruction courante


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

/*
** Stock la valeur de NBR[0] dans NBR[1]
*/
void	ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----ST----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		arg1 = ft_byte_to_str(&env->map[pc], 1);
		pc++;
		buffer = ft_set_buffer(nbr[1]);
		arg2 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;

		if (IS_REG(nbr[1]))
		{
			ft_put("{10}r%d{0} = {10}r%d{0}\n", arg2, arg1);
			ft_put("{10}r%d{0} = {10}%d{0}\n", arg2, champ->reg[arg1]);
			champ->reg[arg2] = champ->reg[arg1];
		}
		else if (IS_IND(nbr[1]))
		{
			ft_put("env->map[{10}%d{0}] = {10}r%d{0}\n", ST_IND_5, arg1);
			ft_put("env->map[{10}%d{0}] = {10}%d{0}\n", ST_IND_5, champ->reg[arg1]);
			env->map[ST_IND_5] = champ->reg[arg1];
		}
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----STI----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum_idx;

	pc = champ->pc + 1;

	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		arg1 = ft_byte_to_str(&env->map[pc], 1);
		pc++;
		buffer = ft_set_buffer(nbr[1]);
		arg2 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		buffer = ft_set_buffer(nbr[2]);
		arg3 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;

		if (IS_IND(nbr[1]))
			arg2 = STI_ARG_5;
		if (IS_REG(nbr[1]))
			arg2 = champ->reg[arg2];
		if (IS_REG(nbr[2]))
			arg3 = champ->reg[arg3];
		sum_idx = arg2 + arg3;

		ft_put("\033[104mMAP[%d + %d] == [%c]{0}\n", champ->pc - 1, (sum_idx % IDX_MOD), env->map[STI_IND_5]);
		env->map[STI_IND_5] = champ->reg[arg1];
		ft_put("\033[104mMAP[%d + %d] == [%c]{0}\n", champ->pc - 1, (sum_idx % IDX_MOD), env->map[STI_IND_5]);
	}
}
