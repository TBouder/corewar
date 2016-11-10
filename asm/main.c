/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/10 15:36:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_usage_asm(char *prog_name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n", prog_name);
	ft_printf("\t-a : Instead of creating a .cor file, outputs a stripped and");
	ft_printf("annotated version of the code to the standard output");
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
	len_source = ft_strlen(source);
	extension = ft_strinit(ft_strrchr(source, '.'));
	return (EQU(extension, ".s"));
}

int		main(int ac, char **av)
{
	t_options	*options;
	int			i;

	options = (t_options *)malloc(sizeof(t_options));
	i = ft_extract_options(av, options);
	if (i == ac)
		ft_usage_asm(av[0]);
	else if (ac - i == 1)
	{
		if (ft_verif_extension(av[i]))
			ft_printf("Writing output program to {10}%s{0}\n", av[i]);
		else
			ft_printf("File extension is {9}not .s{0}\n");
	}
	else if (ac - i > 1)
		ft_printf("Multiple args detected. Only {9}one{0} arg needed\n");
	return (0);
}
