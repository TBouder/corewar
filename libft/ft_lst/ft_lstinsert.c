/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:54:30 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/03 17:55:46 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstinsert() add the element content at the
** current position of the linked list, and put next as next.
*/

#include "../libft.h"

t_list		*ft_lstinsert(void const *content, size_t c_size, t_list *next)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);

	list->content = (void*)malloc(c_size);
	ft_memmove(list->content, (void *)content, c_size);
	list->content_size = c_size;
	list->next = next;
	return (list);
}
