/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/25 15:17:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_detect_errors(t_asm *env)
{
	if (!env->champ_name)
		ft_error_asm(env, ERR_NOCHAMP_NAME, 1);
	else if (!env->champ_comment)
		return (1); //ERROR NO CHAMP COMMENT
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

void		ft_parse_file(t_asm *env)
{
	int		cpt;

	cpt = 0;
	env->instruct_weight = ft_nbrnew(env->file_len);
	while (env->file_content[env->line_nb])
	{
		if (cpt < 2)// && env->file_content[i][0] == '.')
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
