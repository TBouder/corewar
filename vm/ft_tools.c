/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:27:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/21 12:28:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_verif_extension(t_vm *env, char **av, int i)
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
