/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:42:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 13:37:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
# define	ERR_BAD_SRC_FILE			"{9}Error{0} : Can't read source file"
# define	ERR_DIR						"{9}Error{0} : Directories are not allowed"
# define	ERR_NOEXT					"{9}Error{0} : Extension .cor is missing (NOEXT)"
# define	ERR_NOT_COR					"{9}Error{0} : File extension is not .cor"

/******************************************************************************/

/******************************************************************************/

/******************************************************************************/
void			ft_clear_champions(t_champions *champions, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&champions[i].name);
		ft_strdel(&champions[i].comment);
		ft_strdel(&champions[i].content);
		champions[i].magic = 0;
		champions[i].prog_size = 0;
		i++;
	}
}

void			ft_clear_all(t_vm *env)
{
	ft_dbstrdel(env->filename);
	ft_clear_champions(env->champions, env->nb_champ);
	ft_strdel(&env->map);
	free(env->header);
	free(env->champions);
	free(env->fd);
}

void			ft_error_asm(t_vm *env, char *msg, int clear)
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
			ft_error_asm(env, ERR_BAD_SRC_FILE, 0);
		if (open(av[i], O_DIRECTORY) != -1)
			ft_error_asm(env, ERR_DIR, 0);
		if (!ft_strrchr(av[i], '.'))
			ft_error_asm(env, ERR_NOEXT, 0);
		extension = ft_strinit(ft_strrchr(av[i], '.'));
		result = EQU(extension, ".cor");
		ft_strdel(&extension);
		if (result)
			env->filename[y] = ft_strinit(av[i]);
		else
			ft_error_asm(env, ERR_NOT_COR, 0);
		i++;
		y++;
	}
}
/******************************************************************************/

void			ft_put_champion_map(t_vm *env)
{
	t_champions		champion;
	int				i; //CHAMPION NUMBER
	unsigned int	y; //POS IN MAP
	unsigned int	z; //CONTENT OF CHAMP

	i = 0;
	while (i < env->nb_champ)
	{
		champion = env->champions[i];
		y = champion.starting_pos;
		z = 0;
		// ft_printf("[{10}%d{0}] - [{11}%d{0}]\n", champion.prog_size, y);
		while (z < champion.prog_size)
		{
			//SI env->map[y] != 0 -> ERROR
			env->map[y] = champion.content[z];
			z++;
			y++;
		}
		i++;
	}
}

/******************************************************************************/
void			ft_print_map_color(t_vm *env, t_champions *champions, int *i)
{
	char			*hex;

	hex = ft_strinit("0123456789abcdef");
	if (*i >= (int)(champions[0].starting_pos) &&
		*i <= (int)(champions[0].starting_pos + champions[0].prog_size))
			ft_printf("{10}");
	else if (env->nb_champ >= 2 &&
		*i >= (int)(champions[1].starting_pos) &&
		*i <= (int)(champions[1].starting_pos + champions[1].prog_size))
			ft_printf("{11}");
	else if (env->nb_champ >= 3 &&
		*i >= (int)(champions[2].starting_pos) &&
		*i <= (int)(champions[2].starting_pos + champions[2].prog_size))
			ft_printf("{12}");
	else if (env->nb_champ >= 4 &&
		*i >= (int)(champions[3].starting_pos) &&
		*i <= (int)(champions[3].starting_pos + champions[3].prog_size))
			ft_printf("{13}");
	ft_printf("%c", hex[(int)((unsigned char)env->map[*i]) / 16]);
	ft_printf("%c", hex[(int)((unsigned char)env->map[*i]) % 16]);
	*i += 1;
	ft_printf("%c", hex[(int)((unsigned char)env->map[*i]) / 16]);
	ft_printf("%c {0}", hex[(int)((unsigned char)env->map[*i]) % 16]);
	*i += 1;
	ft_strdel(&hex);
}

void			ft_print_map(t_vm *env)
{
	t_champions		*champions;
	int				i;
	int				y;

	champions = (t_champions *)malloc(sizeof(t_champions) * env->nb_champ);
	y = 0;
	while (y < env->nb_champ)
	{
		champions[y] = env->champions[y];
		y++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_print_map_color(env, champions, &i);
		if (i % 64 == 0 && i != 0)
			ft_putchar('\n');
	}
}
/******************************************************************************/

static void		ft_launcher(t_vm *env, char **av, int i)
{
	ft_verif_extension(env, av, i);
	ft_extract_champion(env);
	ft_put_champion_map(env);


	// ft_corewar_func(); //USELESS RIGHT NOW
	int		x = 0;
	while (x < env->nb_champ)
	{
		ft_printf("[{10}%s{0}][{14}%d{0}]\n", env->filename[x], env->fd[x]);
		ft_printf("\t[%s]\n", env->champions[x].name);
		ft_printf("\t[%s]\n", env->champions[x].comment);
		ft_printf("\t[%x]\n", env->champions[x].magic);
		ft_printf("\t[%d]\n", env->champions[x].prog_size);
		ft_printf("\t[%d]\n", env->champions[x].starting_pos);
		x++;
	}
	ft_print_map(env);
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
		ft_error_asm(&env, "{9}Error{0} : No champions", 1);
	else if (ac - i >= 1 && ac - i <= 4)
	{
		ft_init_env(&env, ac - i);
		ft_launcher(&env, av, i);
		ft_clear_all(&env);
	}
	else
		ft_error_asm(&env, "{9}Error{0} : Too many champions", 1);

	free(env.options);
	return (0);
}
