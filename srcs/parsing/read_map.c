/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:14:19 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/02/27 13:49:38 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_map_size(char **line, int32_t *map_file, char *filename)
{
	size_t	size;
	size_t	line_i;

	size = 0;
	while (*line != NULL)
	{
		size++;
		free(*line);
		*line = get_next_line(*map_file);
	}
	close(*map_file);
	*map_file = open(filename, O_RDONLY);
	if (*map_file == -1)
		return (0);
	*line = get_next_line(*map_file);
	while (*line != NULL)
	{
		line_i = 0;
		while (is_whitespace((*line)[line_i]) > 0)
			line_i++;
		if (ft_strncmp(&(*line)[line_i], "1", 1) == 0 || \
			ft_strncmp(&(*line)[line_i], "0", 1) == 0)
			break ;
		free(*line);
		*line = get_next_line(*map_file);
	}
	return (size);
}

int	read_map(t_map *map, char *line, int32_t map_file, char *filename)
{
	size_t	size;
	size_t	len;
	size_t	y;

	size = get_map_size(&line, &map_file, filename);
	map->map = malloc((size + 1) * sizeof(char *));
	if (map->map == NULL)
		return (print_error("Failed to allocate memory"));
	y = 0;
	while (line != NULL && y < size)
	{
		len = validate_map_line(line);
		if (len == 0)
			return (print_error("Invalid character in map\n"));
		if (y == 0 || y == size - 1)
		{
			if (check_walls(line) == 1)
			{
				map->map[y] = ft_substr(line, 0, len);
				if (map->map[y] == NULL)
					return (print_error("Failed to allocate memory"));
			}
			else
				return (print_error("The map has to be surrounded by walls"));
		}
		else
		{
			if (validate_space(line) == 1)
			{
				map->map[y] = ft_substr(line, 0, len);
				if (map->map[y] == NULL)
					return (print_error("Failed to allocate memory"));
			}
			else
				return (print_error("The map has to be surrounded by walls"));
		}
		free(line);
		line = get_next_line(map_file);
		y++;
	}
	map->height = y;
	map->map[y] = NULL;
	return (1);
}
