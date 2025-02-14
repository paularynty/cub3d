/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_funcs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:27 by mrahmat-          #+#    #+#             */
/*   Updated: 2024/06/10 18:37:51 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_reduce(void *acc, t_vec *src, void (*f)(void *, void *))
{
	size_t	count;

	if (src == NULL || f == NULL || acc == NULL)
		return (-1);
	count = 0;
	while (count < src->len)
	{
		f(acc, vec_get(src, count));
		count++;
	}
	return (1);
}

int	vec_sort(t_vec *src, int (*f)(void *, void *))
{
	size_t	index;
	int		temp;
	void	*tempptr;

	if (src == NULL || f == NULL || src->memory == NULL)
		return (-1);
	index = 0;
	while (index < src->len - 1)
	{
		if (f(vec_get(src, index), \
			&src->memory[(index + 1) * src->elem_size]) > 0)
		{
			temp = *(int *)vec_get(src, index);
			tempptr = &temp;
			vec_remove(src, index);
			vec_insert(src, tempptr, index + 1);
			index = 0;
		}
		else
			index++;
	}
	return (1);
}
