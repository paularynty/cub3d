/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:20:42 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/05/10 10:51:11 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	res;

	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	i = 0;
	res = 0;
	if (src_len == 0)
		return (dst_len);
	if (dstsize > dst_len)
		res = src_len + dst_len;
	else
		res = src_len + dstsize;
	while ((dst_len + 1) < dstsize && src[i] != '\0')
	{
		dst[dst_len] = ((char *)src)[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (res);
}
