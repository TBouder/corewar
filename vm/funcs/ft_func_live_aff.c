/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_live_aff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/24 19:06:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		ft_set_winner(t_vm *env, t_champions *champ)
{
	ft_strdel(&env->winner->name);
	env->winner->name = ft_strinit(champ->name);
	env->winner->champ_id = champ->champ_id;
}

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
		list = ft_find_live(env, player_alive);
		if (list)
		{
			// env->nb_live[((t_champions *)list->content)->champ_id] += 1;
			env->nb_live[((t_champions *)list->content)->champ_id * -1] += 1; //IF NEGATIF
			ft_set_winner(env, (t_champions *)list->content);
			if (IS_GRAPH)
			{
				ft_print_champion_color(((t_champions *)list->content),
					env->notif);
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
