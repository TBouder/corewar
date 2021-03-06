/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:50 by tbouder           #+#    #+#             */
/*   Updated: 2017/01/12 12:40:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_usage_asm(char *prog_name)
{
	ft_printf("Usage: %s [-args (no effects right now)] <sourcefile.s>\n",
		prog_name);
}

void	ft_error_asm(t_asm *env, char *msg, int clear)
{
	ft_printf("{9}%s{0}\n", msg);
	if (clear == 1)
		ft_clear_all(env);
	free(env->options);
	exit(1);
}

void	ft_print_on_success(t_asm env)
{
	int		i;

	i = 0;
	ft_printf("----------------------------------------------------\n");
	ft_printf("{14}%-17s{0} : [{10}%s{0}]\n", "Champion Name", env.champ_name);
	ft_printf("{14}%-17s{0} : [{10}%s{0}]\n", "Champion Comment",
		env.champ_comment);
	ft_printf("{14}%-17s{0} : [{10}%d{0}]\n", "File Size", env.instruct_size);
	ft_printf("{14}%-17s{0} : [{10}%x{0}]\n", "Hex Size", env.instruct_size);
	ft_printf("----------------------------------------------------\n");
	ft_printf("Writing output program to {10}%s{0}.cor\n", env.filename_noext);
}

void	ft_launcher(t_asm *env, char **av, int i)
{
	if (ft_verif_extension(env, av[i]))
	{
		ft_get_file_content(env);
		if (env->file_len <= 2)
			ft_error_asm(env, ERR_EMPTY_FILE, 1);
		ft_parse_file(env);
		ft_write_instructions(env);
		ft_print_on_success(*env);
		ft_clear_all(env);
	}
	else
		ft_error_asm(env, ERR_NOT_S, 0);
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
		ft_launcher(&env, av, i);
	else if (ac - i > 1)
		ft_error_asm(&env, MULT_ARGS, 0);
	free(env.options);
	return (0);
}
