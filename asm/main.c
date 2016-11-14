/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/14 18:13:25 by tbouder          ###   ########.fr       */
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
	dest = ft_strnew(ft_strlen_asm(str));
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


void	ft_test(t_asm *env)
{
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = 0;
	fd = open(env->filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		nb_line++;
	}
	ft_printf("{11}%d{0}\n", nb_line);
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
	int		fd;
	int		result;
	int		len_source;
	char	*extension;

	errno = 0;
	if (source == NULL || (fd = open(source, O_RDONLY)) == -1 || errno != 0)
		ft_error_asm(source);
	extension = ft_strinit_asm(ft_strrchr(source, '.'));
	result = EQU(extension, ".s");
	if (result)
	{
		len_source = ft_strlen_asm(source);
		env->filename = ft_strinit_asm(source);
		env->filename_noext = ft_strsub(source, 0, len_source - 2);
	}
	return (result);
}

int		main(int ac, char **av)
{
	t_asm		env;
	t_options	*options;
	int			i;

	options = (t_options *)malloc(sizeof(t_options));
	i = ft_extract_options(av, options);
	if (i == ac)
		ft_usage_asm(av[0]);
	else if (ac - i == 1)
	{
		if (ft_verif_extension(&env, av[i]))
		{
			// ft_transform_file();
			ft_test(&env);
			ft_printf("%s - %s\n", env.filename, env.filename_noext);
			ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);
			// ft_printf("\033[A"); //CHEAT TO REMOVE LAST \n
			// ft_printf("{A}");
		}
		else
			ft_printf("File extension is {9}not .s{0}\n");
	}
	else if (ac - i > 1)
		ft_printf("Multiple args detected. Only {9}one{0} arg needed\n");
	return (0);
}
