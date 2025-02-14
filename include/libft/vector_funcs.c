/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:26 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/13 13:59:23 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if (dst == NULL || elem_size == 0)
		return (-1);
	dst->elem_size = elem_size;
	dst->len = 0;
	dst->alloc_size = init_len * elem_size;
	if (init_len == 0)
		dst->memory = NULL;
	else
	{
		dst->memory = malloc(init_len * elem_size);
		if (dst->memory == NULL)
			return (-1);
	}
	return (1);
}

void	vec_free(t_vec *src)
{
	src->elem_size = 0;
	src->len = 0;
	src->alloc_size = 0;
	free(src->memory);
	src->memory = NULL;
}

int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (src == NULL || dst == NULL || elem_size == 0)
		return (-1);
	dst->elem_size = elem_size;
	dst->alloc_size = len * elem_size;
	if (vec_new(dst, len, elem_size) < 0)
		return (-1);
	dst->len = len;
	ft_memmove(dst->memory, src, dst->alloc_size);
	return (1);
}

int	vec_copy(t_vec *dst, t_vec *src)
{
	if (dst == NULL || src == NULL)
		return (-1);
	ft_memmove(dst->memory, src->memory, dst->alloc_size);
	dst->len = src->len;
	dst->elem_size = src->elem_size;
	return (1);
}

int	vec_resize(t_vec *src, size_t target_len)
{
	t_vec	temp;

	if (src == NULL)
		return (-1);
	if (vec_new(&temp, target_len, src->elem_size) < 0)
		return (-1);
	ft_memmove(temp.memory, src->memory, src->alloc_size);
	temp.len = src->len;
	vec_free(src);
	*src = temp;
	return (1);
}
