/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 15:50:03 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_clear_all(t_asm *env)
{
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_noext);
	ft_strdel(&env->champ_name);
	ft_strdel(&env->champ_comment);
	ft_btreedel(env->file_labels);
	ft_strdel(&env->error_val);
}

void	ft_init_env(t_asm *env)
{
	env->options = NULL;

	env->file_content = NULL;
	env->file_labels = NULL;
	env->file_len = 0;

	env->error_val = NULL;
	env->error_int = 0;

	env->champ_name = NULL;
	env->champ_comment = NULL;
	env->filename = NULL;
	env->filename_noext = NULL;
	env->instruct_size = 0;

	env->hash = NULL;
}

void	ft_usage_asm(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n", prog_name);
}

void	ft_error_asm(t_asm *env, char *msg, int clear)
{
	ft_printf("{9}%s{0}\n", msg);
	if (clear == 1)
		ft_clear_all(env);
	free(env->options);
	exit(1);
}

char	ft_verif_extension(t_asm *env, char *source)
{
	int		result;
	int		len_source;
	char	*extension;

	errno = 0;
	if (source == NULL || (env->fd = open(source, O_RDONLY)) == -1 || errno != 0)
		ft_error_asm(env, ERR_BAD_SRC_FILE, 0);
	if (open(source, O_DIRECTORY) != -1)
		ft_error_asm(env, ERR_DIR, 0);
	if (!ft_strrchr(source, '.'))
		ft_error_asm(env, ERR_NOEXT, 0);
	extension = ft_strinit_asm(ft_strrchr(source, '.'));
	result = EQU(extension, ".s");
	if (result)
	{
		len_source = ft_strlen_asm(source);
		env->filename = ft_strinit_asm(source);
		env->filename_noext = ft_strsub(source, 0, len_source - 2);
	}
	ft_strdel(&extension);
	return (result);
}

int		main(int ac, char **av)
{
	t_asm		env;
	int			i;

	ft_init_env(&env);
	env.options = (t_options *)malloc(sizeof(t_options));
	i = ft_extract_options(av, env.options);
	if (i == ac)
		ft_usage_asm(av[0]);
	else if (ac - i == 1)
	{
		if (ft_verif_extension(&env, av[i]))
		{
			ft_get_file_content(&env);
			if (env.file_len == 0)
				ft_error_asm(&env, ERR_EMPTY_FILE, 1);
			ft_parse_file(&env);

			ft_printf("----------------------------------------------------\n");
			ft_printf("{11}%-17s{0} : [{10}%s{0}]\n", "Champion Name", env.champ_name);
			ft_printf("{11}%-17s{0} : [{10}%s{0}]\n", "Champion Comment", env.champ_comment);
			ft_printf("{11}%-17s{0} : [{10}%d{0}]\n", "File Size", env.instruct_size);
			ft_printf("{11}%-17s{0} : [{10}%x{0}]\n", "Hex Size", env.instruct_size);
			ft_printf("----------------------------------------------------\n");
			ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);

			ft_btree_print_inorder(env.file_labels);

			ft_clear_all(&env);
		}
		else
			ft_error_asm(&env, ERR_NOT_S, 0);
	}
	else if (ac - i > 1)
		ft_error_asm(&env, MULT_ARGS, 0);
	free(env.options);
	return (0);
}
