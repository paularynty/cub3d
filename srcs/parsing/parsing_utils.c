/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:17:23 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/04/10 17:12:20 by mrahmat-         ###   ########.fr       */
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

int	is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || \
		c == '\v' || c == '\f' || c == '\n')
		return (TRUE);
	return (FALSE);
}

int	is_valid_color(char *str)
{
	size_t	i;
	int		result;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && is_whitespace(str[i]) == FALSE)
			return (FALSE);
		result = ft_atoi(str);
		if (result > 255 || result < 0)
			return (FALSE);
		i++;
	}
	if (i == 0 || (i == 1 && str[0] == '\n'))
		return (FALSE);
	return (TRUE);
}

int	copy_map_content(t_map *map, char **new_map, size_t y)
{
	size_t	x;

	x = ft_strlcpy(new_map[y], map->map[y], (ft_strlen(map->map[y]) + 1));
	if (x == 0)
		return (print_error("Failed to create map"));
	while (x < map->width)
	{
		new_map[y][x] = ' ';
		x++;
	}
	new_map[y][x] = '\0';
	return (1);
}

int	get_map_width(t_map *map)
{
	size_t	y;
	size_t	width;
	size_t	max_width;

	y = 0;
	max_width = 0;
	while (map->map[y] != NULL)
	{
		width = ft_strlen(map->map[y]);
		if (width > max_width)
			max_width = width;
		y++;
	}
	map->width = max_width;
	return (fill_map(map));
}
