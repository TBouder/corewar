/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:46:27 by quroulon          #+#    #+#             */
/*   Updated: 2017/01/16 12:08:47 by tbouder          ###   ########.fr       */
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

	ft_printf("%s\n", env->filename_new);
	fd = open(env->filename_new, O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		fd = open(env->filename_new, O_CREAT | O_WRONLY, 0600);
	env->fd_cor = fd;
	hex_string = ft_transform_magic(0);
	write(fd, hex_string, MAGIC_LEN);
	ft_strdel(&hex_string);
	hex_string = ft_transform_champ_infos(env->champ_name, PROG_NAME_LENGTH);
	write(fd, hex_string, PROG_NAME_LENGTH);
	ft_strdel(&hex_string);
	ft_edit_size(env->instruct_size, fd, 8);
	hex_string = ft_transform_champ_infos(env->champ_comment, COMMENT_LENGTH);
	write(fd, hex_string, COMMENT_LENGTH);
	ft_strdel(&hex_string);
}

void		ft_parse_file(t_asm *env)
{
	int		cpt;

	cpt = 0;
	ft_init_parse(env);
	while (env->file_content[env->line_nb])
	{
		if (cpt < 2)
		{
			ft_get_champ_infos(env, env->line_nb);
			cpt++;
		}
		else if (cpt >= 2 && !ft_strchr(env->file_content[env->line_nb], '.'))
			ft_get_size(env, env->line_nb);
		else
			ft_error_asm(env, ERR_BAD_SRC_FILE, 1);
		env->line_nb++;
	}
	if (ft_detect_errors(env) == 0)
		ft_put_data(env);
}
