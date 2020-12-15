/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 15:39:10 by anspirga      #+#    #+#                 */
/*   Updated: 2020/11/10 19:42:16 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
