/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 17:46:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define LD_IND_1		(pc + (env->arg1 % IDX_MOD)) //PC sur l'instruction suivante
#define LD_IND_2		(pc - 1 + (env->arg1 % IDX_MOD)) //PC sur le dernier argument
#define LD_IND_3		((arg1 % IDX_MOD)) //Position sans prendre en compte le PC
#define LD_IND_4		(champ->pc + (env->arg1 % IDX_MOD)) //Depart du premier arg
#define LD_IND_5		((champ->pc - 1 + (env->arg1 % IDX_MOD)) % MEM_SIZE) //Depart de l'instruction courante

#define LLD_IND_1		(pc + env->arg1) //PC sur l'instruction suivante
#define LLD_IND_2		(pc - 1 + env->arg1) //PC sur le dernier argument
#define LLD_IND_3		(arg1) //Position sans prendre en compte le PC
#define LLD_IND_4		(champ->pc + env->arg1) //Depart du premier arg
#define LLD_IND_5		((champ->pc - 1 + env->arg1) % MEM_SIZE) //Depart de l'instruction courante


#define FROM_START		(champ->pc - 1 + (env->arg1 % IDX_MOD)) //Depart du premier arg
#define FROM_NEXT		((env->to_next_instruct + (env->arg1 % IDX_MOD)) % MEM_SIZE)

#define FROM_STARTL		(champ->pc - 1 + env->arg1) //Depart du premier arg
#define FROM_NEXTL		((env->to_next_instruct + env->arg1) % MEM_SIZE)

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

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->arg2 = ft_byte_to_str(&env->map[pc], 1);

		if (IS_IND(nbr[0]))
			env->arg1 = env->map[FROM_STARTL];

		champ->reg[env->arg2] = env->arg1;
		champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}

void		ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LD----{0}\n");
	int		pc;

	pc = champ->pc + 1;
	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->arg2 = ft_byte_to_str(&env->map[pc], 1);

		if (IS_IND(nbr[0]))
			env->arg1 = env->map[FROM_START];

		champ->reg[env->arg2] = env->arg1;
		champ->carry = champ->reg[env->arg2] == 0 ? 1 : 0;
	}
}
