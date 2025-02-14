/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:14:39 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:35 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_len(size_t n)
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

int	ft_putptr(uintptr_t n)
{
	if (n >= 16)
	{
		if (ft_putptr(n / 16) == -1)
			return (-1);
		ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			return (ft_putchar(n + '0'));
		else
		{
			return (ft_putchar((n % 16) - 10 + 'a'));
		}
	}
	return (0);
}

int	ft_putaddress(void *ptr)
{
	int			len;
	uintptr_t	ptr_val;

	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	if (ptr == 0)
		len += ft_putchar('0');
	else
	{
		ptr_val = (uintptr_t)ptr;
		if (ft_putptr(ptr_val) == -1)
			return (-1);
		len += ptr_len(ptr_val);
	}
	return (len);
}
