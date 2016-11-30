/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:34:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/30 13:45:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** This function will check if the file extension is correctly .s or send an
** error if it's not.
*/

char			ft_verif_extension(t_asm *env, char *source)
{
	int		result;
	int		len_source;
	char	*extension;

	errno = 0;
	if (source == NULL || (env->fd = open(source, O_RDONLY)) == -1
		|| errno != 0)
		ft_error_asm(env, ERR_BAD_SRC_FILE, 0);
	if (open(source, O_DIRECTORY) != -1)
		ft_error_asm(env, ERR_DIR, 0);
	if (!ft_strrchr(source, '.'))
		ft_error_asm(env, ERR_NOEXT, 0);
	extension = ft_strinit_asm(ft_strrchr(source, '.'));
	result = EQU(extension, ".s");
	if (result)
	{
		len_source = ft_strlen_asm(source);
		env->filename = ft_strinit_asm(source);
		env->filename_noext = ft_strsub(source, 0, len_source - 2);
		env->filename_new = ft_strjoin(env->filename_noext, ".cor");
	}
	ft_strdel(&extension);
	return (result);
}

/*
** Theses functions will check each arguments in each line to detect if it's
** valid of not.
*/

static void		ft_verif_label_direct_err(t_asm *env, char *verif_label)
{
	ft_printf("{9}ERROR{0} : No such label {14}%s{0}", verif_label);
	ft_strdel(&verif_label);
	ft_error_asm(env, "", 1);
}

static int		ft_verif_label_direct(t_asm *env, char *str, int type)
{
	int		i;
	int		ret;
	char	*verif_label;

	ret = 0;
	if (type == 0)
	{
		i = 2;
		verif_label = ft_strjoin(str + 2, ":");
		ft_btreesearch_asm(env->file_labels, verif_label, &ret);
		if (ret == 0)
			ft_verif_label_direct_err(env, verif_label);
		ft_strdel(&verif_label);
		return (1);
	}
	else
	{
		i = 1;
		while (ft_isnumber(str[i]) || str[i] == '-')
			i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

static int		ft_verif_label_indirect(char *str, int type)
{
	int		i;

	i = 1;
	if (type == 0)
	{
		while (ft_isnumber(str[i]))
			i++;
		if (!str[i])
			return (2);
	}
	else
	{
		while ((str[i] >= 97 && str[i] <= 122) || ft_isnumber(str[i]) ||
				str[i] == '-')
			i++;
		if (!str[i])
			return (2);
	}
	return (0);
}

int				ft_verif_label(t_asm *env, char *str)
{
	int		i;
	int		reg_nb;

	i = 0;
	if (str && str[i] == DIRECT_CHAR && str[i + 1] == LABEL_CHAR)
		return (ft_verif_label_direct(env, str, 0));
	else if (str && str[i] == DIRECT_CHAR && str[i + 1] != LABEL_CHAR)
		return (ft_verif_label_direct(env, str, 1));
	else if (str && (ft_isnumber(str[i]) || str[i] == '-'))
		return (ft_verif_label_indirect(str, 0));
	else if (str && str[i] == LABEL_CHAR)
		return (ft_verif_label_indirect(str, 1));
	else if (str && str[i] == 'r')
	{
		if (!ft_isstrnum(str + 1))
			return (0);
		reg_nb = ft_atoi(str);
		if (reg_nb <= REG_NUMBER)
			return (3);
	}
	return (0);
}
