/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_print_iduxxp.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 13:22:25 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 14:08:40 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flag0_case(t_format *format,
							int padding_size, int zeros, char *array)
{
	print_padding_till_n(' ', format, padding_size);
	if (format->negative == '-')
		print_char('-', format);
	if (format->ptr == 1)
	{
		print_char('0', format);
		print_char('x', format);
	}
	print_padding_till_n('0', format, zeros);
	print_str(array, format);
}

void	print_if_right(t_format *format, int padding_size, int zeros,
															char *array)
{
	if (format->flag != '0')
		print_padding_till_n(format->padding, format, padding_size);
	if (format->negative == '-')
		print_char('-', format);
	if (format->ptr == 1)
	{
		print_char('0', format);
		print_char('x', format);
	}
	if (format->flag == '0')
		print_padding_till_n(format->padding, format, padding_size);
	print_padding_till_n('0', format, zeros);
	print_str(array, format);
}

void	print_if_left(t_format *format, int padding_size,
											int zeros, char *array)
{
	if (format->negative == '-')
		print_char('-', format);
	if (format->ptr == 1)
	{
		print_char('0', format);
		print_char('x', format);
	}
	print_padding_till_n('0', format, zeros);
	print_str(array, format);
	print_padding_till_n(' ', format, padding_size);
}
