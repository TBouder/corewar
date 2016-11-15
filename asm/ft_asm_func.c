/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:30:25 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/15 14:30:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_strlen_asm(char *str)
{
	char	*d;
	int		len;

	d = NULL;
	__asm__ __volatile__
	(
		"SUB	%%ECX, %%ECX\n"
		"SUB	%%AL, %%AL\n"
		"NOT	%%ECX\n"
		"CLD	\n"
		"REPNE	SCASB\n"
		"NOT	%%ECX\n"
		"DEC	%%ECX\n"
		"MOVL	%%ECX, %1\n"
		: "=&D" (d), "=&r" (len)
		: "0" (str)
		: "memory"
	);
	return (len);
}

char	*ft_strinit_asm(char *str)
{
	char	*dest;
	int		s;
	int		d;
	int		a;

	s = 0;
	d = 0;
	a = 0;
	dest = ft_strnew(ft_strlen_asm(str));
	__asm__ __volatile__
	(
		"CLD		\n"
		"loop:"
			"LODSB	\n"
			"STOSB	\n"
			"TESTB	%%AL, %%AL\n"
			"JNE	loop"
		: "=&S" (s), "=&D" (d), "=&a" (a)
		: "0" (str), "1" (dest), "2" (0)
		: "memory"
	);
	return (dest);
}
