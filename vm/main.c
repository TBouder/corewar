/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:42:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/27 14:04:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		ft_parse_args(t_vm *env, int i, char **av)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
	while (av[i])
	{
		if (ft_isstrstr(av[i], "-n"))
		{
			i++;
			if (av[i] && ft_isstrnum(av[i]))
				env->fake_id[y++] = ft_atoi(av[i]);
			else if (!av[i])
				ft_error_vm(env, "{9}Err{0} : No arg after -n", 0);
			else
				ft_error_vm(env, "{9}Err{0} : Bad arg after -n", 0);
		}
		else if (av[i])
		{
			if (x == 4)
				ft_error_vm(env, "{9}Error{0} : Too many champions", 0);
			ft_lstend(&env->champs, (char *)av[i], ft_strlen(av[i]) + 1);
			x++;
		}
		i++;
	}
	return (ft_lstlen(env->champs));
}

static void		ft_put_champion_map(t_vm *env)
{
	t_list			*list;
	t_champions		*champion;
	unsigned int	y;
	unsigned int	z;

	list = env->list_champions;
	while (list)
	{
		champion = ((t_champions *)list->content);
		y = champion->starting_pos;
		z = 0;
		while (z < champion->prog_size)
		{
			env->map[y] = champion->content[z];
			env->map_owner[y] = champion->color;
			z++;
			y++;
		}
		champion->next_cycle = ft_ret_cycle((int)env->map[champion->pc]);
		list = list->next;
	}
}

static void		ft_launcher(t_vm *env)
{
	ft_verif_extension(env, env->champs);
	ft_extract_champion(env);
	ft_put_champion_map(env);
	ft_init_lives(env, 1);
	IS_GRAPH ? ft_init_ncurse(env) : 0;
	ft_fight(env);
	IS_GRAPH ? ft_clear_ncurse(env) : 0;
}

int				main(int ac, char **av)
{
	t_vm		env;
	int			i;
	int			nb_champ;

	ft_init_env(&env, 0);
	env.options = (t_options *)malloc(sizeof(t_options));
	i = ft_get_flags(&env, av, env.options);
	if (i == ac)
		ft_error_vm(&env, "{9}Error{0} : No champions", 0);
	else if (ac - i >= 1)
	{
		nb_champ = ft_parse_args(&env, ac - (ac - i), av);
		ft_init_env(&env, nb_champ);
		ft_launcher(&env);
		ft_clear_all(&env);
	}
	free(env.options);
	return (0);
}
