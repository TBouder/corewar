/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:32:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/10 14:24:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_extract_flags() function put TRUE for each activ flags
*/

#include "../libft.h"

int			ft_extract_options(char **av, t_options *options)
{
	int		i;
	int		j;
	int		k;
	int		value;

	k = 0;
	while (k <= 122)
		options->flags[k++] = FALSE;
	i = 1;
	while (av[i] && av[i][0] == '-' && ft_isalnum(av[i][1]))
	{
		j = 1;
		while (av[i][j] != '\0' && ft_isalnum(av[i][j]))
		{
			value = av[i][j];
			options->flags[value] = TRUE;
			j++;
		}
		i++;
	}
	return (i);
}
