/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:24:38 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/08 15:42:06 by mrahmat-         ###   ########.fr       */
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
		temp *= -1;
		count++;
	}
	while (temp >= 10)
	{
		count++;
		temp = temp / 10;
	}
	return (count + 1);
}

static char	*converter(int n, int size, char *string)
{
	unsigned int	i;

	if (n == -2147483648)
	{
		string[0] = '-';
		string[1] = '2';
		n = 147483648;
	}
	string[size] = '\0';
	i = size - 1;
	if (n < 0)
	{
		string[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		string[i--] = ((n % 10) + '0');
		n = n / 10;
	}
	if (n < 10)
		string[i] = (n + '0');
	return (string);
}

char	*ft_itoa(int n)
{
	unsigned int		size;
	char				*res;

	size = check_size(n);
	res = (char *)malloc(size * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	res = converter(n, size, res);
	return (res);
}
