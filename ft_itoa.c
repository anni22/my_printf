/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 11:51:36 by anspirga      #+#    #+#                 */
/*   Updated: 2020/11/07 17:26:17 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int nbr)
{
	if (nbr < 0)
	{
		return (-nbr);
	}
	return (nbr);
}

static int	get_len(int nbr)
{
	int len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
	}
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
	}
	else if (n == 0)
	{
		str[0] = '0';
	}
	while (n != 0)
	{
		len--;
		str[len] = absolute(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
