/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_iduxxp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 15:08:44 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 17:01:23 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**print the array with our unsigned int in the correct format
**(according to width, flags and precision)
**this time we are using zeros for the precision because it's a number
** there are 3 different cases to print the array:
** 1: R 2: L 3: R, but flag is 0 even though precision is existing -> ignore it!
*/

static	void			print_array(char *array, t_format *format)
{
	int len;
	int zeros;
	int padding_size;

	len = ft_strlen((const char *)array);
	if (format->precision == '.' && format->precision_size > len)
		zeros = format->precision_size - len;
	else
		zeros = 0;
	padding_size = format->width - (len + zeros);
	if (format->negative == '-')
		padding_size--;
	if (format->flag == '0' && format->precision == '.' && format->width > 0)
		handle_flag0_case(format, padding_size, zeros, array);
	else if (format->side == 'R')
		print_if_right(format, padding_size, zeros, array);
	else
		print_if_left(format, padding_size, zeros, array);
}

/*
**gets the correct argument from va_list
**converts signed integers into unsigned by casting
**and store the negative sign in a char variable to add it later on
**returns the unsigned positive argument
*/

static	unsigned int	get_argument(va_list ap, t_format *format,
													t_argument *arg)
{
	unsigned int	positive;
	int				num;

	positive = 0;
	num = 0;
	if (arg->specifier == 'i')
	{
		num = va_arg(ap, int);
		if (num < 0)
		{
			format->negative = '-';
			if (num == -2147483648)
				positive = 2147483648;
			else
			{
				num = num * -1;
				positive = (unsigned int)num;
			}
		}
		else
			positive = (unsigned int)num;
	}
	if (arg->specifier == 'u' || arg->specifier == 'x' || arg->specifier == 'X')
		positive = va_arg(ap, unsigned int);
	return (positive);
}

/*
**extra function to set pointer format values
**0x is arg prefix and gets used to indicate that it will be printed
**in hexadecimal form (thats why width - 2)
*/

static	size_t			get_ptr(va_list ap, t_format *format)
{
	size_t address;

	address = (size_t)va_arg(ap, void *);
	format->ptr = 1;
	format->width -= 2;
	return (address);
}

/*
**gets the argument from va_list first -> positive
**calls my_itoa function which converts the positive number
**into the array string within the right format (decimal -> hexadecimal)
**print the array containing our number in the correct format
*/

void					print_iduxxp(va_list ap, t_format *format,
													t_argument *arg)
{
	size_t	positive;
	char	array[16];

	if (arg->specifier == 'p')
		positive = get_ptr(ap, format);
	else
		positive = (size_t)get_argument(ap, format, arg);
	ft_my_itoa(positive, arg, array);
	if (format->width == 0 && format->ptr == 0)
		format->width = format->precision_size;
	if (format->precision == '.' && format->precision_size == 0 && positive == 0
		&& format->ptr == 0)
		print_padding_till_n(' ', format, format->width);
	else
		print_array(array, format);
}
