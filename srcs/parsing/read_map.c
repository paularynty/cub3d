/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:14:19 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/28 12:49:38 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_map(t_map *map)
{
	char	**new_map;
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
		if (copy_map_content(map, new_map, y) == -1)
			split_free(new_map);
		y++;
	}
	new_map[y] = NULL;
	split_free(map->map);
	map->map = new_map;
	return (TRUE);
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
	while (1)
	{
		*line = get_next_line(*map_file);
		line_i = 0;
		while (is_whitespace((*line)[line_i]) > 0)
			line_i++;
		if ((*line)[line_i] == '0' || (*line)[line_i] == '1')
			break ;
		free(*line);
	}
	return (size);
}

static int	line_checker(char *line, size_t size, size_t y)
{
	if (y == 0 || y == size - 1)
	{
		if (check_walls(line) == -1)
			return (print_error("The map has to be surrounded by walls"));
	}
	else
	{
		if (validate_space(line) == -1)
			return (print_error("The map has to be surrounded by walls"));
	}
	return (1);
}

int	read_map(t_map *map, char *line, int32_t map_file, char *filename)
{
	size_t	size;
	size_t	y;

	size = get_map_size(&line, &map_file, filename);
	map->map = malloc((size + 1) * sizeof(char *));
	if (map->map == NULL)
		return (print_error("Failed to allocate memory"));
	y = 0;
	while (line != NULL && y < size)
	{
		map->map[y] = NULL;
		if (validate_map_line(line) == 0)
			return (free_gnl(&line, map_file));
		if (line_checker(line, size, y) == -1)
			return (free_gnl(&line, map_file));
		map->map[y] = ft_substr(line, 0, ft_strlen_nl(line));
		if (map->map[y] == NULL)
			return (print_error("Failed to allocate memory"));
		free(line);
		line = get_next_line(map_file);
		y++;
	}
	map->height = y;
	map->map[y] = NULL;
	return (TRUE);
}
