/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbstrassign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:31:56 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 14:39:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_dbstrassign() function put a list [lst] in a tab of size [size]
*/

#include "../libft.h"

void	ft_dbstrassign(char **tab, t_list *lst, size_t size)
{
	size_t		i;

	i = 0;
	if (!tab)
		return ;
	while (i < size && lst)
	{
		tab[i] = ft_strinit((char *)lst->content);
		i++;
		lst = lst->next;
	}
}
