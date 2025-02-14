/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:08:14 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/08 10:31:56 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*res;

	if (!*s1 || !s1)
	{
		res = ft_strdup((char *)s1);
		return (res);
	}
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[start]) != 0 && start <= end)
		start++;
	if (start >= end)
	{
		res = ft_strdup(&s1[start]);
		return (res);
	}
	while (ft_strchr(set, s1[end]) != 0 && end >= start)
		end--;
	res = (char *)malloc(end - start + 2);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, &s1[start], end - start + 2);
	return (res);
}
