/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:27:33 by tbouder           #+#    #+#             */
/*   Updated: 2016/12/05 15:45:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_get_file_content_label(t_asm *env, char *label, char *final_line,
			t_list **lst)
{
	char	**split;

	split = NULL;
	ft_btreecmp_asm(env, &env->file_labels, label, ft_strlen(label) + 1);
	split = ft_split_instruct(final_line, ' ');
	if (ft_valid_label(split[0]) == 0)
	{
		ft_dbstrdel(split);
		ft_error_asm(env, "{9}Err{0} : Incorrect label", 1);
	}
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

static void	ft_get_file_content_help(t_asm *env, char *final_line, t_list **lst)
{
	int		len;
	char	*label;
	char	*args;

	len = 0;
	while (final_line[len] && final_line[len] != ' ')
		len++;
	label = ft_strsub(final_line, 0, len);
	args = ft_strsub(final_line, len, ft_strlen_asm(final_line));
	if (label[len - 1] == ':')
		ft_get_file_content_label(env, label, final_line, lst);
	else if (ft_get_opcode(label) != 0 || ft_strstr(label, ".name")
		|| ft_strstr(label, ".comment"))
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

static void	ft_get_file_content_success(t_asm *env, t_list **lst, char *line)
{
	char	*tmp1;
	char	*tmp2;

	ft_strreplace_space(line);
	tmp1 = ft_strtrim(line);
	tmp2 = ft_remove_end(tmp1);
	ft_strdel(&tmp1);
	if (tmp2)
	{
		tmp1 = ft_strtrim(tmp2);
		ft_strdel(&tmp2);
		ft_get_file_content_help(env, tmp1, lst);
		ft_strdel(&tmp1);
	}
}

static void	ft_get_file_content_error(t_asm *env, t_list **lst)
{
	char	*line;

	while (get_next_line(env->fd, &line))
		ft_strdel(&line);
	if (env->error_int == 1)
		ft_printf("{9}Err{0} : redefinition of {14}%s{0}", env->error_val);
	else if (env->error_int == 2)
		ft_printf("{9}Err{0} : Syntax error at token {14}[%s]{0}",
			env->error_val);
	ft_lstclr(lst);
	ft_error_asm(env, "", 1);
}

void		ft_get_file_content(t_asm *env)
{
	t_list	*lst;
	char	*line;

	lst = NULL;
	while (get_next_line(env->fd, &line) > 0)
	{
		if (DIFF(line, ""))
			ft_get_file_content_success(env, &lst, line);
		ft_strdel(&line);
		if (env->error_val)
			ft_get_file_content_error(env, &lst);
	}
	env->file_content = ft_dbstrnew(env->file_len);
	ft_dbstrassign(env->file_content, lst, env->file_len);
	ft_lstclr(&lst);
}
