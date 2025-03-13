/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:59:05 by prynty            #+#    #+#             */
/*   Updated: 2025/03/13 15:34:54 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_color(mlx_image_t *image, int color)
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

static void	get_pixel_data(mlx_texture_t *texture, t_color *color, \
	size_t pixel_coords)
{
	if (pixel_coords + 3 >= (texture->width * texture->height * 4))
		return ;
	color->r = texture->pixels[pixel_coords];
	color->g = texture->pixels[pixel_coords + 1];
	color->b = texture->pixels[pixel_coords + 2];
	color->a = texture->pixels[pixel_coords + 3];
	color->color = rgba(color->r, color->g, color->b, color->a);
}

static uint32_t get_x_coord(t_game *game, mlx_texture_t *texture)
{
    int32_t	texture_x;

    texture_x = (int)(game->ray.wall_hit_x * texture->width);
    if (texture_x < 0)
        texture_x = 0;
    else if ((uint32_t)texture_x >= texture->width)
        texture_x = texture->width - 1;
    return (texture_x);
}

mlx_texture_t	*determine_texture(t_game *game, mlx_texture_t *texture)
{
	if (game->ray.side == 0)
	{
		if (game->player.dir_x < 0 && game->player.dir_y < 0)
			texture = game->map.textures.west;
		else
			texture = game->map.textures.east;
	}
	else
	{
		if (game->player.dir_y < 0)
			texture = game->map.textures.south;
		else
			texture = game->map.textures.north;
	}
	return (texture);

}

void render_walls(int x, t_game *game, mlx_image_t *image, mlx_texture_t *texture)
{
    t_color     color;
    uint32_t    texture_x;
    uint32_t    texture_y;
    double      texture_pos;
    double      step;
    int         y;

    texture_x = get_x_coord(game, texture);
    step = (double)texture->height / game->ray.line_height;
    texture_pos = (game->ray.draw_start - game->window_h / 2
		+ game->ray.line_height / 2) * step;
    if (texture_pos < 0)
        texture_pos = 0;
    y = game->ray.draw_start;
    while (y < game->ray.draw_end)
    {
        texture_y = (uint32_t)texture_pos;
        if (texture_y >= texture->height)
            texture_y = texture->height - 1;
        get_pixel_data(texture, &color,
			((texture->width * texture_y + texture_x) * 4));
        mlx_put_pixel(image, x, y, color.color);
        texture_pos += step;
        y++;
    }
}

int	render_floor_ceiling(t_game *game)
{
	game->assets.ceiling = mlx_new_image(game->mlx,
			game->window_w, game->window_h / 2);
	game->assets.floor = mlx_new_image(game->mlx,
			game->window_w, game->window_h / 2);
	fill_color(game->assets.ceiling, game->map.ceiling.color);
	fill_color(game->assets.floor, game->map.floor.color);
	if (mlx_image_to_window(game->mlx, game->assets.ceiling, 0, 0) == FALSE)
		return (print_error("Failed to put ceiling image to window"));
	if (mlx_image_to_window(game->mlx, game->assets.floor,
			0, game->window_h / 2) == FALSE)
		return (print_error("Failed to put floor image to window"));
	return (TRUE);
}
