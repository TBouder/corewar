/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:02:29 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/01 13:54:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** First of all, we init the env :
** options :		contains all the flags (if -a, options->flags['a'] == 1)
** file_content :	contains all the usefull lines (without empty ones and all
**					the comments)
** line_nb :		interator that is the current line number
** file_labels :	contains all the labels of the file ("hello:")
** args :			char ** var usefull because of the norm
** error_val :		contains the error message
** error_int :		contains the number of the error_val
** champ_name :		contains the name of the Champion
** comment_name :	contains the comment of the Champion
** instruct_size :	contains the total size of the file
** filename :		contains the full path of the file
** filename_noext :	contains the full path, minus the extension
** filename_new :	contains the full path, with the .cor extension
*/

void			ft_init_env(t_asm *env)
{
	env->options = NULL;
	env->error_val = NULL;
	env->error_int = 0;
	env->filename = NULL;
	env->filename_noext = NULL;
	env->filename_new = NULL;
	env->champ_name = NULL;
	env->champ_comment = NULL;
	env->instruct_size = 0;
	env->file_content = NULL;
	env->file_len = 0;
	env->line_nb = 0;
	env->file_labels = NULL;
	env->opcode_next = NULL;
	env->instruct_weight = NULL;
	env->arg_weight = NULL;
	env->args = NULL;
}

static int		**ft_dbnbrnew(size_t size, size_t sub_size)
{
	int			**buffer;
	size_t		i;

	i = 0;
	if (!(buffer = (int **)malloc(sizeof(int *) * size)))
		return (NULL);
	while (i < size)
	{
		buffer[i] = ft_nbrnew(sub_size);
		i++;
	}
	return (buffer);
}

static char		***ft_trpstrnew(size_t size)
{
	char		***buffer;
	size_t		i;

	i = 0;
	if (!(buffer = (char ***)malloc(sizeof(char **) * size)))
		return (NULL);
	while (i < size)
	{
		buffer[i] = NULL;
		i++;
	}
	return (buffer);
}

void			ft_init_parse(t_asm *env)
{
	int		i;

	i = 0;
	env->instruct_weight = ft_nbrnew(env->file_len);
	env->arg_weight = ft_dbnbrnew(env->file_len, 4);
	env->opcode_next = ft_dbstrnew(env->file_len);
	env->args = ft_trpstrnew(env->file_len);
	while (i < env->file_len)
	{
		env->opcode_next[i] = ft_strnew(8);
		i++;
	}
}

/*
** Init a table of function to avoid if forest and to improve perfs
*/

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
