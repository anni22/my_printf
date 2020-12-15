/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anspirga <anspirga@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:08:00 by anspirga      #+#    #+#                 */
/*   Updated: 2020/10/27 15:59:08 by anspirga      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(const char *str)
{
	int num;

	num = 0;
	while (str[num] != '\0')
	{
		num++;
	}
	return (num);
}
