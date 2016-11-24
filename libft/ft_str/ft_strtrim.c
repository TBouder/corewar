/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:07:14 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 10:04:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strtrim() function returns the string s without the white space at
** the beginning and at the end.
*/

#include "../libft.h"
#include <stdlib.h>

static int		count_spaces_st(char const *s)
{
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	while (ft_isspace(s[i]))
	{
		i++;
		spaces++;
	}
	return (spaces);
}

static int		count_spaces_nd(char const *s)
{
	int		j;
	int		spaces;

	j = 1;
	spaces = 0;
	while (ft_isspace(s[ft_strlen(s) - j]))
	{
		j++;
		spaces++;
	}
	return (spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		spaces;

	if (s == NULL)
		return (NULL);
	spaces = count_spaces_st(s) + count_spaces_nd(s);
	str = ft_strsub(s, count_spaces_st(s), ft_strlen(s) - count_spaces_nd(s));
	str[ft_strlen(s) - spaces] = '\0';
	return (str);
}

// char		*ft_strtrim(char const *s)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	j = ft_strlen(s) - 1;
// 	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
// 		i++;
	

// 	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && i < j)
// 	{
// 		ft_printf("str : [%s], char : [%c], strlen : %d, j : %d\n", s, s[j], ft_strlen(s), j);
// 		j--;
// 	}
// 	str = ft_strsub(s, i, j - i + 1);
// 	return (str);
// }