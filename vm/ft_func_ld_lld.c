/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 23:42:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----LLD----{0}\n");
	int		buffer;
	int		arg_dir_ind;
	int		arg_reg;

	if ((nbr[0] == 11 || nbr[0] == 10) && nbr[1] == 1)
	{
		buffer = nbr[0] == 11 ? 2 : 4; //Permet d'avancer jusqu'a la fin du premier argument
		arg_dir_ind = ft_byte_to_str(&env->map[champ->pc + 1], buffer); //Recupere le premier argument (Dir ou Indir)
		arg_reg = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1); //Recupere le second argument (Reg)
		if (nbr[0] == 10)
			champ->reg[arg_reg] += arg_dir_ind; //Si direct
		else if (nbr[0] == 11)
			champ->reg[arg_reg] += env->map[champ->pc + buffer + arg_dir_ind]; //Si indirect
		champ->carry = champ->reg[arg_reg] == 0 ? 1 : 0;
	}
}

void	ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----LD----{0}\n");
	int		buffer;
	int		arg_dir_ind;
	int		arg_reg;

	if ((nbr[0] == 11 || nbr[0] == 10) && nbr[1] == 1)
	{
		buffer = nbr[0] == 11 ? 2 : 4; //Permet d'avancer jusqu'a la fin du premier argument
		arg_dir_ind = ft_byte_to_str(&env->map[champ->pc + 1], buffer); //Recupere le premier argument (Dir ou Indir)
		arg_reg = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1); //Recupere le second argument (Reg)

		if (nbr[0] == 10)
			champ->reg[arg_reg] = arg_dir_ind % IDX_MOD;
		else if (nbr[0] == 11)
		{
			ft_printf("\033[104mREG [%d] => POS [%d] -> [%c]{0}\n", arg_reg, champ->pc + buffer + (arg_dir_ind % IDX_MOD), champ->reg[arg_reg]);

			champ->reg[arg_reg] = env->map[champ->pc + buffer + (arg_dir_ind % IDX_MOD)];

			ft_printf("\033[104mREG [%d] => POS [%d] -> [%c]{0}\n", arg_reg, champ->pc + buffer + (arg_dir_ind % IDX_MOD), champ->reg[arg_reg]);
		}
			// OR ???
			// champ->reg[arg_reg] += env->map[champ->pc + ((buffer + arg_dir_ind) % IDX_MOD)];
		champ->carry = champ->reg[arg_reg] == 0 ? 1 : 0;
	}
}
