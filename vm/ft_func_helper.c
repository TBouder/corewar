/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 11:34:14 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		*ft_send_args(char *bin)
{
	int		*nbr;
	char	*first;
	char	*second;
	char	*third;

	nbr = ft_nbrnew(3);
	first = ft_strsub(bin, 0, 2);
	second = ft_strsub(bin, 2, 2);
	third = ft_strsub(bin, 4, 2);
	nbr[0] = ft_atoi(first);
	nbr[1] = ft_atoi(second);
	nbr[2] = ft_atoi(third);
	ft_strdel(&first);
	ft_strdel(&second);
	ft_strdel(&third);
	ft_strdel(&bin);
	return (nbr);
}

int		ft_byte_to_str(char *str, int len)
{
	int		i;
	int		y;
	int		res;
	char	*value;
	char	*hex;

	i = 0;
	y = 0;
	len *= 2;
	hex = ft_strinit("0123456789abcdef");
	value = ft_strnew(len);
	while (i < len)
	{
		value[i] = hex[(int)((unsigned char) str[y]) / 16];
		value[i + 1] = hex[(int)((unsigned char) str[y]) % 16];
		i += 2;
		y++;
	}
	res = ft_atoi_base(value, 16);
	ft_strdel(&value);
	ft_strdel(&hex);
	return (res);
}

int		*ft_get_size(t_vm *env, t_champions *champ)
{
	char	*size;
	char	*bin;
	int		len;
	int		i;

	champ->pc += 1;
	size = ft_itoa_base(ft_byte_to_str(&env->map[champ->pc], 1), 2);
	bin = ft_strnew(8);
	len = ft_strlen(size);
	i = 7;
	while (i >= 0)
	{
		if ((len - 1) >= 0)
			bin[i] = size[len - 1];
		else
			bin[i] = '0';
		i--;
		len--;
	}
	ft_strdel(&size);
	return (ft_send_args(bin));
}

int		ft_count_to_next(int *nbr, int op)
{
	int		count;
	int		situ;

	count = 0;
	situ = 0;
	if (op == 3 || op == 4 || op == 5 || op == 16)
	 	situ = -42;
	else if ((op >= 9 && op <= 12) || op == 14 || op == 15)
	 	situ = 2;
	else if (op == 1 || op == 2 || op == 6 || op == 7 || op == 8 || op == 13)
	 	situ = 4;
	nbr[0] == 1 ? count += 1 : 0;
	nbr[0] == 11 ? count += 2 : 0;
	nbr[0] == 10 ? count += situ : 0;
	nbr[1] == 1 ? count += 1 : 0;
	nbr[1] == 11 ? count += 2 : 0;
	nbr[1] == 10 ? count += situ : 0;
	nbr[2] == 1 ? count += 1 : 0;
	nbr[2] == 11 ? count += 2 : 0;
	nbr[2] == 10 ? count += situ : 0;
	if (op == 1)
		count = 4;
	return (count + 1);
}
