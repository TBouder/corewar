/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/11 19:44:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

char	ft_verif_extension(char *source)
{
	int		fd;
	int		len_source;
	char	*extension;



	errno = 0;
	if (source == NULL || (fd = open(source, O_RDONLY)) == -1 || errno != 0)
		ft_error_asm(source);
	extension = ft_strinit(ft_strrchr(source, '.'));

	// len_source = ft_strlen(source);
	len_source = 0;
	char *D = NULL;
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
		: "=&D" (D), "=&r" (len_source)
		: "0" (source)
		: "memory"
	);

	ft_printf("{10}%d{0}",len_source);
	ft_printf("%s -> %d || %s\n",extension, ft_strlen(extension), ft_strsub(source, 0, ft_strlen(source) - ft_strlen(extension)));
	return (EQU(extension, ".s"));
}

int		main(int ac, char **av)
{
	t_asm		*env;
	t_options	*options;
	int			i;

	env = (t_asm *)malloc(sizeof(t_asm));
	options = (t_options *)malloc(sizeof(t_options));
	i = ft_extract_options(av, options);
	if (i == ac)
		ft_usage_asm(av[0]);
	else if (ac - i == 1)
	{
		if (ft_verif_extension(av[i]))
		{
			// ft_transform_file();
			ft_printf("Writing output program to {10}%s{0}\n", av[i]);
		}
		else
			ft_printf("File extension is {9}not .s{0}\n");
	}
	else if (ac - i > 1)
		ft_printf("Multiple args detected. Only {9}one{0} arg needed\n");
	return (0);
}
