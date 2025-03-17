/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:59 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/15 14:05:45 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	validate_map_line(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
	{
		if (line[len] == ' ' || line[len] == '1' || line[len] == '0')
			len++;
		else if (line[len] == 'N' || line[len] == 'E' || \
			line[len] == 'S' || line[len] == 'W')
			len++;
		else
			return (0);
	}
	return (len);
}

int	validate_space(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_nl(line);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '0')
		{
			if (i == 0 || i == len)
				return (-1);
			else if (line[i - 1] == ' ' || line[i + 1] == ' ')
				return (FALSE);
			else
				i++;
		}
		else
			i++;
	}
	return (TRUE);
}

int	check_walls(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	check_surroundings(char **map, size_t x, size_t y)
{
	char	*player;

	player = "NSEW";
	if (y != 0 && map[y - 1][x] != '0' && map[y - 1][x] != '1' \
		&& ft_strchr(player, map[y - 1][x]) == NULL)
		return (print_error("First if"));
	if (map[y + 1] != NULL && map[y + 1][x] != '0' && map[y + 1][x] != '1' \
		&& ft_strchr(player, map[y + 1][x]) == NULL)
		return (print_error("Second if"));
	if (x != 0 && map[y][x - 1] != '0' && map[y][x - 1] != '1' \
		&& ft_strchr(player, map[y][x - 1]) == NULL)
		return (print_error("3 if"));
	if (map[y][x + 1] != '0' && map[y][x + 1] != '1' \
		&& ft_strchr(player, map[y][x + 1]) == NULL)
		return (print_error("4 if"));
	if (y == 0 && map[y][x] != ' ' && map[y][x] != '1')
		return (print_error("5 if"));
	if (map[y + 1] == NULL && map[y][x] != ' ' && map[y][x] != '1')
		return (print_error("6 if"));
	if (x == 0 && map[y][x] != ' ' && map[y][x] != '1')
		return (print_error("7 if"));
	if (map[y][x + 1] == '\0' && map[y][x] != '1')
		return (print_error("8 if"));
	if (x != 0 && map[y][x - 1] == ' ' && map[y][x] != '1')
		return (print_error("9 if")); 
	return (TRUE);
}

int	final_validation(t_game *game)
{
	size_t	y;
	size_t	x;
	t_map	map;

	y = 0;
	map = game->map;
	while (y < map.height)
	{
		x = 0;
		while (map.map[y][x] != '\0')
		{
			if (map.map[y][x] == '0')
			{
				if (check_surroundings(map.map, x, y) < 0)
					return (FALSE);
			}
			else if (map.map[y][x] == 'N' || map.map[y][x] == 'S' || \
				map.map[y][x] == 'E' || map.map[y][x] == 'W')
			{
				if (init_player(&game->player, x, y, map.map[y][x]) == FALSE)
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	if (game->player.pos_x == 0 || game->player.pos_y == 0)
		return (print_error("No player in map, need one (1)"));
	return (TRUE);
}
