/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_live_aff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/08 18:38:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_corewar_live(t_vm *env, t_champions *champ, int *nbr)
{
	if (0)
	{
		env = 0;
		champ = 0;
		nbr = 0;
	}
	ft_put("{9}----LIVE----{0}\n");
}

void	ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr)
{
	int		value;

	ft_put("{9}----AFF----{0}\n");
	if (IS_REG(nbr[0]))
	{
		value = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		ft_put("Champion {14}%d{0} ({14}%s{0}) ask to print {10}r%d{0} : [{10}%c{0}] [{10}0x%x{0}]\n",
		champ->champ_id, champ->name, value, champ->reg[value] % 256, champ->reg[value] % 256);
	}
}
