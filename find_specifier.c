/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_specifier.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 09:02:30 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 13:32:12 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	clean_format(t_format *format, t_argument *argument)
{
	format->padding = '\0';
	format->width = 0;
	format->flag = '\0';
	format->side = '\0';
	format->precision_size = 0;
	format->precision = '\0';
	format->negative = '\0';
	format->ptr = 0;
	argument->base = 10;
	argument->set = '\0';
	argument->specifier = '\0';
}

static	void	define_argument(t_argument *argument, char c)
{
	if (c == 'i' || c == 'd')
	{
		argument->specifier = 'i';
		argument->base = 10;
	}
	if (c == 'u')
	{
		argument->specifier = 'u';
		argument->base = 10;
	}
	if (c == 'x' || c == 'p')
	{
		argument->specifier = c;
		argument->base = 16;
		argument->set = 'h';
	}
	if (c == 'X')
	{
		argument->specifier = 'X';
		argument->base = 16;
		argument->set = 'H';
	}
}

/*
**handles the case of a negative width (if it used to be a star)
**and a negative precision
**finds the specifier and calls the correct function to get the argument
**and print it
**
**I realised it would be easiest to just handle one case -> unsigned integers
**instead of creating a unique function for each specifier
**because we can just cast signed int into unsigned int and add the - later
**
**cleans the format in the end to get ready for the next specifier
*/

void			find_specifier(va_list args, char c, t_format *format)
{
	t_argument	argument;

	if (format->width < 0)
	{
		format->side = 'L';
		if (format->flag == '0')
			format->flag = '-';
		format->width *= -1;
	}
	if (format->precision_size < 0)
		format->precision = '\0';
	if (c == 'c')
		c_print(args, format);
	else if (c == 's')
		s_print(args, format);
	else if (c == 'i' || c == 'd' || c == 'u' || c == 'x' ||
													c == 'X' || c == 'p')
	{
		define_argument(&argument, c);
		print_iduxxp(args, format, &argument);
	}
	clean_format(format, &argument);
}
