/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_ld_lld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 02:23:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (4);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

/*
**FONCTIONNEL MAIS WHY (Rapport au corewar de gens)
*/
void	ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----LLD----{0}\n");
	int		buffer;
	int		arg1;
	int		arg2;

	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], buffer);

		arg2 = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1);

		ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, champ->reg[arg2], champ->reg[arg2]);
		if (IS_DIR(nbr[0]))
		{
			champ->reg[arg2] += arg1;
			ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, arg1, arg1);
		}
		else if (IS_IND(nbr[0]))
		{
			champ->reg[arg2] += env->map[champ->pc + buffer + arg1];
			ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, env->map[champ->pc + buffer + arg1], env->map[champ->pc + buffer + arg1]);
		}

		champ->carry = champ->reg[arg2] == 0 ? 1 : 0;
	}
}

/*
** Devrait etre le fonctionnement correct en avancant dans le pc en meme temps
*/
/*
void	ft_corewar_lld(t_vm *env, t_champions *champ, int *nbr)
{
ft_printf("{9}----LLD----{0}\n");
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

	if (IS_DIR(nbr[0]))
		champ->reg[arg2] = arg1;
	else if (IS_IND(nbr[0]))
		champ->reg[arg2] = env->map[ + arg1];

	champ->carry = champ->reg[arg2] == 0 ? 1 : 0;
}
}
*/


void	ft_corewar_ld(t_vm *env, t_champions *champ, int *nbr)
{
	ft_printf("{9}----LD----{0}\n");
	int		buffer;
	int		arg1;
	int		arg2;

	if ((IS_IND(nbr[0]) || IS_DIR(nbr[0])) && IS_REG(nbr[1]))
	{
		buffer = ft_set_buffer(nbr[0]);
		arg1 = ft_byte_to_str(&env->map[champ->pc + 1], buffer);
		arg2 = ft_byte_to_str(&env->map[champ->pc + buffer + 1], 1);


		ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, champ->reg[arg2], champ->reg[arg2]);

		if (IS_DIR(nbr[0]))
		{
			champ->reg[arg2] = arg1 % IDX_MOD;
			ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, arg1 % IDX_MOD, arg1 % IDX_MOD);
		}
		else if (IS_IND(nbr[0]))
		{
			champ->reg[arg2] = env->map[champ->pc + buffer + (arg1 % IDX_MOD)];
			ft_printf("{10}r%d{0} = [{10}%c{0}] ([{10}0x%x{0}])\n", arg2, env->map[champ->pc + buffer + (arg1 % IDX_MOD)], env->map[champ->pc + buffer + (arg1 % IDX_MOD)]);
		}
			// OR ???
			// champ->reg[arg2] += env->map[champ->pc + ((buffer + arg1) % IDX_MOD)];
		champ->carry = champ->reg[arg2] == 0 ? 1 : 0;
	}
}
