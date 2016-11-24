/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/24 14:56:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_btreecmp_asm(t_asm *env, t_btree **tree, void const *content, size_t c_size)
{
    if (!(*tree))
	{
		(*tree) = ft_btreenew(content, c_size);
		return ;
	}
    if (CMP((char *)content, (char *)(*tree)->content) < 0)
        ft_btreecmp_asm(env, &(*tree)->left, content, c_size);
	else if (CMP((char *)content, (char *)(*tree)->content) > 0)
        ft_btreecmp_asm(env, &(*tree)->right, content, c_size);
	else
	{
		env->error_int = 1;
		env->error_val = ft_strinit((char *)content);
	}
}

/*
** This function is used to remove all the stuff after [;] or [#] and the white
** spaces
*/
void	ft_strreplace_space(char *str)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = -1;
	while (str[i])
	{
		if (str[i] == ';')
		{
			cpt = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		if (str[i] == ',' && cpt > 0 && (ft_strnstr(str, ".name", cpt) == NULL
			|| ft_strnstr(str, ".comment", cpt) == NULL))
			str[i] = ' ';
		else if (str[i] == ',' && (ft_strstr(str, ".name") == NULL
			|| ft_strnstr(str, ".comment", cpt) == NULL))
			str[i] = ' ';
		i++;
	}
}

char	*ft_remove_end(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	while (str && str[i] && str[i] != ';' && str[i] != '#')
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
	char	*label;
	char	*args;

	len = 0;
	while (final_line[len] && final_line[len] != ' ')
		len++;
	split = NULL;
	label = ft_strsub(final_line, 0, len);
	args = ft_strsub(final_line, len, ft_strlen_asm(final_line));
	if (label[len - 1] == ':')
	{
		ft_btreecmp_asm(env, &env->file_labels, (char *)label, ft_strlen(label) + 1);//ON MET LE LABEL DANS LE BTREE
		split = ft_split_instruct(final_line, ' ');
		if (DIFF(split[1], ""))
		{
			ft_lstend(lst, split[0], ft_strlen(split[0]) + 1);
			ft_lstend(lst, split[1], ft_strlen(split[1]) + 1);
		 	env->file_len++;
		}
		else
			ft_lstend(lst, final_line, ft_strlen_asm(final_line) + 1);
		ft_dbstrdel(split);
	}
	else if (ft_get_opcode(label) != 0 || ft_strstr(label, ".name") || ft_strstr(label, ".comment"))
		ft_lstend(lst, final_line, ft_strlen_asm(final_line) + 1);
	else
	{
		env->error_int = 2;
		env->error_val = ft_strinit(label);
	}
	env->file_len++;
	ft_strdel(&label);
	ft_strdel(&args);
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
				ft_strdel(&tmp1);
			}
		}
		ft_strdel(&line);
		if (env->error_val)
		{
			while (get_next_line(env->fd, &line))
				ft_strdel(&line);
			ft_strdel(&line);
			if (env->error_int == 1)
				ft_printf("{9}Error{0} : redefinition of {14}%s{0}", env->error_val);
			else if (env->error_int == 2)
				ft_printf("{9}Error{0} : Syntax error at token {14}%s{0}", env->error_val);
			ft_lstclr(&lst);
			ft_error_asm(env, "", 1);
		}
	}
	env->file_content = ft_dbstrnew(env->file_len);
	ft_dbstrassign(env->file_content, lst, env->file_len);
	ft_lstclr(&lst);
}
