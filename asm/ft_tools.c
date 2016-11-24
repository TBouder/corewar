/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:38:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 14:35:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		count_l(char const *s, char c)
{
	int		letter;
	int		i;

	letter = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		letter++;
	}
	return (letter);
}

char			**ft_split_args(char const *s, char c)
{
	char	**str;
	int		n_words;
	int		i;
	char	n_c[1];

	i = 0;
	n_c[0] = c;
	if (s == NULL)
		return (NULL);
	n_words = 4;
	str = ft_dbstrnew(4);
	if (s[0] == '\0')
		str[i] = ft_strsub(s, 0, count_l(s, c));
	while (n_words-- && s[0] != '\0')
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, count_l(s, c));
		s = s + count_l(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char			**ft_split_instruct(char const *s, char c)
{
	char	**str;
	int		n_words;
	int		i;
	char	n_c[1];

	i = 0;
	n_c[0] = c;
	if (s == NULL)
		return (NULL);
	n_words = 3;
	str = ft_dbstrnew(3);
	if (s[0] == '\0')
		str[i] = ft_strsub(s, 0, count_l(s, c));
	while (*s == c && *s)
		s++;
	str[0] = ft_strsub(s, 0, count_l(s, c));
	s = s + count_l(s, c);
	while (*s == c && *s)
		s++;
	str[1] = ft_strsub(s, 0, ft_strlen(s));
	str[2] = NULL;
	return (str);
}
