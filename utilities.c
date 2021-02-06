/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 16:54:08 by anspirga      #+#    #+#                 */
/*   Updated: 2021/01/30 17:19:18 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *str)
{
	int num;

	num = 0;
	while (str[num] != '\0')
	{
		num++;
	}
	return (num);
}

static int	overflow(int neg, int num, const char *str, int i)
{
	if (neg == -1 && str[i] > '8')
		return (0);
	else if (neg == 1 && str[i] > 7)
		return (-1);
	else
	{
		num = num * 10 + (str[i] - '0');
		return (num * neg);
	}
}

static int	ft_isspace(const char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				i;
	long long int	num;
	int				neg;

	i = 0;
	num = 0;
	neg = 1;
	i = ft_isspace(str, i);
	while ((str[i] == '+' || str[i] == '-')
			&& str[i + 1] != '+' && str[i + 1] != '-')
		if (str[i] == '-')
		{
			neg = neg * -1;
			i++;
		}
		else
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num >= 922337203685477580)
			return (overflow(neg, num, str, i));
	}
	return (num * neg);
}

/*
**returns the number of digits of a number num
**returns 0 if num is 0, WICHTIG!
*/

int			get_digit_length(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (0);
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		num = num * -1;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
