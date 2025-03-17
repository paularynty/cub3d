/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:45:16 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 20:01:41 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_image(t_game *game, mlx_image_t *image, uint32_t x, uint32_t y)
{
	if (mlx_image_to_window(game->mlx, image,
			x * TILESIZE, y * TILESIZE) == FALSE)
		return (print_error("Failed to put image to window"));
	return (TRUE);
}

static int	render_minimap_elements(t_game *game, t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (!draw_image(game, game->assets.minimap_wall, x, y))
					return (FALSE);
			}
			else if (map->map[y][x] == 'N' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'S' || map->map[y][x] == 'W')
			{
				if (!draw_image(game, game->assets.minimap_player, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	init_minimap(t_game *game, t_map *map)
{
	if (render_minimap_elements(game, map) == FALSE)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
