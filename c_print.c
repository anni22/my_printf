/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 09:57:09 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 17:09:12 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**gets the argument for specifier c
**prints it in the correct format
*/

void			c_print(va_list args, t_format *format)
{
	char	c;
	int		i;

	i = format->width - 1;
	c = va_arg(args, int);
	if (format->side == 'L')
		print_char(c, format);
	while (i > 0)
	{
		print_char(format->padding, format);
		i--;
	}
	if (format->side == 'R')
		print_char(c, format);
}
