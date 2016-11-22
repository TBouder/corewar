/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 10:38:13 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

/*
** This function is used to remove all the stuff after [;] or [#] and the white
** spaces
*/
void	ft_strreplace_space(char *str)
{
	int		i;

	i = 0;
	// ft_printf("{11}%s{0}\n", str);
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		if (str[i] == ',') //////PTETE PAS TOP POUR LA VERIF
			str[i] = ' ';
		i++;
	}
}
char	*ft_remove_end(char *str, char c)
{
	char	*comment;
	char	*sub;
	char	*ret;
	int		string_len;
	int		comment_len;

	comment = ft_strinit(ft_strrchr(str, c));
	if (comment)
	{
		string_len = ft_strlen_asm(str);
		comment_len = ft_strlen_asm(comment);
		sub = ft_strsub(str, 0, string_len - comment_len);
		ret = ft_strtrim(sub);
		ft_strdel(&sub);
		ft_strdel(&comment);
		return (ret);
	}
	ft_strdel(&comment);
	return (ft_strtrim(str));

}

void	ft_clear_all(t_asm *env)
{
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_noext);
	ft_strdel(&env->champ_name);
	ft_strdel(&env->champ_comment);
}

void	ft_init_env(t_asm *env)
{
	env->options = NULL;

	env->file_content = NULL;
	env->file_len = 0;

	env->champ_name = NULL;
	env->champ_comment = NULL;
	env->filename = NULL;
	env->filename_noext = NULL;
	env->instruct_size = 0;
}

void	ft_get_file_content(t_asm *env)
{
	t_list	*lst;
	char	*line;
	char	*tmp;
	char	*final_line;

	lst = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (DIFF(line, ""))
		{
			tmp = ft_remove_end(line, ';');
			final_line = ft_remove_end(tmp, COMMENT_CHAR);
			ft_strreplace_space(final_line);
			if (DIFF(final_line, ""))
			{
				ft_lstend(&lst, (char *)final_line, ft_strlen_asm(final_line) + 1);
				env->file_len++;
			}
			ft_strdel(&tmp);
			ft_strdel(&final_line);
		}
		ft_strdel(&line);
	}
	env->file_content = ft_dbstrnew(env->file_len);
	ft_dbstrassign(env->file_content, lst, env->file_len);
	ft_lstclr(&lst);
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
			ft_printf("{9}[%s]{0}\n", env.champ_name);
			ft_printf("{9}[%s]{0}\n", env.champ_comment);
			ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);
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
