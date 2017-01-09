/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:41:56 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/06 15:26:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isstrstr() function returns 1 if s2 is inside s1 or 0 if it's not.
*/

#include "../libft.h"

int		ft_isstrstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (s2[0] == '\0')
		return (1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}
