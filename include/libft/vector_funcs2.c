/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:56:46 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/10 18:38:01 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_append(t_vec *dst, t_vec *src)
{
	if (dst == NULL || src == NULL)
		return (-1);
	else if ((dst->len + src->len) * dst->elem_size >= dst->alloc_size)
		if (vec_resize(dst, dst->len + src->len) < 0)
			return (-1);
	ft_memmove(&dst->memory[dst->len * dst->elem_size], src->memory, \
		src->len * src->elem_size);
	dst->len = dst->len + src->len;
	return (1);
}

int	vec_prepend(t_vec *dst, t_vec *src)
{
	size_t	count;

	if (dst == NULL || src == NULL)
		return (-1);
	else if ((dst->len + src->len) * dst->elem_size >= dst->alloc_size)
		if (vec_resize(dst, dst->len + src->len) < 0)
			return (-1);
	count = 0;
	while (count++ < src->len)
		ft_memmove(vec_get(dst, 1), dst->memory, \
			(dst->len + src->len) * dst->elem_size);
	ft_memmove(dst->memory, src->memory, src->len * src->elem_size);
	dst->len = dst->len + src->len;
	return (1);
}

void	vec_iter(t_vec *src, void (*f)(void *))
{
	size_t	count;

	if (src == NULL || f == NULL)
		return ;
	count = 0;
	while (count < src->len)
	{
		f(vec_get(src, count));
		count++;
	}
}

void	vec_map(t_vec *dst, t_vec *src, void (*f)(void *))
{
	size_t	count;

	if (dst == NULL || src == NULL || f == NULL)
		return ;
	else if (dst->memory == NULL)
		if (vec_new(dst, src->len, src->elem_size) < 0)
			return ;
	count = 0;
	ft_memmove(dst->memory, src->memory, src->len * src->elem_size);
	dst->len = src->len;
	while (count < dst->len)
	{
		f(vec_get(dst, count));
		count++;
	}
}

int	vec_filter(t_vec *dst, t_vec *src, bool (*f)(void *))
{
	size_t	count;

	if (src == NULL || dst == NULL || f == NULL)
		return (-1);
	else if (dst->memory == NULL)
	{
		if (vec_new(dst, src->len, src->elem_size) < 0)
			return (-1);
	}
	else if (dst->len * dst->elem_size >= dst->alloc_size)
	{
		if (vec_resize(dst, dst->len * 2) < 0)
			return (-1);
	}
	count = 0;
	ft_memmove(dst->memory, src->memory, src->len * src->elem_size);
	dst->len += src->len;
	while (count < dst->len)
	{
		if (!f(vec_get(dst, count)))
			vec_remove(dst, count);
		count++;
	}
	return (1);
}
