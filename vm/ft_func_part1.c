/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:16:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/05 17:41:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_get_size(t_vm *env, t_champions *champ)
{
	char	*value;
	char	*hex;

	hex = ft_strinit("0123456789abcdef");
	value = ft_strnew(2);
	value[0] = hex[(int)((unsigned char)env->map[champ->pc + 1]) / 16];
	value[1] = hex[(int)((unsigned char)env->map[champ->pc + 1]) % 16];
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

	

	return (0);
}

int		ft_corewar_live(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("live\n");
	return (10);
}
int		ft_corewar_ld(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("ld\n");
	ft_get_size(env, champ);

	// ft_printf("{14}%s{0}\n", value);

	// ft_printf("{10}%c", hex[(int)((unsigned char)env->map[champ->pc + 1]) / 16]);
	// ft_printf("%c{0}\n", hex[(int)((unsigned char)env->map[champ->pc + 1]) % 16]);
	// *i += 1;
	// ft_printf("%c", hex[(int)((unsigned char)env->map[*i]) / 16]);
	// ft_printf("%c {0}", hex[(int)((unsigned char)env->map[*i]) % 16]);
	// *i += 1;


	// ft_printf("{10}%x{0}\n", ft_atoi_base(&env->map[champ->pc + 1], 16));
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 2]);
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 3]);
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 4]);
	return (5);
}
int		ft_corewar_st(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("st\n");
	ft_get_size(env, champ);

	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 1]);
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 2]);
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 3]);
	// ft_printf("{10}%x{0}\n", env->map[champ->pc + 4]);
	return (5);
}
int		ft_corewar_add(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("add\n");
	ft_get_size(env, champ);

	return (10);
}
int		ft_corewar_sub(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("sub\n");
	return (10);
}
int		ft_corewar_and(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("and\n");
	return (6);
}
int		ft_corewar_or(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("or\n");
	return (6);
}
int		ft_corewar_xor(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("xor\n");
	return (6);
}
int		ft_corewar_zjmp(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("zjmp\n");
	return (20);
}
int		ft_corewar_ldi(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("ldi\n");
	return (25);
}
int		ft_corewar_sti(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("sti\n");
	return (25);
}
int		ft_corewar_fork(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("fork\n");
	return (800);
}
int		ft_corewar_lld(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("lld\n");
	return (10);
}
int		ft_corewar_lldi(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("lldi\n");
	return (50);
}
int		ft_corewar_lfork(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("lfork\n");
	return (1000);
}
int		ft_corewar_aff(t_vm *env, t_champions *champ)
{
	0 ? env = NULL : 0;
	0 ? champ = NULL : 0;
	ft_printf("aff\n");
	return (2);
}
