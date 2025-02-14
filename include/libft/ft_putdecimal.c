/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:47:56 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:50 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(int n)
{
	int	temp;
	int	count;

	temp = n;
	count = 0;
	if (temp == -2147483648)
	{
		count = 11;
		return (count);
	}
	if (temp < 0)
	{
		count++;
		temp *= -1;
	}
	while (temp >= 10)
	{
		count++;
		temp = temp / 10;
	}
	return (count + 1);
}

int	ft_putdecimal(int n)
{
	int		len;

	len = check_size(n);
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648") == -1)
			return (-1);
		return (len);
	}
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		if (ft_putdecimal(n / 10) == -1)
			return (-1);
		ft_putdecimal(n % 10);
	}
	else
		if (ft_putchar(n + '0') == -1)
			return (-1);
	return (len);
}
