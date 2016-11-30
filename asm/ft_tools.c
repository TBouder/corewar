/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:38:11 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 12:55:27 by tbouder          ###   ########.fr       */
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

	i = 0;
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

	i = 0;
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

/*
** These functions remove all the stuff after [;] or [#] and the white
** spaces
*/

void			ft_strreplace_space(char *str)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == ';')
			break ;
		cpt = i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		if (str[i] == ',' && ft_strnstr(str, ".name", cpt) == NULL
			&& ft_strnstr(str, ".comment", cpt) == NULL)
			str[i] = ' ';
		i++;
	}
}

char			*ft_remove_end(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	while (str && str[i] && str[i] != ';' && str[i] != '#')
		i++;
	if (i != 0)
	{
		buff = ft_strsub(str, 0, i);
		return (buff);
	}
	return (NULL);
}
