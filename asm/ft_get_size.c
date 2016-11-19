/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:19:07 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/19 15:18:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_get_args(int code, char **content)
{
	if (code == 1 || code == 9 || code == 12 || code == 15 || code == 16)
	{
		if (content && content[1] && !content[2])
			return (ft_analyse_args_one(code, content[1]));
		return (0);
	}
	else if (code == 2 || code == 3 || code == 13)
	{
		if (content && content[1] && content[2] && !content[3])
			return (ft_analyse_args_two(code, content[1], content[2]));
		return (0);
	}
	else
	{
		if (content && content[1] && content[2] && content[3] && !content[4])
			return (ft_analyse_args_three(code, content[1], content[2], content[3]));
		return (0);
	}
	return (0);
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

void			ft_get_opcode_name(t_asm *env, char **content)
{
	env->fd_cor = 0;
	int		opcode;

	opcode = ft_get_opcode(content[0]);
	env->instruct_size += ft_get_args(opcode, content);

	ft_printf("%s : %d\n", content[0], env->instruct_size);
	// ft_printf("[{11}%s{0}] : [{10}%d{0}]\n", content[0], ft_get_opcode(content[0]));
	// env->instruct_size += ft_put_weight_opname(content[0]);
	// ft_printf("[{10}%s{0}] -> [%d] ", content[0], env->instruct_size);
	// env->instruct_size += ft_put_weight_args(content);
	// ft_printf("[{10}%s{0}] -> [%d]\n", content[0], env->instruct_size);
	// ft_printf("-> [%d]\n", env->instruct_size);

	// while (content[i])
	// {
	// 	ft_printf("[{10}%s{0}]", content[i]);
	// 	i++;
	// }
	// ft_printf("\n");
}

void			ft_get_size(t_asm *env, int i)
{
	char		**content;

	content = ft_strsplit(env->file_content[i], ' ');

	ft_get_opcode_name(env, content);
	ft_printf("[{9}%d{0}]\n", env->instruct_size);
}
