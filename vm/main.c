/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:42:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/13 18:13:15 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
# define	ERR_BAD_SRC_FILE			"{9}Error{0} : Can't read source file"
# define	ERR_DIR						"{9}Error{0} : Directories are not allowed"
# define	ERR_NOEXT					"{9}Error{0} : Extension .cor is missing (NOEXT)"
# define	ERR_NOT_COR					"{9}Error{0} : File extension is not .cor"
# define	IS_GRAPH env.options->flags['g']

void			ft_clear_champions(t_champions **champions, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&champions[i]->name);
		ft_strdel(&champions[i]->comment);
		ft_strdel(&champions[i]->content);
		champions[i]->magic = 0;
		champions[i]->prog_size = 0;
		i++;
	}
}

void			ft_clear_all(t_vm *env)
{
	ft_dbstrdel(env->filename);
	// ft_clear_champions(env->champions, env->nb_champ);
	ft_strdel(&env->map);
	free(env->header);
	// free(env->champions);
	free(env->fd);
}

void			ft_error_vm(t_vm *env, char *msg, int clear)
{
	ft_printf("{9}%s{0}\n", msg);
	if (clear == 1)
		ft_clear_all(env);
	free(env->options);
	exit(1);
}

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

static void		ft_put_champion_map(t_vm *env)
{
	t_list			*list;
	t_champions		*champion;
	int				i; //CHAMPION NUMBER
	unsigned int	y; //POS IN MAP
	unsigned int	z; //CONTENT OF CHAMP

	i = 0;
	list = env->list_champions;
	while (i < env->nb_champ)
	{
		champion = ((t_champions *)list->content);
		y = champion->starting_pos;
		z = 0;
		while (z < champion->prog_size)
		{
			//SI env->map[y] != 0 -> ERROR
			env->map[y] = champion->content[z];
			z++;
			y++;
		}
		i++;
		list = list->next;
	}
}

static void		ft_launcher(t_vm *env, char **av, int i)
{
	t_list		*list;
	ft_verif_extension(env, av, i);
	ft_extract_champion(env);
	ft_put_champion_map(env);

	int		x = 0;
	list = env->list_champions;
	while (list)
	{
		ft_printf("[{10}%s{0}][{14}%d{0}]\n", env->filename[x], env->fd[x]);
		ft_printf("\t[%s]\n", ((t_champions *)list->content)->name);
		ft_printf("\t[%s]\n", ((t_champions *)list->content)->comment);
		ft_printf("\t[%x]\n", ((t_champions *)list->content)->magic);
		ft_printf("\t[%d]\n", ((t_champions *)list->content)->prog_size);
		ft_printf("\t[%d]\n", ((t_champions *)list->content)->starting_pos);
		list = list->next;
		x++;
	}

	ft_fight(env);
}

int				main(int ac, char **av)
{
	t_vm		env;
	int			i;

	ft_init_env(&env, 0);
	env.options = (t_options *)malloc(sizeof(t_options));
	i = ft_extract_options(av, env.options);
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
