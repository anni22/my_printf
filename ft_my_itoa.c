/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_my_itoa.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/30 13:55:02 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 14:03:32 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**count digits of unsigned int(positive)
*/

static	int	count_digits(size_t positive, t_argument *argument)
{
	int len;

	len = 0;
	while (positive != 0)
	{
		positive = positive / argument->base;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

/*
**converts unsigned int number (positive) into a string
**which can be formatted and then printed
**
**difference to normal itoa function:
**handels not only decimal format, but also hexadecimal capital and not capital
** ->function slowly fills array with the unsigned int
**in the correct format (decimal or hexadecimal)
*/

void		ft_my_itoa(size_t positive, t_argument *argument, char *array)
{
	int			len;
	const char	*digit_set;

	len = count_digits(positive, argument);
	array[len] = '\0';
	if (argument->set == 'H')
		digit_set = "0123456789ABCDEF";
	else if (argument->set == 'h')
		digit_set = "0123456789abcdef";
	else
		digit_set = "0123456789";
	len--;
	while (len >= 0)
	{
		array[len] = digit_set[positive % argument->base];
		positive = positive / argument->base;
		len--;
	}
}
