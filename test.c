/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:17:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/11/10 16:57:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define  TAILLE 10

// 1 EAX : Utilisé pour les opérations arithmétiques et le stockage de la valeur de retour des appels systèmes.
// 2 EDX : Utilisé pour les opérations arithmétiques et les opérations d'entrée/sortie.
// 3 ECX : registre compteur (counter register)
// 4 EBX : Utilisé comme pointeur de donnée (située dans DS en mode segmenté).

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

//
// int		main(int ac, char **av)
// {
// 	int a = 10;
//     int b = 5;
// 	int c = ft_add(a, b);
// 	int d;
// 	ft_mv(c, &d);
// 	ft_printf("a = %d && b = %d && c = %d && d = %d\n", a, b, c, d);
//     return 0;
// }

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

void	my_strcpy(char * src, char * dest)
{
	int S, D, A;

	__asm__ __volatile__
	(
		"cld\n"               /* ESI++, EDI++ */
		"1:\tlodsb\n"         /* MOVB DS:ESI, AL */
		"stosb\n"             /* MOVB AL, ES:EDI */
		"testb\t%%al,%%al\n"  /* ZF=1 si AL == 0 */
		"jne\t1b"               /* JMP si ZF == 0 */

		:"=&S" (S),"=&D" (D), "=&a" (A)
		:"0" (src),"1" (dest), "2" (0)
		:"memory"
	);
}

int main (void)
{
	char * str1 = (char*) malloc(TAILLE*sizeof(char));
	char * str2 = (char*) malloc(TAILLE*sizeof(char));

	if (!str1 || !str2)
		return EXIT_FAILURE;

	my_strcpy((char*)"foo", str1);
	my_strcpy((char*)"bar", str2);

	if (!my_strcmp(str1, str2))
		ft_printf("Les deux chaines \"%s\" et \"%s\" sont egales.\n", str1, str2);
	else
	ft_printf("Les deux chaines \"%s\" et \"%s\" ne sont pas egales.\n", str1, str2);

	free (str1);
	free (str2);
	return EXIT_SUCCESS;
}
