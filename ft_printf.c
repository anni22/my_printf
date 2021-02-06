/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 12:54:38 by anspirga      #+#    #+#                 */
/*   Updated: 2021/02/04 13:45:16 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**i keeps track of the overall parsing and
**the position of the current char in the formatstring
**
**count keeps track of the number of chars being parsed in each function and
**then returns that value in each function
**it all comes together and adds up in parse_formatstr
*/

/*
**get_width_or_precision_and_precision
**gets width or when width non-existing then precision
**and when width or precision is a star, then it gets the star
**returns the count of characters for the parsing process
**(returns either 1 or 3 (* or *.*))
*/

static	int		get_width_precision_or_star(va_list args, t_format *format,
														const char *str, int i)
{
	int count;

	count = 0;
	if (str[i] == '*')
		while (str[i] == '*')
		{
			count = replace_star(format, args);
			i++;
		}
	else
	{
		if (format->precision == '.')
		{
			if (str[i] == '0')
				count++;
			format->precision_size = ft_atoi(str + (i + count));
			count = count + get_digit_length(format->precision_size);
		}
		else
		{
			format->width = ft_atoi(str + i);
			count = get_digit_length(format->width);
		}
	}
	return (count);
}

/*
**gets the dot of the precision and call th function
**which actually gets only the precision in this case
**returns the count of characters for the parsing process
*/

static	int		get_precision(va_list args, const char *str,
										t_format *format, int i)
{
	int count;

	count = 0;
	format->precision_size = 0;
	if (str[i] != '.')
		return (0);
	while (str[i] == '.')
	{
		i++;
		count++;
	}
	format->precision = '.';
	count = count + get_width_precision_or_star(args, format, str, i);
	return (count);
}

/*
**get flags and stores them in the format struct
**returns number of flags, so the parsing can go on in the parse function
**
**possible flags: 0, -, or star
**when star is first then no other flag
**when 0 and - together either way, 0 gets ignored and - stored
**star can occur after 0 or minus
*/

static	int		get_flags(va_list args, const char *str,
										t_format *format, int i)
{
	int count;

	count = 0;
	format->side = 'R';
	format->padding = ' ';
	if (str[i] == '*' || str[i] == '-' || str[i] == '0')
		format->flag = str[i];
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			format->flag = '-';
			format->side = 'L';
		}
		count++;
		i++;
	}
	if (format->flag == '0')
		format->padding = '0';
	count = count + get_width_precision_or_star(args, format, str, i);
	return (count);
}

/*
**helper function for printf
**goes through the formatstr char after char
**prints the char as long as there is not a single percentage sign
**if there is a single %, then it checks for flags, the width and precision and
**fills the information into the format struct (in my header file)
**then it calls the find specifier function which finds the specifier and
**replaces it with the correct argument
*/

void			parse_formatstr(va_list args, const char *str,
										t_format *format, int i)
{
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
		{
			print_char(str[i], format);
			i++;
		}
		while (str[i] == '%' && str[i + 1] == '%')
		{
			print_char('%', format);
			i = i + 2;
		}
		if (str[i] == '%' && str[i + 1] != '%' && str[i + 1] != '\0')
		{
			i++;
			i = i + get_flags(args, str, format, i);
			i = i + get_precision(args, str, format, i);
			find_specifier(args, str[i], format);
			if (str[i] != '\0')
				i++;
		}
	}
}

//needs fixing! Don't return in void function! Even if it's void!
//initialize structs in the beginning and set them to zero right away!

/*
** so the idea behind my printf is to
** parse through every character in the formatstring
** and either print it, store the information in my format struct
** or replace and print the correct argument from the variable list
** in this way I don't have to use malloc,
** because I process every information I get right away
**
** so this is basically my output function, because it either
** returns -1 in case of an error or it returns the number of chars printed
** and it calls the parse_formatstr function which takes care of the rest
*/

int				ft_printf(const char *str, ...)
{
	t_format	format;
	va_list		args;
	int			i;

	i = 0;
	format.output.counter = 0;
	format.output.error = 0;
	va_start(args, str);
	parse_formatstr(args, str, &format, i);
	va_end(args);
	if (format.output.error == -1)
		return (-1);
	else
		return (format.output.counter);
}
