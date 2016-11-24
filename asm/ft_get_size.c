/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:19:07 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 15:38:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_init_function_tab(int (*tab[17])())
{
	tab[0] = NULL;
	tab[1] = &ft_opweight_1;
	tab[2] = &ft_opweight_2;
	tab[3] = &ft_opweight_3;
	tab[4] = &ft_opweight_4_5;
	tab[5] = &ft_opweight_4_5;
	tab[6] = &ft_opweight_6_7_8;
	tab[7] = &ft_opweight_6_7_8;
	tab[8] = &ft_opweight_6_7_8;
	tab[9] = &ft_opweight_9_12_15;
	tab[10] = &ft_opweight_10_14;
	tab[11] = &ft_opweight_11;
	tab[12] = &ft_opweight_9_12_15;
	tab[13] = &ft_opweight_13;
	tab[14] = &ft_opweight_10_14;
	tab[15] = &ft_opweight_9_12_15;
	tab[16] = &ft_opweight_16;
}

int				ft_get_opcode(char *opname)
{
	int		opcode;

	opcode = 0;
	opcode == 0 && EQU(opname, "live") ? opcode = 1 : 0;
	opcode == 0 && EQU(opname, "ld") ? opcode = 2 : 0;
	opcode == 0 && EQU(opname, "st") ? opcode = 3 : 0;
	opcode == 0 && EQU(opname, "add") ? opcode = 4 : 0;
	opcode == 0 && EQU(opname, "sub") ? opcode = 5 : 0;
	opcode == 0 && EQU(opname, "and") ? opcode = 6 : 0;
	opcode == 0 && EQU(opname, "or") ? opcode = 7 : 0;
	opcode == 0 && EQU(opname, "xor") ? opcode = 8 : 0;
	opcode == 0 && EQU(opname, "zjmp") ? opcode = 9 : 0;
	opcode == 0 && EQU(opname, "ldi") ? opcode = 10 : 0;
	opcode == 0 && EQU(opname, "sti") ? opcode = 11 : 0;
	opcode == 0 && EQU(opname, "fork") ? opcode = 12 : 0;
	opcode == 0 && EQU(opname, "lld") ? opcode = 13 : 0;
	opcode == 0 && EQU(opname, "lldi") ? opcode = 14 : 0;
	opcode == 0 && EQU(opname, "lfork") ? opcode = 15 : 0;
	opcode == 0 && EQU(opname, "aff") ? opcode = 16 : 0;
	return (opcode);
}

void			ft_btreeequ(t_btree *node, char *content, int *ret)
{
	if (node)
	{
		ft_btreeequ(node->left, content, ret);
		if (EQU(node->content, content))
		{
			*ret = 1;
			return ;
		}
		ft_btreeequ(node->right, content, ret);
	}
}

int				ft_verif_label_direct(t_asm *env, char *str, int type)
{
	int		i;
	int		ret;
	char	*verif_label;

	ret = 0;
	if (type == 0)
	{
		i = 2;
		verif_label = ft_strjoin(str + 2, ":");
		ft_btreeequ(env->file_labels, verif_label, &ret);
		if (ret == 0)
		{
			ft_printf("{9}ERROR{0} : No such label {14}%s{0}", verif_label);
			ft_strdel(&verif_label);
			ft_error_asm(env, "", 1);
		}
		ft_strdel(&verif_label);
		return (1);
	}
	else
	{
		i = 1;
		while (ft_isnumber(str[i]) || str[i] == '-')
			i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

int				ft_verif_label_indirect(char *str, int type)
{
	int		i;

	i = 0;
	if (type == 0)
	{
		i = 1;
		while (ft_isnumber(str[i]))
			i++;
		if (!str[i])
			return (2);
	}
	else
	{
		i = 1;
		while ((str[i] >= 97 && str[i] <= 122) || ft_isnumber(str[i]) ||
				str[i] == '-')
			i++;
		if (!str[i])
			return (2);
	}
	return (0);
}

int				ft_verif_label(t_asm *env, char *str)
{
	int		i;
	int		reg_nb;

	i = 0;
	if (str && str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
		return (ft_verif_label_direct(env, str, 0));
	else if (str && str[i] == DIRECT_CHAR && str[i + 1] != LABEL_CHAR)
		return (ft_verif_label_direct(env, str, 1));
	else if (str && (ft_isnumber(str[i]) || str[i] == '-'))
		return (ft_verif_label_indirect(str, 0));
	else if (str && str[i] == LABEL_CHAR)
		return (ft_verif_label_indirect(str, 1));
	else if (str && str[i] == 'r')
	{
		if (!ft_isstrnum(str + 1))
			return (0);
		reg_nb = ft_atoi(str);
		if (reg_nb <= REG_NUMBER)
			return (3);
	}
	return (0);
}

void			ft_get_size(t_asm *env, int i)
{
	int			(*tab[17])(t_asm *env, char *, char *, char *);
	int			opcode;
	int			arg_value = 0;

	env->args = ft_split_args(env->file_content[i], ' ');
	opcode = ft_get_opcode(env->args[0]);

	ft_init_function_tab(tab);

	if (opcode != 0)
		arg_value = tab[(int)opcode](env, env->args[1], env->args[2], env->args[3]);
	if (arg_value < 0)
	{
		if (arg_value == -1)
			ft_printf("{9}ERROR{0} : One argument of this line is falty [%s]", env->file_content[i]);
		if (arg_value == -2)
			ft_printf("{9}ERROR{0} : Too many arguments for [%s]", env->args[0]);
		ft_error_asm(env, "", 1);
	}
	env->instruct_size += arg_value;
	ft_dbstrdel(env->args);
	env->args = NULL;
}
