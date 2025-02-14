/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:03:01 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/31 11:08:00 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(unsigned int n)
{
	unsigned int	temp;
	unsigned int	count;

	temp = n;
	count = 0;
	while (temp >= 10)
	{
		count++;
		temp = temp / 10;
	}
	return (count + 1);
}

int	ft_putunsign(unsigned int n)
{
	char	res;
	int		len;

	len = check_size(n);
	if (n >= 10)
	{
		res = n % 10 + '0';
		if (ft_putunsign(n / 10) == -1)
			return (-1);
	}
	else
		res = n + '0';
	if (ft_putchar(res) == -1)
		return (-1);
	return (len);
}
