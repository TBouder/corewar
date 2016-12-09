/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/09 14:42:33 by tbouder          ###   ########.fr       */
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
	return (res);
}

int		*ft_get_size(t_vm *env, t_champions *champ, int is_not_live)
{
	if (is_not_live)
		champ->pc += 1;
	int tmp = ft_byte_to_str(&env->map[champ->pc], 1);
	// ft_put("INT {10}%ld{0}\n", tmp);
	char *tmp2 = ft_itoa_base(tmp, 2);
	// ft_printf("BIN {10}%s{0}\n", tmp2);

	char *bin = ft_strnew(8);
	int len = ft_strlen(tmp2);
	int x = 7;
	while (x >= 0)
	{
		if ((len - 1) >= 0)
			bin[x] = tmp2[len - 1];
		else
			bin[x] = '0';
		x--;
		len--;
	}
	// ft_printf("BIN {10}%s{0}\n", bin);

	return (ft_send_args(bin));
}

int		ft_count_to_next(int *nbr, int op)
{
	int		count;
	int		situ ;

	count = 0; //On saute le code du poids
	if (op == 3 || op == 4 || op == 5 || op == 16)
	 	situ = -42;
	else if (op == 9 || op == 10 || op == 11 || op == 12 || op == 14 || op == 15)
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
	if (count < 0)
		;//YA UN PB, GENRE UNE ERREUR
	if (op == 1)
		count = 4;
	return (count + 1); //On passe a l'arg suivant
}

void		ft_print_arg_count(int *nbr, int count, int pc)
{
	if (0)
	{
		ft_put("ARG N_1 -> {13}%d{0} || ARG N_2 -> {13}%d{0} || ARG N_3 -> {13}%d{0}\n",
		nbr[0], nbr[1], nbr[2]);
		ft_put("COUNT -> {13}%d{0} || PC -> {13}%d{0}\n", count, pc);
	}
}
