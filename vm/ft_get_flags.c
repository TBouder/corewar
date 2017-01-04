/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 12:00:35 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/03 20:04:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_init_options(t_options *options)
{
	int		k;

	k = 0;
	while (k < 122)
		options->flags[k++] = FALSE;
}

static void		ft_extract_dump(t_vm *env, char **av, t_options *flag, int *i)
{
	flag->flags['d'] = TRUE;
	*i += 1;
	if (av[*i] && ft_isstrnum(av[*i]))
		env->dump_cycle = ft_atoi(av[*i]);
	else if (!av[*i])
		ft_error_vm(env, "{9}Err{0} : No arg after -d", 0);
	else
		ft_error_vm(env, "{9}Err{0} : Bad arg after -d", 0);
}

static void		ft_extract_fakenb(t_vm *env, char **av, t_options *flag, int *i)
{
	flag->flags['n'] = TRUE;
	*i += 1;
	if (av[*i] && ft_isstrnum(av[*i]))
		env->fake_id[0] = ft_atoi(av[*i]);
	else if (!av[*i])
		ft_error_vm(env, "{9}Err{0} : No arg after -n", 0);
	else
		ft_error_vm(env, "{9}Err{0} : Bad arg after -n", 0);
}

int				ft_get_flags(t_vm *env, char **av, t_options *options)
{
	int		i;
	int		j;
	int		value;

	i = 1;
	ft_init_options(options);
	while (av[i] && av[i][0] == '-' && ft_isalnum(av[i][1]))
	{
		j = 1;
		if (ft_isstrstr(av[i], "-dump") || ft_isstrstr(av[i], "-d"))
			ft_extract_dump(env, av, options, &i);
		else if (ft_isstrstr(av[i], "-n"))
			ft_extract_fakenb(env, av, options, &i);
		else
		{
			while (av[i][j] != '\0' && ft_isalnum(av[i][j]))
			{
				value = av[i][j++];
				value != 'd' ? options->flags[value] = TRUE : 0;
			}
		}
		i++;
	}
	return (i);
}
