/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_st_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:38:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/16 14:37:47 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"
#define IS_GRAPH env->options->flags['g']

static int			ft_set_buffer(int nbr)
{
	if (IS_REG(nbr))
		return (1);
	if (IS_DIR(nbr))
		return (2);
	if (IS_IND(nbr))
		return (2);
	return (0);
}

/*
** Stock la valeur de NBR[0] dans NBR[1]
*/
void	ft_corewar_st(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;

	pc = champ->pc + 1;
	if (IS_REG(nbr[0]) && (IS_REG(nbr[1]) || IS_IND(nbr[1])))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);

		if (IS_REG(nbr[1]))
			champ->reg[env->arg2] = champ->reg[env->arg1];
		else if (IS_IND(nbr[1]))
		{
			env->map[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->reg[env->arg1];
			env->map_owner[(champ->pc - 1 + (env->arg2 % I)) % M] = champ->color;
		}
	}
}

static void		ft_convert(unsigned long long n, char *s, int *index)
{
	char	*str;

	str = ft_strinit("0123456789abcdef");
	if (n < (ULL)16)
	{
		s[*index] = str[n];
		*index += 1;
	}
	else
	{
		ft_convert(n / 16, s, index);
		ft_convert(n % 16, s, index);
	}
	ft_strdel(&str);
}

char			*ft_itoxx(unsigned long long n)
{
	char	*s;
	int		len;
	int		k;

	k = 0;
	len = ft_nbrlen_base(n, 16);
	s = ft_strnew(8);
	ft_convert(n, s, &k);
	return (s);
}


/*
** Stock la valeur de NBR[1] + NBR[2] dans NBR[0]
*/
void	ft_corewar_sti(t_vm *env, t_champions *champ, int *nbr)
{
	int		pc;
	int		sum_idx;

	pc = champ->pc + 1;

	if (IS_REG(nbr[0]) && IS_ALL(nbr[1]) && IS_DIR_REG(nbr[2]))
	{
		env->buf = ft_set_buffer(nbr[0]);
		env->arg1 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[1]);
		env->arg2 = ft_byte_to_str(&env->map[pc], env->buf);
		pc += env->buf;
		env->buf = ft_set_buffer(nbr[2]);
		env->arg3 = ft_byte_to_str(&env->map[pc], env->buf);


		if (IS_IND(nbr[1]))
			env->arg2 = env->map[(champ->pc - 1 + (env->arg2 % I)) % M];
		else if (IS_REG(nbr[1]))
			env->arg2 = champ->reg[env->arg2];
		if (IS_REG(nbr[2]))
			env->arg3 = champ->reg[env->arg3];
		sum_idx = env->arg2 + env->arg3;

		char	*reg;
		char	*regg;
		char	*str_reg;
		int		len;
		int		i;

		reg = ft_strinit("00000000");
		regg = ft_itox((unsigned int)champ->reg[env->arg1]);
		len = ft_printf("%!x", (unsigned int)champ->reg[env->arg1]);
		i = 0;
		while (i < 8 && len)
		{
			reg[7 - i] = regg[len - 1];
			i++;
			len--;
		}

		i = 0;
		int j = 0;
		while (i < 8)
		{
			str_reg = ft_strsub(reg, i, 2);
			env->map[champ->pc - 1 + sum_idx + j] = ft_atoi_base(str_reg, 16);
			i += 2;
			j += 1;
		}
		// env->map[(sum_idx % I) % M] = champ->reg[env->arg1];
		// env->map_owner[(sum_idx % I) % M] = champ->color;
	}
}
