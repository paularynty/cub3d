/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:27:41 by prynty            #+#    #+#             */
/*   Updated: 2025/03/13 22:02:54 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_color(mlx_image_t *image, int color)
{
	uint32_t	x;
	uint32_t	y;

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
}

void	get_pixel_data(mlx_texture_t *texture, t_color *color, size_t coords)
{
	if (coords + 3 >= (texture->width * texture->height * 4))
		return ;
	color->r = texture->pixels[coords];
	color->g = texture->pixels[coords + 1];
	color->b = texture->pixels[coords + 2];
	color->a = texture->pixels[coords + 3];
	color->color = rgba(color->r, color->g, color->b, color->a);
}

uint32_t	get_x_coord(t_game *game, mlx_texture_t *texture)
{
	uint32_t	texture_x;

	texture_x = game->ray.wall_hit_x * texture->width;
	if (texture_x < 0)
		texture_x = 0;
	else if (texture_x >= texture->width)
		texture_x = texture->width - 1;
	// else if ((game->ray.side == VERTICAL && game->ray.dir_x > 0)
	// 	|| (game->ray.side == HORIZONTAL && game->ray.dir_y < 0))
	// 	texture_x = texture->width - texture_x - 1;
	return (texture_x);
}

mlx_texture_t	*determine_texture(t_game *game, mlx_texture_t *texture)
{
	if (game->ray.side == VERTICAL)
	{
		if (game->ray.step_x < 0)
			texture = game->map.textures.west;
		else
			texture = game->map.textures.east;
	}
	else
	{
		if (game->ray.step_y < 0)
			texture = game->map.textures.south;
		else
			texture = game->map.textures.north;
	}
	return (texture);
}
