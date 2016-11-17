/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:28:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/17 15:55:36 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_itox() function converts the initial hex representation by a string
** pointed to by nb.
*/

#include "../libft.h"

static void		ft_convert(unsigned long long n, char *s, int *index)
{
	char	*str;

	str = ft_strinit("0123456789abcdef");
	if (n < (ULL)16)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_strdel(&str);
		ft_convert(n / 16, s, index);
		ft_convert(n % 16, s, index);
	}
}

char			*ft_itox(unsigned long long n)
{
	char	*s;
	int		len;
	int		k;

	k = 0;
	len = ft_nbrlen(n);
	s = ft_strnew(len + 1);
	ft_convert(n, s, &k);
	return (s);
}
