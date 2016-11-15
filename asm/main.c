/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 14:30:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*********************************ASM******************************************/
int		ft_strlen_asm(char *str)
{
	char	*d;
	int		len;

	d = NULL;
	__asm__ __volatile__
	(
		"SUB	%%ECX, %%ECX\n"
		"SUB	%%AL, %%AL\n"
		"NOT	%%ECX\n"
		"CLD	\n"
		"REPNE	SCASB\n"
		"NOT	%%ECX\n"
		"DEC	%%ECX\n"
		"MOVL	%%ECX, %1\n"
		: "=&D" (d), "=&r" (len)
		: "0" (str)
		: "memory"
	);
	return (len);
}

char	*ft_strinit_asm(char *str)
{
	char	*dest;
	int		s;
	int		d;
	int		a;

	s = 0;
	d = 0;
	a = 0;
	dest = ft_strnew(ft_strlen(str));
	__asm__ __volatile__
	(
		"CLD		\n"
		"loop:"
			"LODSB	\n"
			"STOSB	\n"
			"TESTB	%%AL, %%AL\n"
			"JNE	loop"
		: "=&S" (s), "=&D" (d), "=&a" (a)
		: "0" (str), "1" (dest), "2" (0)
		: "memory"
	);
	return (dest);
}
/********************************!ASM******************************************/

/********************************LIBFT*****************************************/

char	**ft_dbstrnew(size_t size)
{
	char		**buffer;
	size_t		i;

	buffer = NULL;
	if (!(buffer = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		buffer[i] = NULL;
		i++;
	}
	return (buffer);
}

void	ft_dbstrassign(char **tab, t_list *lst, size_t size)
{
	size_t		i;

	i = 0;
	if (!tab)
		return ;
	while (i < size && lst)
	{
		tab[i] = ft_strinit((char *)lst->content);
		i++;
		lst = lst->next;
	}
}

void	ft_putdbstr(char **tab, size_t size)
{
	size_t		i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		ft_printf("[{10}%s{0}]\n", tab[i]);
		i++;
	}
}

/*******************************!LIBFT*****************************************/

void	ft_clear_all(t_asm *env)
{
	ft_dbstrdel(env->file_content);
	ft_strdel(&env->filename);
	ft_strdel(&env->filename_noext);
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
		ft_lstend(&lst, (char *)line, ft_strlen(line) + 1);
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
	extension = ft_strinit(ft_strrchr(source, '.'));
	result = EQU(extension, ".s");
	if (result)
	{
		len_source = ft_strlen(source);
		env->filename = ft_strinit(source);
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
			// ft_transform_file();
			ft_get_file_content(&env);
			ft_putdbstr(env.file_content, env.file_len);
			// ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);

			ft_clear_all(&env);
		}
		else
			ft_printf("File extension is {9}not .s{0}\n");
	}
	else if (ac - i > 1)
		ft_printf("Multiple args detected. Only {9}one{0} arg needed\n");
	return (0);
}
