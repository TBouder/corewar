/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_and_or_xor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 18:45:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	get_buf(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (4);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

void	ft_and_or_xor_helper(t_vm *env, t_champions *champ, int *nbr, int op)
{
	int		pc;
	int		arg1;
	int		arg2;
	int		reg;
	int		buf;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_ALL(nbr[1]) && IS_REG(nbr[2]))
	{
		arg1 = ft_byte_to_str(&env->map[pc], get_buf(nbr[0]));
		buf = get_buf(nbr[0]);
		if (IS_IND(nbr[0]) == 1)
			arg1 = env->map[pc + buf + (arg1 % IDX_MOD)];
		else if (IS_REG(nbr[0]))
			arg1 = champ->reg[arg1];

		arg2 = ft_byte_to_str(&env->map[pc + buf], get_buf(nbr[1]));
		if (IS_IND(nbr[1]) == 1)
			arg2 = env->map[pc + buf + (arg2 % IDX_MOD)];
		else if (IS_REG(nbr[1]))
			arg2 = champ->reg[arg2];
		buf += get_buf(nbr[1]);

		reg = ft_byte_to_str(&env->map[pc + buf], get_buf(nbr[2]));
		op == 6 ? champ->reg[reg] = arg1 & arg2 : 0;
		op == 7 ? champ->reg[reg] = arg1 | arg2 : 0;
		op == 8 ? champ->reg[reg] = arg1 ^ arg2 : 0;
	}
}



// #define LDI_IND_1	pc + (sum_idx % IDX_MOD) //PC sur l'instruction suivante
// #define LDI_IND_2	pc - 1 + (sum_idx % IDX_MOD) //PC sur le dernier argument
// #define LDI_IND_3	(sum_idx % IDX_MOD) //Position sans prendre en compte le PC
// #define LDI_IND_4	champ->pc + (sum_idx % IDX_MOD) //Depart du premier arg
// #define LDI_IND_5	champ->pc - 1 + (sum_idx % IDX_MOD) //Depart de l'instruction courante
//   buffer = ft_set_buffer(nbr[0]);
// arg1 = ft_byte_to_str(&env->map[pc], buffer);
// pc += buffer;
// buffer = ft_set_buffer(nbr[1]);
// arg2 = ft_byte_to_str(&env->map[pc], buffer);
// pc += buffer;
// arg3 = ft_byte_to_str(&env->map[pc], 1);
// pc++;

void		ft_corewar_and(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----AND----{0}\n");
	ft_and_or_xor_helper(env, champ, nbr, 6);
}

void		ft_corewar_or(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----OR----{0}\n");
	ft_and_or_xor_helper(env, champ, nbr, 7);
}

void		ft_corewar_xor(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----XOR----{0}\n");
	ft_and_or_xor_helper(env, champ, nbr, 8);
}



// }

// int		ft_corewar_and_or_xor(t_vm *env, t_champions *champ, int op)
// {
// 	op == 6 ? ft_printf("{9}----and----{0}\n") :
// 	op == 7 ? ft_printf("{9}----or----{0}\n") :
// 	op == 8 ? ft_printf("{9}----xor----{0}\n") : 0;

// 	int		*nbr;
// 	int		count;

// 	nbr = ft_get_size(env, champ, 1);
// 	count = ft_count_to_next(nbr, op);
// 	ft_and_or_xor_helper(env, champ, nbr, op);
// 	champ->pc += count;

// 	ft_printf("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
// 	nbr[0], nbr[1], nbr[2]);
// 	ft_printf("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, champ->pc);
// 	return (6);
// }
