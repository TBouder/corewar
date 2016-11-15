/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 16:05:18 by quroulon         ###   ########.fr       */
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
	free(env->options);
}

static void	ft_init_env(t_asm *env)
{
	env->file_content = NULL;
	env->file_len = 0;

	env->champ_name = NULL;
	env->champ_comment = NULL;
	env->filename = NULL;
	env->filename_noext = NULL;
	env->options = NULL;
}

void	ft_get_file_content(t_asm *env)
{
	t_list	*lst;
	char	*line;

	lst = NULL;
	while (get_next_line(env->fd, &line))
	{
		ft_lstend(&lst, (char *)line, ft_strlen_asm(line) + 1);
		env->file_len++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	env->file_content = ft_dbstrnew(env->file_len);
	ft_dbstrassign(env->file_content, lst, env->file_len);
	ft_lstclr(&lst);
}

void	ft_usage_asm(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n", prog_name);
	ft_printf("\t-a : Instead of creating a .cor file, outputs a stripped and");
	ft_printf("annotated version of the code to the standard output\n");
}

void	ft_error_asm(char *source)
{
	ft_printf("Can't read source file {9}%s{0}\n", source);
	exit(1);
}

char	ft_verif_extension(t_asm *env, char *source)
{
	int		result;
	int		len_source;
	char	*extension;

	errno = 0;
	if (source == NULL || (env->fd = open(source, O_RDONLY)) == -1 || errno != 0)
		ft_error_asm(source);
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
			ft_putdbstr(env.file_content, env.file_len);
			ft_parse_file(&env);
			// ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);
		
			ft_printf("{9}%s{0}\n", env.champ_name);
			ft_printf("{9}%s{0}\n", env.champ_comment);

			ft_clear_all(&env);
		}
		else
			ft_printf("File extension is {9}not .s{0}\n");
	}
	else if (ac - i > 1)
		ft_printf("Multiple args detected. Only {9}one{0} arg needed\n");
	return (0);
}
