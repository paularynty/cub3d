/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:46:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/10 12:32:46 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_ray *ray, t_game *game)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] > '0')
			hit = TRUE;
	}
}

void	init_draw(t_ray *ray, t_game *game)
{
	double	wall_dist;

	if (ray->side == 0)
		wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)game->mlx->height / wall_dist;
	ray->draw_start = (-ray->line_height) / 2 + game->mlx->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->mlx->height / 2;
	if (ray->draw_end >= game->mlx->height)
		ray->draw_end = game->mlx->height - 1;
}

void	render_world(t_game *game)
{
	uint32_t	x;

	if (game->assets.world != NULL)
		mlx_delete_image(game->mlx, game->assets.world);
	game->assets.world = mlx_new_image(game->mlx, game->window_w, game->window_h);
	if (!game->assets.world)
		return ;
	x = 0;
	while (x < game->assets.world->width)
	{
		init_ray_info(x, &game->ray, &game->player, game->mlx);
		init_side_step(&game->ray, &game->player);
		cast_ray(&game->ray, game);
		init_draw(&game->ray, game);
		test_draw(x, game, game->assets.world);
		x++;
	}
	mlx_image_to_window(game->mlx, game->assets.world, 0, 0);
}
