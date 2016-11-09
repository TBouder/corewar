/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/09 16:37:20 by tbouder          ###   ########.fr       */
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
	if (ac == 1)
		ft_usage_asm(av[0]);
	else if (ac >= 2 && ft_verif_extension(av[1]))
		ft_printf("Writing output program to {10}%s{0}\n", av[1]);
	else
		return (0);
	return (0);
}
