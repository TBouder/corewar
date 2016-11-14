/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <quroulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:58:43 by quroulon          #+#    #+#             */
/*   Updated: 2016/11/10 19:26:47 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int				main(void)
{
	int a = 10;
	int b = 5;

	// __asm__("movl\t%1, %0"
	// 		: "=&r" (a) : "r" (b)
	// 		);

	//		OPERATION SOURCE, DESTINATION
	__asm__("movl %1, %0" // %1 == %eax, %0 == %ecx
			: "=&r" (a) : "r" (b)
			);

	__asm__("movl $42, %ebx");
	__asm__("movl $42, %eax");
	__asm__("cmp %ebx, %eax");


	// __asm__("msg" : .asciz "Hello");

	__asm__("mov $12, %1");
	__asm__("write str$ (%eax)");

	ft_printf("a = b = %d \n", a);
	return (0);
}