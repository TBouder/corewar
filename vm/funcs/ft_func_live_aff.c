/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_live_aff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/15 19:15:28 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#define IS_GRAPH env->options->flags['g']

static t_list	*ft_find_live(t_vm *env, int id)
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

void			ft_corewar_live(t_vm *env, t_champions *champ, int *nbr)
{
	int				player_alive;
	t_list			*list;

	if (IS_DIR(nbr[0]))
	{
		player_alive = ft_byte_to_str(&env->map[champ->pc + 1], 4);

		if ((list = ft_find_live(env, player_alive)))
		{
			((t_champions *)list->content)->is_alive += 1;
			if (IS_GRAPH)
			{
				ft_print_champion_color(((t_champions *)list->content), env->notif);
				wprintw(env->notif, " is alive\n");
				ft_reload_windows(env, 3);
			}
			else
			{
				ft_put("Champion {14}%d{0} ({14}%s{0}) is {10}alive{0}\n",
				player_alive, ((t_champions *)list->content)->name);
			}
			env->total_live++;
		}
	}
}

void			ft_corewar_aff(t_vm *env, t_champions *champ, int *nbr)
{
	int		value;

	if (IS_REG(nbr[0]))
	{
		value = ft_byte_to_str(&env->map[champ->pc + 1], 1);
		if (IS_GRAPH)
		{
			ft_print_champion_color(champ, env->notif);
			wprintw(env->notif, " ask to print r%d : [%C] [0x%x]\n", value,
			champ->reg[value] % 256, champ->reg[value] % 256);
			ft_reload_windows(env, 3);
		}
		else
		{
			ft_put("Champion {14}%d{0} ({14}%s{0}) ask to print ",
			champ->champ_id, champ->name);
			ft_put("{10}r%d{0} : [{10}%C{0}] [{10}0x%x{0}]\n", value,
			champ->reg[value] % 256, champ->reg[value] % 256);
		}

	}
}
