/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 20:15:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_corewar_live(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----live----{0}\n");
	nbr = ft_get_size(env, champ, 0);
	count = ft_count_to_next(nbr, 1);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_ld(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;
	int		buffer;
	int		arg_dir_ind;
	int		arg_reg;

	ft_printf("{9}----ld----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 2);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);

	if ((nbr[0] == 11 || nbr[0] == 10) && nbr[1] == 1)
	{
		buffer = nbr[0] == 11 ? 2 : 4; //Permet d'avancer jusqu'a la fin du premier argument

		// arg_dir_ind = ft_byte_to_str(env->map[champ->pc + buffer]); //Recupere le premier argument (Dir ou Indir)
		// arg_reg = ft_byte_to_str(env->map[champ->pc + buffer + 1]); //Recupere le second argument (Reg)

		arg_dir_ind = ft_byte_to_str(&env->map[champ->pc + 1], buffer); //Recupere le premier argument (Dir ou Indir)
		arg_reg = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1); //Recupere le second argument (Reg)

		if (nbr[0] == 10)
			champ->reg[arg_reg] += arg_dir_ind; //Si direct
		else if (nbr[0] == 11)
			champ->reg[arg_reg] += env->map[champ->pc + buffer + arg_dir_ind]; //Si indirect

		champ->carry = champ->reg[arg_reg] == 0 ? 1 : 0;
	}

	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (5);
}

int		ft_corewar_st(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----st----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 3);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);

	return (5);
}
