/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/10 21:40:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define LLD_IND_1		(pc + arg1) //PC sur l'instruction suivante
#define LLD_IND_2		(pc - 1 + arg1) //PC sur le dernier argument
#define LLD_IND_3		(arg1) //Position sans prendre en compte le PC
#define LLD_IND_4		(champ->pc + arg1) //Depart du premier arg
#define LLD_IND_5		(champ->pc - 1 + arg1) //Depart de l'instruction courante

#define LD_IND_1		(pc + (arg1 % IDX_MOD)) //PC sur l'instruction suivante
#define LD_IND_2		(pc - 1 + (arg1 % IDX_MOD)) //PC sur le dernier argument
#define LD_IND_3		((arg1 % IDX_MOD)) //Position sans prendre en compte le PC
#define LD_IND_4		(champ->pc + (arg1 % IDX_MOD)) //Depart du premier arg
#define LD_IND_5		(champ->pc - 1 + (arg1 % IDX_MOD)) //Depart de l'instruction courante

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

void		ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LLD----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		arg2 = ft_byte_to_str(&env->map[pc], 1);
		pc++;

		ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, champ->reg[arg2], champ->reg[arg2]);
		if (IS_DIR(nbr[0]))
		{
			champ->reg[arg2] = arg1;
			ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, arg1, arg1);
		}
		else if (IS_IND(nbr[0]))
		{
			champ->reg[arg2] = env->map[LLD_IND_5 % MEM_SIZE];
			ft_put("{10}r%d{0} = env->map[{10}%d{0}]\n", arg2, LLD_IND_5 % MEM_SIZE);
			ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n",
			arg2, env->map[LLD_IND_5 % MEM_SIZE], env->map[LLD_IND_5 % MEM_SIZE]);
		}
		champ->carry = champ->reg[arg2] == 0 ? 1 : 0;
	}
}

void		ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LD----{0}\n");
	int		pc;
	int		buffer;
	int		arg1;
	int		arg2;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[pc], buffer);
		pc += buffer;
		arg2 = ft_byte_to_str(&env->map[pc], 1);
		pc++;

		ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, champ->reg[arg2], champ->reg[arg2]);
		if (IS_DIR(nbr[0]))
		{
			champ->reg[arg2] = arg1 % IDX_MOD;
			ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, arg1 % IDX_MOD, arg1 % IDX_MOD);
		}
		else if (IS_IND(nbr[0]))
		{
			champ->reg[arg2] = env->map[LD_IND_5 % MEM_SIZE];
			ft_put("{10}r%d{0} = env->map[{10}%d{0}]\n", arg2, LD_IND_5 % MEM_SIZE);
			ft_put("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, env->map[LD_IND_5 % MEM_SIZE], env->map[LD_IND_5 % MEM_SIZE]);
		}
		champ->carry = champ->reg[arg2] == 0 ? 1 : 0;
	}
}
