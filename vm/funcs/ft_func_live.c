/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/12 12:27:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		ft_set_winner(t_vm *env, t_champions *champ)
{
	ft_strdel(&env->winner->name);
	env->winner->name = ft_strinit(champ->name);
	env->winner->champ_id = champ->champ_id;
	env->winner->fake_id = champ->fake_id;
}

static t_list	*ft_find_live(t_vm *env, int id)
{
	t_list	*list;

	list = env->list_champions;
	while (list)
	{
		if (((t_champions *)list->content)->fake_id == id)
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
		player_alive = ft_byte_to_str(env, champ->pc + 1, 4);
		if (!(list = ft_find_live(env, player_alive)))
			return ;
		env->nb_live[((t_champions *)list->content)->champ_id] += 1;
		ft_set_winner(env, (t_champions *)list->content);
		if (IS_GRAPH)
		{
			ft_print_champion_color(((t_champions *)list->content), env->notif);
			wprintw(env->notif, " is alive\n");
			ft_reload_windows(env, 3);
		}
		else if (!IS_SILENT)
		{
			ft_printf("Champion {14}%d{0} ({14}%s{0}) is {10}alive{0}\n",
			player_alive, ((t_champions *)list->content)->name);
		}
		env->total_live++;
	}
}
