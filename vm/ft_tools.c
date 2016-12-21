/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:27:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 23:44:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_verif_extension() function checks if the file extension is .cor
*/
void	ft_verif_extension(t_vm *env, char **av, int i)
{
	char	*extension;
	int		result;
	int		y;

	y = 0;
	while (av[i])
	{
		errno = 0;
		if (av[i] == NULL || (env->fd[y] = open(av[i], O_RDONLY)) == -1
			|| errno != 0)
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

/*
** The ft_which_isalive() function checks, for each champion, if it is alive or
** not and remove it if not.
*/
int		ft_which_isalive(t_vm *env)
{
	int		i;
	int		nb_live;

	i = 1;
	nb_live = 0;
	while (i < 4)
	{
		nb_live += env->nb_live[i];
		if (env->nb_live[i] == 0)
			ft_clear_champ(env, i);
		i++;
	}
	return (nb_live);
}

/*
** The ft_one_isalive() function checks if there is at least one champion alive
*/
int		ft_one_isalive(t_vm *env)
{
	t_champions 	*champion;
	t_list			*list;

	list = env->list_champions;
	while (list)
	{
		champion = ((t_champions *)list->content);
		if (champion->exist == TRUE)
		{
			if (champion->is_alive >= 0)
				return (1);
		}
		list = list->next;
	}
	return (0);
}

/*
** The ft_add_champion() function adds a champion in the list, as a copy of
** champ or as a new one.
*/
void	ft_add_champion(t_vm *env, t_champions *champ, int id, int pc)
{
	t_champions	*new_champ;

	new_champ = (t_champions *)malloc(sizeof(t_champions));
	new_champ->id = env->current_id++;
	new_champ->name = champ ? ft_strinit(champ->name) : NULL;
	new_champ->comment = champ ? ft_strinit(champ->comment) : NULL;
	new_champ->content = champ ? ft_strinit(champ->content) : NULL;
	new_champ->magic = champ ? champ->magic : 0;
	new_champ->prog_size = champ ? champ->prog_size : 0;
	new_champ->starting_pos = champ ? champ->starting_pos : 0;
	new_champ->champ_id = id + 1;
	ft_init_reg(new_champ, champ);
	new_champ->reg[1] = champ ? champ->reg[1] : id + 1;
	new_champ->pc = pc;
	new_champ->pc_void = champ ? champ->pc_void : 0;
	new_champ->carry = champ ? champ->carry : FALSE;
	new_champ->is_alive = champ ? champ->is_alive : 1;
	new_champ->exist = champ ? champ->exist : TRUE;
	new_champ->cycle = champ ? champ->cycle : 0;
	new_champ->next_cycle = env->cycle + 1;
	new_champ->is_fork = champ ? 1 : 0;
	new_champ->color = champ ? champ->color : id + 42;
	ft_lststart(&env->list_champions, new_champ, sizeof(t_champions));
	ft_verbose_fork(env, champ, new_champ);
}

/*
** The ft_ret_cycle() function takes an opcode as paramater and according to it,
** returns the number of cycle to perform before calling the next instruction
*/
int		ft_ret_cycle(int op)
{
	if (op == AFF)
		return (2);
	else if (op == LD || op == ST)
		return (5);
	else if (op == AND || op == OR || op == XOR)
		return (6);
	else if (op == LIVE || op == ADD || op == SUB || op == LLD)
		return (10);
	else if (op == ZJMP)
		return (20);
	else if (op == LDI || op == STI)
		return (25);
	else if (op == LLDI)
		return (50);
	else if (op == FORK)
		return (800);
	else if (op == LFORK)
		return (1000);
	return (0);
}
