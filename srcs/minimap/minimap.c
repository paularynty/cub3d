/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:45:16 by prynty            #+#    #+#             */
/*   Updated: 2025/03/18 17:34:00 by mrahmat-         ###   ########.fr       */
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

/* static int	draw_wall_minimap(t_game *game, uint32_t x, uint32_t y)
{
	uint32_t	iter_x;
	uint32_t	iter_y;
	t_color		color;

	if (y > game->assets.minimap->height)
		return (TRUE);
	iter_y = 0;
	while (iter_y < TILESIZE)
	{
		iter_x = 0;
		while (iter_x < TILESIZE)
		{
			if (x + iter_x < game->assets.minimap->width)
			{
				get_pixel_data(game->assets.minimap_wall, &color, iter_x + iter_y);
				mlx_put_pixel(game->assets.minimap, x + iter_x, y + iter_y, color.color);
			}
			iter_x++;
		}
		iter_y++;
		if (y + iter_y > game->assets.minimap->height)
			break ;
	}
	return (TRUE);
} */

static int	render_minimap_elements(t_game *game, t_map *map)
{
	uint32_t	x;
	uint32_t	y; 

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			/* if (map->map[y][x] == '1')
			{
				if (!draw_wall_minimap(game, x * TILESIZE, y * TILESIZE))
					return (FALSE);
			} */
			if (map->map[y][x] == 'N' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'S' || map->map[y][x] == 'W')
			{
				if (!draw_image(game, game->assets.minimap_player, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->assets.minimap, 5, 5);
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
