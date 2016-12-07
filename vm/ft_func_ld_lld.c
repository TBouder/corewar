/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/07 15:51:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	ft_lld_helper(t_vm *env, t_champions *champ, int *nbr)
{
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

static void	ft_ld_helper(t_vm *env, t_champions *champ, int *nbr)
{
	int		buffer;
	int		arg_dir_ind;
	int		arg_reg;

	if ((nbr[0] == 11 || nbr[0] == 10) && nbr[1] == 1)
	{
		buffer = nbr[0] == 11 ? 2 : 4; //Permet d'avancer jusqu'a la fin du premier argument
		arg_dir_ind = ft_byte_to_str(&env->map[champ->pc + 1], buffer); //Recupere le premier argument (Dir ou Indir)
		arg_reg = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1); //Recupere le second argument (Reg)
		if (nbr[0] == 10)
			champ->reg[arg_reg] += arg_dir_ind % IDX_MOD; //Si direct
		else if (nbr[0] == 11)
			champ->reg[arg_reg] += env->map[champ->pc + (buffer + arg_dir_ind) % IDX_MOD]; //Si indirect
		champ->carry = champ->reg[arg_reg] == 0 ? 1 : 0;
	}
}

int			ft_corewar_ld_lld(t_vm *env, t_champions *champ, int op)
{
	op == 2 ? ft_printf("{9}----ld----{0}\n") : ft_printf("{9}----lld----{0}\n");

	int		*nbr;
	int		count;

	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, op);
	if (op == 2)
		ft_ld_helper(env, champ, nbr);
	else
		ft_lld_helper(env, champ, nbr);
	champ->pc += count;
	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
	nbr[0], nbr[1], nbr[2]);
	ft_printf("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, champ->pc);
	return (op == 2 ? 5 : 25);
}
