/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:42:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/14 19:15:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
# define	ERR_BAD_SRC_FILE	"{9}Error{0} : Can't read source file"
# define	ERR_DIR				"{9}Error{0} : Directories are not allowed"
# define	ERR_NOEXT			"{9}Error{0} : Extension .cor is missing (NOEXT)"
# define	ERR_NOT_COR			"{9}Error{0} : File extension is not .cor"
# define	IS_GRAPH env.options->flags['g']

void			ft_verif_extension(t_vm *env, char **av, int i)
{
	char	*extension;
	int		result;
	int		y;

	y = 0;
	while (av[i])
	{
		errno = 0;
		if (av[i] == NULL || (env->fd[y] = open(av[i], O_RDONLY)) == -1 || errno != 0)
			ft_error_vm(env, ERR_BAD_SRC_FILE, 0);
		if (open(av[i], O_DIRECTORY) != -1)
			ft_error_vm(env, ERR_DIR, 0);
		if (!ft_strrchr(av[i], '.'))
			ft_error_vm(env, ERR_NOEXT, 0);
		extension = ft_strinit(ft_strrchr(av[i], '.'));
		result = EQU(extension, ".cor");
		ft_strdel(&extension);
		if (result)
			env->filename[y] = ft_strinit(av[i]);
		else
			ft_error_vm(env, ERR_NOT_COR, 0);
		i++;
		y++;
	}
}
/******************************************************************************/

static void		ft_init_options(t_options *options)
{
	int		k;

	k = 0;
	while (k < 122)
		options->flags[k++] = FALSE;
}

static void		ft_extract_dump(t_vm *env, char **av, t_options *flag, int *i)
{
	flag->flags['d'] = TRUE;
	*i += 1;
	if (ft_isstrnum(av[*i]))
		env->dump_cycle = ft_atoi(av[*i]);
	else
		*i -= 1;
}

static int		ft_get_flags(t_vm *env, char **av, t_options *options)
{
	int		i;
	int		j;
	int		value;

	i = 1;
	ft_init_options(options);
	while (av[i] && av[i][0] == '-' && ft_isalnum(av[i][1]))
	{
		j = 1;
		if (ft_isstrstr(av[i], "-dump") || ft_isstrstr(av[i], "-d"))
			ft_extract_dump(env, av, options, &i);
		else
		{
			while (av[i][j] != '\0' && ft_isalnum(av[i][j]))
			{
				value = av[i][j++];
				options->flags[value] = TRUE;
			}
		}
		i++;
	}
	return (i);
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
			//SI env->map[y] != 0 -> ERROR
			env->map[y] = champion->content[z];
			env->map_owner[y] = champion->color;
			z++;
			y++;
		}
		list = list->next;
	}
}

static void		ft_launcher(t_vm *env, char **av, int i)
{
	ft_verif_extension(env, av, i);
	ft_extract_champion(env);
	ft_put_champion_map(env);
	ft_fight(env);
}

int				main(int ac, char **av)
{
	t_vm		env;
	int			i;

	ft_init_env(&env, 0);
	env.options = (t_options *)malloc(sizeof(t_options));
	i = ft_get_flags(&env, av, env.options);
	if (i == ac)
		ft_error_vm(&env, "{9}Error{0} : No champions", 1);
	else if (ac - i >= 1 && ac - i <= 4)
	{
		IS_GRAPH ? ft_init_ncurse(&env) : 0;

		ft_init_env(&env, ac - i);
		ft_launcher(&env, av, i);
		ft_clear_all(&env);

		IS_GRAPH ? ft_clear_ncurse(&env) : 0;
	}
	else
		ft_error_vm(&env, "{9}Error{0} : Too many champions", 1);

	free(env.options);
	return (0);
}
