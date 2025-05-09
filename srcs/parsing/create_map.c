/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:02:45 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/04/10 18:46:46 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_texture(mlx_texture_t **texture, char *path)
{
	size_t	start;
	size_t	end;
	char	*parsed_path;

	start = 0;
	if (*texture != NULL)
		return (print_error("Multiple textures, expected one per NO/SO/EA/WE"));
	while (is_whitespace(path[start]) == 1)
		start++;
	end = start;
	while (ft_isprint(path[end]) != 0)
		end++;
	parsed_path = ft_substr(path, start, end - start);
	if (parsed_path == NULL)
		return (print_error("Failed to allocate memory"));
	*texture = mlx_load_png(parsed_path);
	free(parsed_path);
	if (*texture == NULL)
		return (print_error("Texture loading failed"));
	return (TRUE);
}

static int	add_color(t_color *color, char *line)
{
	size_t	start;
	char	**splitted_line;
	int		i;

	if (color->color != 0)
		return (print_error("Multiple color values, expected one per F/C"));
	start = 0;
	while (is_whitespace(line[start]) == 1)
		start++;
	splitted_line = ft_split(&line[start], ',');
	if (splitted_line == NULL || splitted_line[0] == NULL)
		return (print_error("Failed to allocate memory"));
	i = 0;
	while (splitted_line[i] != NULL)
		if (is_valid_color(splitted_line[i++]) == FALSE)
			return (split_free(splitted_line, 1, "Invalid RGB value"));
	if (i != 3)
		return (split_free(splitted_line, 1, "Invalid RGB value"));
	color->r = ft_atoi(splitted_line[0]);
	color->g = ft_atoi(splitted_line[1]);
	color->b = ft_atoi(splitted_line[2]);
	color->a = 255;
	color->color = rgba(color->r, color->g, color->b, color->a);
	split_free(splitted_line, 0, NULL);
	return (TRUE);
}

static int	check_key(t_map *map, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (add_texture(&map->textures.north, line + 2));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (add_texture(&map->textures.south, line + 2));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (add_texture(&map->textures.west, line + 2));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (add_texture(&map->textures.east, line + 2));
	else if (ft_strncmp(line, "F", 1) == 0)
		return (add_color(&map->floor, line + 1));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (add_color(&map->ceiling, line + 1));
	else if (ft_strncmp(line, "1", 1) == 0 || ft_strncmp(line, "0", 1) == 0)
		return (-2);
	return (print_error("Invalid file content"));
}

static int	check_line(t_map *map, char *line)
{
	size_t	line_i;

	line_i = 0;
	if (ft_strcmp(line, "\n") == 0)
		return (TRUE);
	while (is_whitespace(line[line_i]) == 1)
		line_i++;
	return (check_key(map, &line[line_i]));
}

int	create_map(t_game *game, char *filename)
{
	char	*line;
	int		check;

	if (validate_file(game, filename) == FALSE)
		return (FALSE);
	line = get_next_line(game->map.map_fd);
	if (line == NULL)
		return (print_error("Empty or misconfigured file"));
	while (line != NULL)
	{
		check = check_line(&game->map, line);
		if (check == -2)
		{
			if (read_map(&game->map, line, game->map.map_fd, filename) < 0)
				return (FALSE);
			if (get_map_width(&game->map) < 0)
				return (FALSE);
			return (final_validation(game));
		}
		if (check == FALSE)
			return (free_gnl(&line, game->map.map_fd));
		free(line);
		line = get_next_line(game->map.map_fd);
	}
	return (TRUE);
}
