/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/22 16:02:29 by tbouder          ###   ########.fr       */
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

char	*ft_remove_end(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != ';' && str[i] != '#')
		i++;
	if (i != 0)
	{
		buff = ft_strsub(str, 0, i);
		return (buff);
	}
	return (NULL);
}

void	ft_get_file_content_helper(t_asm *env, char *final_line, t_list **lst)
{
	int		len;
	char	**split;
	char	*command;
	char	*args;

	len = 0;
	while (final_line[len] && final_line[len] != ' ')
		len++;

	command = ft_strsub(final_line, 0, len);
	args = ft_strsub(final_line, len, ft_strlen_asm(final_line));
	if (command[len - 1] == ':')
	{
		split = ft_split_instruct(final_line, ' ');
		if (DIFF(split[1], ""))
		{
			// ft_printf("{10}[%s] : [%s]{0}\n", split[0], split[1]);
			ft_lstend(lst, split[0], ft_strlen_asm(split[0]) + 1);
			ft_lstend(lst, split[1], ft_strlen_asm(split[1]) + 1);
			env->file_len++;
		}
		else
			ft_lstend(lst, final_line, ft_strlen_asm(final_line) + 1);
	}
	else
	{
		ft_lstend(lst, final_line, ft_strlen_asm(final_line) + 1);
	}

	env->file_len++;
}

void	ft_get_file_content(t_asm *env)
{
	t_list	*lst;
	char	*line;
	char	*tmp1;
	char	*tmp2;

	lst = NULL;
	while (get_next_line(env->fd, &line))
	{
		if (DIFF(line, ""))
		{
			ft_strreplace_space(line);
			tmp1 = ft_strtrim(line);
			tmp2 = ft_remove_end(tmp1);
			ft_strdel(&tmp1);
			if (tmp2)
			{
				tmp1 = ft_strtrim(tmp2);
				ft_strdel(&tmp2);
				ft_get_file_content_helper(env, tmp1, &lst);
				// ft_lstend(&lst, (char *)final_line, ft_strlen_asm(final_line) + 1); //OLD
				// env->file_len++; //OLD
				ft_strdel(&tmp1);
			}
		}
		ft_strdel(&line);
	}
	env->file_content = ft_dbstrnew(env->file_len);
	ft_dbstrassign(env->file_content, lst, env->file_len);
	ft_lstclr(&lst);
}
