/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 20:49:49 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 12:44:31 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**shortens length if precision asks for it
*/

static	int		get_correct_length(t_format *format, int str_len)
{
	if (format->precision_size < str_len && format->precision == '.')
		return (format->precision_size);
	else
		return (str_len);
}

/*
**gets correct length (shortens length if precision asks for it)
**gets the padding needed (according to the width)
**prints string according to the side
*/

static	void	print_str_in_correct_format(const char *str, int str_len,
															t_format *format)
{
	int correct_length;
	int padding_needed;

	if (format->precision_size == 0 && format->precision == '.')
	{
		return (print_padding_till_n(format->padding,
									format, format->width));
	}
	correct_length = get_correct_length(format, str_len);
	padding_needed = format->width - correct_length;
	if (format->side == 'L')
	{
		print_str_till_n(str, format, correct_length);
		print_padding_till_n(format->padding, format, padding_needed);
	}
	else
	{
		print_padding_till_n(format->padding, format, padding_needed);
		print_str_till_n(str, format, correct_length);
	}
}

/*
**gets the str argument from va_list
**prints the string in the correct format (calls function)
**except of when you already know that the string is going to be printed fully
**or hast to be truncated for sure
*/

void			s_print(va_list args, t_format *format)
{
	char		*str;
	const char	*actual_str;
	int			str_len;

	str = va_arg(args, char *);
	if (str == NULL)
		actual_str = "(null)";
	else
		actual_str = str;
	str_len = ft_strlen(actual_str);
	if (format->precision == '\0' && format->width <= str_len)
		print_str(actual_str, format);
	else if (format->width < str_len && format->precision_size >= format->width)
		print_str_til_precision(actual_str, format);
	else
		print_str_in_correct_format(actual_str, str_len, format);
}
