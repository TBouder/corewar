/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_live_aff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/12 20:13:23 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_list		*ft_find_live(t_vm *env, int id)
{
	t_list	*list;

	list = env->list_champions;
	while (list)
	{
		if (((t_champions *)list->content)->champ_id == id)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	ft_corewar_live(t_vm *env, t_champions *champ, int *nbr)
{
	int				player_alive;
	t_list			*list;

	ft_put("{9}----LIVE----{0}\n");
	if (IS_DIR(nbr[0]))
	{
		player_alive = ft_byte_to_str(&env->map[champ->pc + 1], 4);

		if ((list = ft_find_live(env, player_alive)))
		{
			((t_champions *)list->content)->is_alive += 1;
			ft_printf("Champion {14}%d{0} ({14}%s{0}) is {10}alive{0}\n",
			player_alive, ((t_champions *)list->content)->name);
		}
	}
}

void	ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr)
{
	int		value;

	ft_put("{9}----AFF----{0}\n");
	if (IS_REG(nbr[0]))
	{
		value = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		ft_put("Champion {14}%d{0} ({14}%s{0}) ask to print {10}r%d{0} : [{10}%C{0}] [{10}0x%x{0}]\n",
		champ->champ_id, champ->name, value, champ->reg[value] % 256, champ->reg[value] % 256);
	}
}
