/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:14:19 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/13 21:48:18 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_map(t_map *map)
{
	char	**new_map;
	size_t	x;
	size_t	y;

	y = 0;
	new_map = malloc((map->height + 1) * sizeof(char *));
	if (new_map == NULL)
		return (print_error("Failed to allocate memory"));
	while (map->map[y] != NULL)
	{
		new_map[y] = malloc((map->width + 1) * sizeof(char));
		if (new_map[y] == NULL)
		{
			split_free(new_map);
			return (print_error("Failed to allocate memory"));
		}
		x = ft_strlcpy(new_map[y], map->map[y], (ft_strlen(map->map[y]) + 1));
		if (x == 0)
		{
			split_free(new_map);
			return (print_error("Failed to create map"));
		}
		while (x < map->width)
		{
			new_map[y][x] = ' ';
			x++;
		}
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	split_free(map->map);
	map->map = new_map;
	return (TRUE);
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
	return (TRUE);
}
