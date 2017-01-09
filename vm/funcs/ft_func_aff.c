/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/05 18:54:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr)
{
	int		value;

	if (IS_REG(nbr[0]))
	{
		value = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		if (IS_GRAPH && IN_REG(champ->reg[value]))
		{
			ft_print_champion_color(champ, env->notif);
			wprintw(env->notif, " ask to print r%d : [%C] [0x%x]\n", value,
			champ->reg[value] % 256, champ->reg[value] % 256);
			ft_reload_windows(env, 3);
		}
		else if (!IS_SILENT && IN_REG(champ->reg[value]))
		{
			ft_put("Champion {14}%d{0} ({14}%s{0}) ask to print ",
			champ->champ_id, champ->name);
			ft_put("{10}r%d{0} : [{10}%C{0}] [{10}0x%x{0}]\n", value,
			champ->reg[value] % 256, champ->reg[value] % 256);
		}
	}
}
