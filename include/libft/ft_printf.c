/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:43:51 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:13 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printer(const char format, va_list args)
{
	int				len;

	len = 0;
	if (format == 'd' || format == 'i')
		len += ft_putdecimal(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunsign(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_printhex(va_arg(args, int), format);
	else if (format == 'X')
		len += ft_printhex(va_arg(args, int), format);
	else if (format == 'p')
		len += ft_putaddress(va_arg(args, void *));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

static int	parse_str(const char *str, va_list args)
{
	int	len;
	int	check;

	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
			{
				check = printer(*str++, args);
				if (check == -1)
					return (-1);
				len += check;
			}
		}
		else if (*str != '%')
		{
			if (ft_putchar(*str++) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = parse_str(str, args);
	va_end(args);
	return (len);
}
/* 
#include <stdio.h>
int	main(void)
{
	//unsigned int	nbr = -1;

	printf("%d\n\n", ft_printf("Hello%"));
	printf("%d\n", printf("%p\n", ""));
	return (0);
} */