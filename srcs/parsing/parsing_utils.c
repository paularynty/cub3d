/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:23 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/02/27 13:39:04 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_gnl(char **line, int fd)
{
	char	*gnl;

	gnl = *line;
	while (gnl != NULL)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	return (-1);
}

void	split_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int32_t	rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || \
		c == '\v' || c == '\f' || c == '\n')
		return (1);
	return (-1);
}
