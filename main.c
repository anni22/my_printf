/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 14:34:40 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/31 11:27:45 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int		a = 2;

	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;

	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;

	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";

//  %[flag][width][precision][specifier]

	printf("\n");
	printf("flag testing: %.*i  hi\n", 5, 2 );
	ft_printf("flag testing: %.*i  hi\n", 5, 2);
	printf("\n");
	printf("external input\n");
	printf("%i, %0*.*d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, 15, 5, j, k, l, m, n, c, c, j, j, j);
	ft_printf("%i, %0*.*d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, 15, 5, j, k, l, m, n, c, c, j, j, j);
	printf("\n");
	printf("----------------------------------------------\n\n");

	printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d);
	ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d);
	printf("\n");
	printf("----------------------------------------------\n");

	printf("Simple input test");
	printf("\n");
	ft_printf("Simple input test");
	printf("\n");
	printf("\n");
	printf(" --- Return : %d\n", printf("Simple input test"));
	ft_printf(" --- Return : %d\n", ft_printf("Simple input test"));
	printf("\n");
	printf("----------------------------------------------\n");

	printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d);
	ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d);
	printf("\n");
	printf("----------------------------------------------\n");

	printf(" --- Return : %d\n", printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	ft_printf(" --- Return : %d\n", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	printf("\n");
	
	printf(" --- Return : %d\n", printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r));
	ft_printf(" --- Return : %d\n", ft_printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r));
	//system ("leaks a.out");

	return (0);
}

//gcc main.c c_print.c find_specifier.c ft_my_itoa.c ft_printf.c ft_printf.h s_print.c print_iduxXp.c utilities.c utilities_print.c utilities_print_iduxXp.c