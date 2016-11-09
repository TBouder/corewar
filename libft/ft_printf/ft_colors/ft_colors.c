/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 19:18:19 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:37:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define O str[*index + 1]
#define T str[*index + 2]
#define R str[*index + 3]
#define F str[*index + 4]
#define V str[*index + 5]

int			ft_ok(char str)
{
	if (ft_isdigit(str) || str == 'r' || str == 'g' || str == 'b' || str == 'y'
		|| str == 'p' || str == 'c' || str == 'w' || str == 'A')
		return (1);
	return (0);
}

static void	ft_print_all_colors(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 15)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[38;5;", i, "m", 9607, i, "\e[0m");
		if (!((i + 1) % 6))
			ft_putchar('\n');
		i++;
	}
	ft_putendl("\n");
	while (i <= 256)
	{
		ft_printf("%s%d%s%C: %d%s\t", "\e[38;5;", i, "m", 9607, i, "\e[0m");
		if (i == 51 || i == 87 || i == 123 || i == 159 || i == 195 || i == 231)
			ft_putstr("\n\n");
		else if (!((j + 1) % 6))
			ft_putstr("\n");
		i++;
		j++;
	}
	ft_putchar('\n');
}

int			ft_color(const char *str, int *index)
{
	int		color;

	if ((ft_ok(O) && T == '}') || (ft_ok(O) && ft_ok(T) && R == '}')
		|| (ft_ok(O) && ft_ok(T) && ft_ok(R) && F == '}'))
	{
		color = ft_atoi(&str[*index + 1]);
		if (O == 'A' && T == '}')
			ft_print_all_colors();
		else if (color == 0)
			write(1, "\e[0m", 4);
		else
			ft_printf("\e[38;5;%dm", color);
		if (O && T && T == '}')
			*index += 3;
		else if (O && T && R && R == '}')
			*index += 4;
		else if (O && T && R && F && F == '}')
			*index += 5;
		return (0);
	}
	index += 1;
	return (1);
}
