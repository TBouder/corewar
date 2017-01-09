/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_ncurse_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:32:37 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 09:20:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** The ft_dump_ncurse() function dumps the memory with NCURSE
*/

static t_champions	*ft_get_ncurse_color_champ(t_vm *env, int *col)
{
	t_list		*list;
	t_champions	*champ;

	list = env->list_champions;
	while (list)
	{
		champ = (t_champions *)list->content;
		if (champ && champ->pc == *col)
			return (champ);
		list = list->next;
	}
	return (NULL);
}

static void			ft_ncurse_pc_colors(t_vm *env, int *col, int on)
{
	t_list		*list;
	t_champions	*champ;

	list = env->list_champions;
	while (list)
	{
		champ = (t_champions *)list->content;
		if (champ && champ->pc == *col)
		{
			if (on)
				wattron(env->main, COLOR_PAIR(champ->color + 30) | A_BOLD);
			else
				wattroff(env->main, COLOR_PAIR(champ->color + 30) | A_BOLD);
		}
		list = list->next;
	}
}

static void			ft_ncurse_move_colors(t_vm *env, int *col, int on)
{
	t_champions	*champ;

	champ = ft_get_ncurse_color_champ(env, col);
	if (champ)
	{
		if (on)
			wattron(env->main, COLOR_PAIR(champ->color + 10) | A_BOLD);
		else
			wattroff(env->main, COLOR_PAIR(champ->color + 10) | A_BOLD);
	}
	else
	{
		if (on)
			wattron(env->main, COLOR_PAIR(env->map_owner[*col] + 20) | A_BOLD);
		else
			wattroff(env->main, COLOR_PAIR(env->map_owner[*col] + 20) | A_BOLD);
	}
	env->map_moves[*col]--;
}

void				ft_get_ncurse_color(t_vm *env, int *col, int on)
{
	t_champions	*champ;

	if (env->map_moves[*col])
		ft_ncurse_move_colors(env, col, on);
	else if (env->map_owner[*col])
	{
		champ = ft_get_ncurse_color_champ(env, col);
		if (champ)
		{
			if (on)
				wattron(env->main, COLOR_PAIR(champ->color + 10) | A_BOLD);
			else
				wattroff(env->main, COLOR_PAIR(champ->color + 10) | A_BOLD);
		}
		else
		{
			if (on)
				wattron(env->main, COLOR_PAIR(env->map_owner[*col]) | A_BOLD);
			else
				wattroff(env->main, COLOR_PAIR(env->map_owner[*col]) | A_BOLD);
		}
	}
	ft_ncurse_pc_colors(env, col, on);
}
