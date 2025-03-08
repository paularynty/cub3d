/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:46:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/08 18:26:38 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_game *game)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] > '0')
			hit = TRUE;
	}
}

void	init_draw(t_game *game)
{
	double	wall_dist;
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 0)
		wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = game->mlx->height / wall_dist;
	ray->draw_start = -ray->line_height / 2 + game->mlx->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->mlx->height / 2;
	if (ray->draw_end >= game->mlx->height)
		ray->draw_end = game->mlx->height - 1;
}
