/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:46:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/17 14:21:11 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_wall_collision(t_game *game, t_ray *ray)
{
	ray->hit = TRUE;
	if (ray->side == VERTICAL)
		ray->wall_dist = (ray->map_x - game->player.pos_x \
			+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->wall_dist = (ray->map_y - game->player.pos_y \
			+ (1 - ray->step_y) / 2) / ray->dir_y;
	if (ray->side == VERTICAL)
		ray->wall_hit_x = game->player.pos_y \
			+ ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit_x = game->player.pos_x \
			+ ray->wall_dist * ray->dir_x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
}

void	cast_ray(t_ray *ray, t_game *game)
{
	while (ray->hit == FALSE)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side = VERTICAL;
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
		}
		else
		{
			ray->side = HORIZONTAL;
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
		}
		if (game->map.map[ray->map_y][ray->map_x] > '0')
			handle_wall_collision(game, ray);
	}
}

void	init_draw(t_ray *ray, t_game *game)
{
	ray->line_height = (int)(game->mlx->height / ray->wall_dist);
	ray->draw_start = (-ray->line_height) / 2 + game->mlx->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->mlx->height / 2;
	if (ray->draw_end >= game->mlx->height)
		ray->draw_end = game->mlx->height - 1;
}
