/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:59:05 by prynty            #+#    #+#             */
/*   Updated: 2025/03/10 18:57:55 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	render_walls(mlx_texture_t *texture)
// {
// 	texture->pixels
// }

static int	image_color_fill(mlx_image_t *image, int color)
{
	uint32_t	x;
	uint32_t	y;

	if (!image)
		return (0);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, (uint32_t)color);
			++x;
		}
		++y;
	}
	return (TRUE);
}

int	render_floor_ceiling(t_game *game)
{
	game->assets.ceiling = mlx_new_image(game->mlx,
			game->window_w, game->window_h / 2);
	game->assets.floor = mlx_new_image(game->mlx,
			game->window_w, game->window_h / 2);
	image_color_fill(game->assets.ceiling, game->map.ceiling.color);
	image_color_fill(game->assets.floor, game->map.floor.color);
	if (mlx_image_to_window(game->mlx, game->assets.ceiling, 0, 0) == FALSE)
		return (print_error("Failed to put ceiling image to window"));
	if (mlx_image_to_window(game->mlx, game->assets.floor,
			0, game->window_h / 2) == FALSE)
		return (print_error("Failed to put floor image to window"));
	return (TRUE);
}
