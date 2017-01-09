/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:56:19 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/09 11:49:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The ft_verif_extension() function checks if the file extension is .cor
*/

void	ft_verif_extension(t_vm *env, t_list *champs)
{
	char	*extension;
	int		result;
	int		y;

	y = 0;
	while (champs)
	{
		errno = 0;
		if (!champs->content ||
			(env->fd[y] = open(champs->content, O_RDONLY)) == -1 || errno != 0)
			ft_error_vm(env, ERR_BAD_SRC_FILE, 1);
		if (open(champs->content, O_DIRECTORY) != -1)
			ft_error_vm(env, ERR_DIR, 1);
		if (!ft_strrchr(champs->content, '.'))
			ft_error_vm(env, ERR_NOEXT, 1);
		extension = ft_strinit(ft_strrchr(champs->content, '.'));
		result = EQU(extension, ".cor");
		ft_strdel(&extension);
		if (result)
			env->filename[y] = ft_strinit(champs->content);
		else
			ft_error_vm(env, ERR_NOT_COR, 1);
		y++;
		champs = champs->next;
	}
}

/*
** The ft_verif_fake_id() function checks all IDs and check if there is two time
** the same one (error)
*/

void	ft_verif_fake_id(t_vm *env)
{
	int		i;
	int		y;
	int		id;

	i = 0;
	while (i < env->nb_champ)
	{
		y = i + 1;
		id = env->fake_id[i];
		while (y < env->nb_champ)
		{
			if (id == env->fake_id[y])
				ft_error_vm(env, "{9}ERR{0} : Same id after -n", 0);
			y++;
		}
		i++;
	}
}

/*
** The ft_verif_one_alive() function checks if there is at least one
** champion is alive
*/

int		ft_verif_one_alive(t_vm *env)
{
	int		i;

	i = 1;
	while (i <= env->nb_champ)
	{
		if (env->nb_live[i] > 0)
			return (1);
		i++;
	}
	return (0);
}

/*
** The ft_verif_alives() function checks, for each champion, if it is alive or
** not and remove it if not.
*/

int		ft_verif_alives(t_vm *env)
{
	int		i;
	int		nb_live;
	int		number_of_survivor;

	i = 1;
	nb_live = 0;
	number_of_survivor = 0;
	while (i <= env->nb_champ)
	{
		nb_live += env->nb_live[i];
		if (env->nb_live[i] == 0)
		{
			ft_clear_champ(env, &env->list_champions, i);
			env->nb_live[i] = 0;
		}
		else
			number_of_survivor++;
		i++;
	}
	if (number_of_survivor <= 1)
		ft_verbose_winner(env);
	return (nb_live);
}
