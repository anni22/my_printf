/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 14:31:59 by anspirga      #+#    #+#                 */
/*   Updated: 2020/12/15 18:51:25 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

//printf returns the number of characters printed
int		my_printf(const char *str, ...)
{
	int i;
	int count;
	int print_integer;
	char *integer_string;
	char *print_string;
	va_list list;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				print_string = va_arg(list, char *);
				ft_putstr_fd(print_string, 1);
				i++;
				count = count + ft_strlen(print_string);
			}
			else if (str[i] == 'i')
			{
				print_integer = va_arg(list, int);
				integer_string = ft_itoa(print_integer);
				ft_putnbr_fd(print_integer, 1);
				i++;
				count = count + ft_strlen(integer_string);
			}
			else if (str[i] == '%')
			{
				ft_putchar_fd('%', 1);
				i++;
				count++;
			}
			else if (str[i] != '\0')
			{
				ft_putchar_fd('%', 1);
				ft_putchar_fd(str[i], 1);
				i++;
				count = count + 2;
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(list);
	return (count);
}

int		main(int argc, char *argv[])
{
	char str [] = "hello";
	int num;

	num = 10;
	//my_printf("Hello\n");
	my_printf("String: %s Integer: %i test: %% %", str, num);
	printf("\nString: %s Integer: %i test: %%\n", str, num);
	//my_printf(str);
	//my_printf(argv[0]);
	return (0);
}
