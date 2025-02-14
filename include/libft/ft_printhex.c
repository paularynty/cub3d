/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:39:19 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:19 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char format)
{
	if (n >= 16)
	{
		if (ft_printhex(n / 16, format) == -1)
			return (-1);
		ft_printhex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			return (ft_putchar(n + '0'));
		else
		{
			if (format == 'x')
				return (ft_putchar(n - 10 + 'a'));
			if (format == 'X')
				return (ft_putchar(n - 10 + 'A'));
		}
	}
	return (0);
}

int	ft_printhex(unsigned int n, char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	if (ft_puthex(n, format) == -1)
		return (-1);
	return (hex_len(n));
}
