/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:02:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/10/18 00:33:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstnew() creates a new linked list with content as
** list->content or NULL if there is no content.
*/

#include <stdlib.h>
#include "../libft.h"

t_list		*ft_lstnew(void const *content, size_t c_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = (void*)malloc(c_size);
		ft_memmove(list->content, (void *)content, c_size);
		list->content_size = c_size;
	}
	list->next = NULL;
	return (list);
}
