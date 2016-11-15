/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:07:03 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 17:12:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strsub() function returns a part of s, starting at start and with
** a length len.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (s == NULL || len > ft_strlen(s) || !(buffer = ft_strnew(len)))
		return (NULL);
	while (i < len && ((char *)s)[start])
	{
		buffer[i] = ((char *)s)[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}
