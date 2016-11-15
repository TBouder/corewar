/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:31:56 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 14:36:47 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_dbstrnew() function init to null a double tab and return it
*/

#include "../libft.h"

char	**ft_dbstrnew(size_t size)
{
	char		**buffer;
	size_t		i;

	buffer = NULL;
	if (!(buffer = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		buffer[i] = NULL;
		i++;
	}
	return (buffer);
}
