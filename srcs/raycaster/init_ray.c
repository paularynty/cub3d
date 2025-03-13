/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:20:56 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/13 21:44:10 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_data(t_ray *ray)
{
	ray->camera_x = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->hit = FALSE;
	ray->wall_dist = 0;
	ray->wall_hit_x = 0;
	ray->texture_x = 0;
	ray->texture_y = 0;
}

void	init_ray(int x, t_ray *ray, t_player *player, t_game *game)
{
	init_ray_data(ray);
	ray->camera_x = 2 * x / (double)game->window_w - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	init_side_step(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) \
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) \
			* ray->delta_dist_y;
	}
}
