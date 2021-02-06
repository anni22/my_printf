/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_star.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 17:02:38 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 17:02:58 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**replaces star with actual number from va_list
**checks if star is supposed to be width or precision
*/

int		replace_star(t_format *format, va_list args)
{
	if (format->flag != '\0' && format->precision == '\0')
		format->width = va_arg(args, int);
	if (format->precision != '\0')
		format->precision_size = va_arg(args, int);
	return (1);
}
