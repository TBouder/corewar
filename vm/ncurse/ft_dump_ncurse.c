/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_ncurse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 20:32:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/30 20:35:21 by tbouder          ###   ########.fr       */
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
		if (champ->pc == *col)
			return (champ);
		list = list->next;
	}
	return (NULL);
}

static void			ft_get_ncurse_color_helper(t_vm *env, int *col, int on)
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

static void			ft_get_ncurse_color(t_vm *env, int *col, int on)
{
	t_champions	*champ;

	if (env->map_moves[*col])
		ft_get_ncurse_color_helper(env, col, on);
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
}

static void			ft_print_hex_mem_ncurse(t_vm *env, char *add, size_t size,
				int *col)
{
	size_t		i;
	char		*hex;

	hex = ft_strinit("0123456789abcdef");
	i = 0;
	while (i < 64)
	{
		if (i < size)
		{
			ft_get_ncurse_color(env, col, 1);
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) / 16]);
			wprintw(env->main, "%c", hex[(int)((unsigned char)add[i]) % 16]);
			ft_get_ncurse_color(env, col, 0);
		}
		if (i % 2)
			wprintw(env->main, " ");
		i++;
		*col += 1;
	}
	ft_strdel(&hex);
}

void				ft_dump_ncurse(t_vm *env, const void *addr, size_t size)
{
	int		offset;
	int		owner;

	offset = 0;
	owner = 0;
	while (size > 64)
	{
		ft_print_hex_mem_ncurse(env, (char *)addr + offset, 64, &owner);
		wprintw(env->main, "\n");
		offset += 64;
		size -= 64;
	}
	ft_print_hex_mem_ncurse(env, (char *)addr + offset, size, &owner);
	wprintw(env->main, "\n");
}
