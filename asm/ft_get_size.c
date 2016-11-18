/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:19:07 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/18 15:50:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_find_space(char *str, int i)
{
	int		len;

	len = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char			*ft_strsplitt(char *str)
{
	// char	**s;
	int		len;
	int		i;
	int		next_space;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		next_space = ft_find_space(str, i);
		if (next_space == 0)
			break ;
		ft_printf("[{10}%s{0}]", ft_strsub(str, i, next_space));
		i += next_space + 1;
	}
	ft_putchar('\n');
	return NULL;
}

void			ft_get_opcode_name(t_asm *env, char **content)
{
	env->fd_cor = 0;
	int		i;

	i = 0;
	while (content[i])
	{
		ft_printf("[{10}%s{0}]", content[i]);
		i++;
	}
	ft_printf("\n");
}

void			ft_get_size(t_asm *env, int i)
{
	char		**content;

	content = ft_strsplit(env->file_content[i], ' ');

	ft_get_opcode_name(env, content);
}
