/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_print.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 18:40:57 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 14:13:44 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_til_precision(const char *str, t_format *format)
{
	int i;

	if (format->precision_size == 0 && format->precision != '.')
		return (print_str(str, format));
	i = 0;
	while (i < format->precision_size && str[i] != '\0')
	{
		print_char(str[i], format);
		i++;
	}
}

/*
**print string and count till n
*/

void	print_str_till_n(const char *str, t_format *format, int n)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (write(1, &str[i], 1) < 0)
		{
			format->output.error = -1;
			return ;
		}
		else
			format->output.counter++;
		i++;
	}
}

/*
**print padding and count till n
*/

void	print_padding_till_n(char c, t_format *format, int n)
{
	while (n > 0)
	{
		if (write(1, &c, 1) < 0)
			format->output.error = -1;
		else
			format->output.counter++;
		n--;
	}
}

void	print_str(const char *str, t_format *format)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) < 0)
		{
			format->output.error = -1;
			return ;
		}
		else
			format->output.counter++;
		i++;
	}
}

void	print_char(char c, t_format *format)
{
	int num;

	num = write(1, &c, 1);
	if (num < 0)
		format->output.error = -1;
	else
		format->output.counter++;
}
