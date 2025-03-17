/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:59:05 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 18:44:50 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static	uint8_t	get_color(int32_t color, int bit)
// {
// 	return (color >> bit) & 0xFF;
// }

// static uint32_t    get_shaded_pixel(uint32_t color, double distance)
// {
//     uint8_t        r;
//     uint8_t        g;
//     uint8_t        b;
//     double        factor;

//     factor = 1 / (1 + distance * 0.2);
//     if (factor < 0.2)
//         factor = 0.2;

//     r = (uint8_t)(get_color(color, 24) * factor);
//     g = (uint8_t)(get_color(color, 16) * factor);
//     b = (uint8_t)(get_color(color, 8) * factor);

//     return (rgba(r, g, b, 0xFF));
// }

void	render_walls(int x, t_game *game, mlx_image_t *image, \
	mlx_texture_t *texture)
{
	t_color		color;
	double		texture_pos;
	double		step;
	int			y;

	game->ray.texture_x = get_x_coord(game, texture);
	step = (double)texture->height / game->ray.line_height;
	texture_pos = (game->ray.draw_start - game->window_height / 2 \
		+ game->ray.line_height / 2) * step;
	if (texture_pos < 0)
		texture_pos = 0;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		game->ray.texture_y = (uint32_t)texture_pos;
		if (game->ray.texture_y >= texture->height)
			game->ray.texture_y = texture->height - 1;
		get_pixel_data(texture, &color, \
			((texture->width * game->ray.texture_y + game->ray.texture_x) * 4));
		// color.color = get_shaded_pixel(color.color, game->ray.wall_dist);
		mlx_put_pixel(image, x, y, color.color);
		texture_pos += step;
		y++;
	}
}

int	render_floor_ceiling(t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->assets.ceiling, 0, 0) == FALSE)
		return (print_error("Failed to put ceiling image to window"));
	if (mlx_image_to_window(game->mlx, game->assets.floor,
			0, game->window_height / 2) == FALSE)
		return (print_error("Failed to put floor image to window"));
	return (TRUE);
}

void	render_world(t_game *game)
{
	uint32_t		x;
	mlx_texture_t	*texture;

	texture = NULL;
	if (game->assets.world != NULL)
		mlx_delete_image(game->mlx, game->assets.world);
	game->assets.world = mlx_new_image(game->mlx, \
		game->window_width, game->window_height);
	if (!game->assets.world)
		return ;
	x = 0;
	while (x < game->assets.world->width)
	{
		init_ray(x, &game->ray, &game->player, game);
		init_side_step(&game->ray, &game->player);
		cast_ray(&game->ray, game);
		init_draw(&game->ray, game);
		texture = determine_texture(game, texture);
		render_walls(x, game, game->assets.world, texture);
		x++;
	}
	mlx_image_to_window(game->mlx, game->assets.world, 0, 0);
	// mlx_image_to_window(game->mlx, game->assets.minimap_floor, 0, 0);
}
