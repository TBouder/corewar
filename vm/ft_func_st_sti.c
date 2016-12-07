/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 23:43:11 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_set_buffer(int nbr)
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
	ft_printf("{9}----ST----{0}\n");
	int		buffer;
	int		arg_reg;
	int		arg_reg_ind;

	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		//Permet d'avancer jusqu'a la fin du premier argument
		buffer = IS_IND(nbr[1]) ? 2 : 1;
		//Recupere le premier argument (Reg)
		arg_reg = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		//Recupere le second argument (Reg ou Indir)
		arg_reg_ind = ft_byte_to_str(&env->map[champ->pc + 2], buffer);
		if (IS_REG(nbr[1]))
			champ->reg[arg_reg_ind] = champ->reg[arg_reg];
		else if (IS_IND(nbr[1]))
			env->map[champ->pc + buffer + (arg_reg_ind % IDX_MOD)] = champ->reg[arg_reg];
	}
}

/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----STI----{0}\n");
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

		sum_idx = arg2 + arg3;

		ft_printf("\033[104mMAP[%d + %d] == [%c]{0}\n", pc, (sum_idx % IDX_MOD), env->map[pc + (sum_idx % IDX_MOD)]);

		env->map[pc + (sum_idx % IDX_MOD)] = champ->reg[arg1];

		ft_printf("\033[104mMAP[%d + %d] == [%c]{0}\n", pc, (sum_idx % IDX_MOD), env->map[pc + (sum_idx % IDX_MOD)]);

	}
}
