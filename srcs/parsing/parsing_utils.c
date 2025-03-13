/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:23 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/13 21:52:06 by prynty           ###   ########.fr       */
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
	return (FALSE);
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

int	is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || \
		c == '\v' || c == '\f' || c == '\n')
		return (TRUE);
	return (FALSE);
}
