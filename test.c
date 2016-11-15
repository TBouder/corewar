/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:17:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/11 17:41:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

/*
	int		ft_add(int a, int b)
	{
		int		c;

		__asm__
		(
			"add %1, %2" //ON VA ADDITIONNER
			: "=r" (c) //ET METTRE LE RESULTAT DANS C
			: "r" (a), "0"(b) //A ET B
		);
		return (c);
	}

	void	ft_mv(int a, int *b)
	{
		__asm__
		(
			"movl %1, %0"
			: "=&r" (*b)
			: "r" (a)
		);
	}


	int		main(int ac, char **av)
	{
		int a = 10;
	    int b = 5;
		int c = ft_add(a, b);
		int d;
		ft_mv(c, &d);
		ft_printf("a = %d && b = %d && c = %d && d = %d\n", a, b, c, d);
	    return 0;
	}
*/
/******************************************************************************/

int	my_strcmp(const char * str1,const char * str2)
{
 int S, D, __res;

 __asm__ __volatile__(
        "cld\n"                /* ESI++, EDI++ */
        "1:\tlodsb\n\t"        /* MOV DS:ESI, AL */
        "scasb\n\t"            /* SUB ES:ESI, AL */
        "jne 2f\n\t"           /* JMP si ZF == 0 (ES:EDI != AL) */
        "testb %%al,%%al\n\t"  /* ZF=1 si AL == 0 */
        "jne 1b\n\t"           /* JMP si ZF == 0 => il y a encore des caracteres */
                               /* pour comparer */
        "xorl %%eax,%%eax\n\t" /* (str1 == str2) => __res = 0 */
        "jmp 3f\n"             /* on a termine ! */
        "2:\tmovl $1,%%eax\n\t"
        "jl 3f\n\t"            /* (str1 != str2) et (str1[i] > str2[i]) => __res = 1 */
        "negl %%eax\n"         /* (str1 != str2) et (str1[i] < str2[i]) => __res = -1 */
        "3:"

        :"=&D" (S), "=&S" (S),"=&a" (__res)
        :"0" (str1),"1" (str2), "2" (0)
        :"memory");

 return __res;
}

char	*ft_strinit_asm(char *src)
{
	int S, D, A = 0;
	char	*dest;

	dest = ft_strnew(ft_strlen(src));

	__asm__ __volatile__
	(
		// -> SERT A CLEAR ESI ET EDI
		"cld\n"

		//Loop CORRESPOND A L'ADRESSE
			// On copie le contenu du pointeur ESI (source) de DS et on l'ajoute a AL (accumulateur (zone de stockage))
			// On copie le contenu de AL (accumulateur (zone de stockage)) dans le pointeur EDI (destination) de ES
			// Si AL == 1 alors ZF = 0 sinon ZF = 1
			// Si ZF == 0 alors retourner a loop (au debut de la loop)
		"loop:"
			"LODSB\n"
			"STOSB\n"
			"TESTB %%AL, %%AL\n"
			"JNE loop"

		// Creation d'une dependance de la source, dest et zone de stockage avec le block asm pour que le contenu change avant la fin
		// de la fonction
		: "=&S" (S), "=&D" (D), "=&a" (A)

		// On met src dans S, dest dans D et 0 dans a
		: "0" (src), "1" (dest), "2" (0)

		//PERMET DE PROTECT CAR EN FAISANT LODSL ET STOSL ON NE CONNAIT PAS LE NOMBRE D'OCTETS A COPIER
		: "memory"
	);
	return (dest);
}

int main (void)
{
	char	*str1;
	char	*str2;

	str1 = ft_strinit_asm("foo foo bar foo");
	str2 = ft_strinit_asm("foo foo bar bar");

	if (!my_strcmp(str1, str2))
		ft_printf("Les deux chaines \"%s\" et \"%s\" sont egales.\n", str1, str2);
	else
	ft_printf("Les deux chaines \"%s\" et \"%s\" ne sont pas egales.\n", str1, str2);

	free (str1);
	free (str2);
	return EXIT_SUCCESS;
}
