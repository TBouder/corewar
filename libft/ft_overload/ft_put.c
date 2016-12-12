/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:19:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 13:19:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	OVERLOAD ft_put(int nbr)
{
	ft_putnbr(nbr);
}

void	OVERLOAD ft_put(char c)
{
	ft_putchar(c);
}

int		OVERLOAD ft_put(const char *format, ...)
{
	va_list		pa;
	int			i;
	int			r_val;

	i = -1;
	r_val = 0;
	va_start(pa, format);
	if (format == NULL)
		return (-1);
	while (format[++i])
	{
		(format[i] == '{') ? ft_color(format, &i) : 0;
		if (!format[i] || (format[i] == '%' && ft_undef(format, i + 1) == 0))
			return (r_val);
		format[i] == '%' && format[i + 1] == '\0' ? r_val-- : 0;
		format[i] == '%' ? 0 : ft_putchar(format[i]);
		if (format[i] == '%' && format[i + 1] && ft_undef(format, i + 1)
			&& (i = ft_printf_conv((char *)format, &pa, &r_val, i + 1)) == -1)
			return (-1);
		r_val++;
	}
	va_end(pa);
	return (r_val);
}
