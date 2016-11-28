/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/28 18:43:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_detect_errors(t_asm *env)
{
	if (!env->champ_name)
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	else if (!env->champ_comment)
		ft_error_asm(env, ERR_NOCHAMP_COMMENT, 1);
	return (0);
}

void		ft_put_data(t_asm *env)
{
	int		fd;
	char	*hex_string;

	fd = open("test.cor", O_WRONLY, O_CREAT, 0600);

	hex_string = ft_transform_magic();
	write(fd, hex_string, MAGIC_LEN);
	ft_strdel(&hex_string);

	hex_string = ft_transform_champ_infos(env->champ_name, PROG_NAME_LENGTH);
	write(fd, hex_string, PROG_NAME_LENGTH);
	ft_strdel(&hex_string);

	ft_transform_size(env->instruct_size, fd);

	hex_string = ft_transform_champ_infos(env->champ_comment, COMMENT_LENGTH);
	write(fd, hex_string, COMMENT_LENGTH);
	ft_strdel(&hex_string);
}

int		**ft_dbnbrnew(size_t size, size_t sub_size)
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

void		ft_parse_file(t_asm *env)
{
	int		cpt;

	cpt = 0;
	// Contient X case (X = nombre de ligne) et chaque ligne contient 4 cases
	//	[Poids OPCODE][POIDS ARG1][POIDS ARG2][POIDS ARG3]
	env->arg_weight = ft_dbnbrnew(env->file_len, 4);
	// Contient X case (X = nombre de ligne) et chaque ligne a la valeur apres l'opcode
	int i = 0;
	env->opcode_next = ft_dbstrnew(env->file_len);
	while (i < env->file_len)
	{
		env->opcode_next[i] = ft_strnew(8);
		i++;
	}


	while (env->file_content[env->line_nb])
	{
		if (cpt < 2)
		{
			ft_get_champ_infos(env, env->line_nb);
			cpt++;
		}
		else if (cpt >= 2 && ft_strchr(env->file_content[env->line_nb], '.') == NULL)
			ft_get_size(env, env->line_nb);
		else
			ft_error_asm(env, ERR_BAD_SRC_FILE, 1);
		env->line_nb++;
	}
	if (ft_detect_errors(env) == 0)
		ft_put_data(env);
}
