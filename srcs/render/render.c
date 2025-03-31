/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:59:05 by prynty            #+#    #+#             */
/*   Updated: 2025/03/31 16:33:05 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_x_coord(t_game *game, mlx_texture_t *texture)
{
	int32_t	texture_x;

	texture_x = game->ray.wall_hit_x * texture->width;
	if ((game->ray.side == VERTICAL && game->ray.step_x > 0)
		|| (game->ray.side == HORIZONTAL && game->ray.step_y < 0))
		texture_x = texture->width - texture_x - 1;
	if (texture_x < 0)
		texture_x = 0;
	else if ((uint32_t)texture_x >= texture->width)
		texture_x = texture->width - 1;
	return ((uint32_t)texture_x);
}

static mlx_texture_t	*determine_texture(t_game *game, mlx_texture_t *texture)
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
		if (game->ray.step_y > 0)
			texture = game->map.textures.south;
		else
			texture = game->map.textures.north;
	}
	return (texture);
}

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
		mlx_put_pixel(image, x, y, color.color);
		texture_pos += step;
		y++;
	}
}

static void	render_floor_ceiling(t_game *game)
{
	fill_color(game->assets.world, game->map.floor.color, \
		game->window_width, game->window_height);
	fill_color(game->assets.world, game->map.ceiling.color, \
		game->window_width, game->window_height / 2);
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
	render_floor_ceiling(game);
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
}
