/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/06 15:37:47 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_test_helper(char *sbin, int begin)
{
	char		*hex;
	char		*part;

	hex = ft_strnew_hex(1);
	part = ft_strsub(sbin, begin, 2);
	ft_printf("{9}%s{0}\n", sbin);

	if (!part)
		return ;

	hex[0] += ft_atoi_base(part, 2);

	if (hex[0] == 1)
		ft_printf("{10}1 er arg est un registre{0} : %x\n", hex[0]);
	else if (hex[0] == 2)
		ft_printf("{10}1 er arg est une valeur directe{0} : %x\n", hex[0]);
	else if (hex[0] == 3)
		ft_printf("{10}1 er arg est une valeur indirecte{0} : %x\n", hex[0]);

	ft_strdel(&hex);
	ft_strdel(&part);
}

void			ft_count_to_next(t_vm *env, t_champions *champ, int op)
{
	char		*hex;
	char		*sbin;

	if (op == 1 && op == 9 && op == 12 && op == 15 && op == 16)
		return ;
	sbin = ft_itoa_base(env->map[champ->pc + 1], 2);

	ft_test_helper(sbin, 0);
	ft_test_helper(sbin, 2);
	ft_test_helper(sbin, 4);
	ft_test_helper(sbin, 6);
}

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

int		*ft_get_size(t_vm *env, t_champions *champ, int is_not_live)
{
	char	*value;
	char	*hex;

	hex = ft_strinit("0123456789abcdef");
	value = ft_strnew(2);
	if (is_not_live)
		champ->pc += 1;
	value[0] = hex[(int)((unsigned char)env->map[champ->pc]) / 16];
	value[1] = hex[(int)((unsigned char)env->map[champ->pc]) % 16];
	int tmp = ft_atoi_base(value, 16);
	ft_printf("INT {10}%ld{0}\n", tmp);
	char *tmp2 = ft_itoa_base(tmp, 2);
	ft_printf("BIN {10}%s{0}\n", tmp2);

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
	ft_printf("BIN {10}%s{0}\n", bin);

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

int		ft_corewar_live(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----live----{0}\n");
	// nbr = ft_get_size(env, champ, 0);
	count = ft_count_to_next(env, champ, 1);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_ld(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----ld----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 2);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (5);
}

int		ft_corewar_st(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----st----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 3);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);

	return (5);
}

int		ft_corewar_add(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----add----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 4);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_sub(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----sub----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 5);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_and(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----and----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 6);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (6);
}

int		ft_corewar_or(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----or----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 7);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (6);
}

int		ft_corewar_xor(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----xor----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 8);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (6);
}

int		ft_corewar_zjmp(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----zjmp----{0}\n");
	nbr = ft_get_size(env, champ, 0);
	count = ft_count_to_next(nbr, 9);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (20);
}

int		ft_corewar_ldi(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----ldi----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 10);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (25);
}

int		ft_corewar_sti(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----sti----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 11);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (25);
}

int		ft_corewar_fork(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----fork----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 12);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (800);
}

int		ft_corewar_lld(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----lld----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 13);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (10);
}

int		ft_corewar_lldi(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----lldi----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 14);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (50);
}

int		ft_corewar_lfork(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----lfork----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 15);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (1000);
}

int		ft_corewar_aff(t_vm *env, t_champions *champ)
{
	int		*nbr;
	int		count;

	ft_printf("{9}----aff----{0}\n");
	nbr = ft_get_size(env, champ, 1);
	count = ft_count_to_next(nbr, 16);
	ft_printf("ARG N_1 -> {13}%d{0}\n", nbr[0]);
	ft_printf("ARG N_2 -> {13}%d{0}\n", nbr[1]);
	ft_printf("ARG N_3 -> {13}%d{0}\n", nbr[2]);
	ft_printf("COUNT -> {13}%d{0}\n", count);
	champ->pc += count; //(+1 pour l'oct avec le poids ds args, +1 pour passer a l'arg suivant)
	ft_printf("PC -> {13}%d{0}\n", champ->pc);
	return (2);
}
