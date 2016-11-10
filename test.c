/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:17:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/10 15:45:06 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		main(int ac, char **av)
{
	int a;
    int b = 5;
	char *one;
	char *two = ft_strinit(av[1]);
	//	//movl %edx, %eax means Move the contents of the edx register into the eax register
    asm
	(
		"movl %1, %0"
		: "=&r" (a)
		: "r" (b)
		// : /* liste des modifications */
	);
	// ft_printf("a = %d && b = %d\n", a, b);


	ft_printf("a = %s && b = %s\n", one, two);
    return 0;
}
