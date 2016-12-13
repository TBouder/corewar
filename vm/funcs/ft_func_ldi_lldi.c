/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ldi_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 13:20:24 by quroulon         ###   ########.fr       */
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

void		ft_corewar_ldi(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LDI----{0}\n");
	int		pc;
	int		sum_idx;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		ft_put("{9}%d\n{0}", (arg1 % IDX_MOD)); //POSITION DE L'ADRESSE

		if (IS_IND(nbr[0]))
			env->arg1 = env->map[(champ->pc - 1 + env->arg1) % M];
		if (IS_REG(nbr[0]))
			env->arg1 = champ->reg[env->arg1];
		if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];

		sum_idx = env->arg1 + env->arg2; //SERA UNE ADRESSE DANS LAQUELLE ON VA LIRE UNE VALEUR DE LA TAILLE D'UN REGISTRE QU'ON MET DANS REG[env->arg3]

		ft_print_memory(env->map, 80);

		champ->reg[env->arg3] = ft_byte_to_str(&env->map[sum_idx % M], 1);
		ft_put("\033[104mr%d = 0x%x{0}\n", env->arg3, champ->reg[env->arg3]);
	}
}

void		ft_corewar_lldi(t_vm *env, t_champions *champ, int *nbr)
{
	ft_put("{9}----LLDI----{0}\n");
	int		pc;
	int		sum_idx;

	pc = champ->pc + 1;
	if (IS_ALL(nbr[0]) && IS_DIR_REG(nbr[1]) && IS_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);

		if (IS_IND(nbr[0]))
			env->arg1 = env->map[(champ->pc - 1 + env->arg1) % M];
		if (IS_REG(nbr[0]))
			env->arg1 = champ->reg[env->arg1];
		if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];

		sum_idx = env->arg1 + env->arg2; //SERA UNE ADRESSE DANS LAQUELLE ON VA LIRE UNE VALEUR DE LA TAILLE D'UN REGISTRE QU'ON MET DANS REG[env->arg3]

		ft_print_memory(env->map, 80);

		champ->reg[env->arg3] = ft_byte_to_str(&env->map[(sum_idx % I) % M], 1);
		ft_put("\033[104mr%d = 0x%x{0}\n", env->arg3, champ->reg[env->arg3]);
	}
}