/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:48:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/29 20:09:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init_champions(t_vm *env)
{
	int		i;

	i = 0;
	while (i < env->nb_champ)
	{
		env->champions[i].name = NULL;
		env->champions[i].comment = NULL;
		env->champions[i].magic = 0;
		env->champions[i].prog_size = 0;
		env->champions[i].content = NULL;
		env->champions[i].starting_pos = 0;
		i++;
	}
}

void			ft_init_env(t_vm *env, int part)
{
	if (part == 0)
	{
		env->options = NULL;
		env->nb_champ = 0;
	}
	else
	{
		env->nb_champ = part;
		env->fd = ft_nbrnew(part);
		env->filename = ft_dbstrnew(part);
		env->header = (header_t *)malloc(sizeof(header_t) * part);
		env->champions = (t_champions *)malloc(sizeof(t_champions) * part);
		env->total_size = 0;
		env->map = ft_strnew(MEM_SIZE);
		ft_init_champions(env);
	}
}
