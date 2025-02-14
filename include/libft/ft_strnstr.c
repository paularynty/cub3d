/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:28:25 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/10 10:51:57 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ni;
	size_t	hi;

	if (needle[0] == '\0')
		return ((char *)haystack);
	hi = 0;
	while (len > hi && haystack[hi] != '\0')
	{
		ni = 0;
		while (len > (ni + hi) && needle[ni] == haystack[hi + ni])
		{
			if (needle[ni + 1] == '\0')
				return ((char *)&haystack[hi]);
			ni++;
		}
		hi++;
	}
	return (0);
}
