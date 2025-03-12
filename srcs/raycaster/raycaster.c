/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:46:11 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/12 15:03:51 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cast_ray(t_ray *ray, t_game *game)
{
    while (ray->hit == FALSE)
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
            ray->side = 1;
        }
        if (game->map.map[ray->map_y][ray->map_x] > '0')
        {
            ray->hit = TRUE;
            if (ray->side == 0)
                ray->wall_dist = (ray->map_x - game->player.pos_x \
                    + (1 - ray->step_x) / 2) / ray->dir_x;
            else
                ray->wall_dist = (ray->map_y - game->player.pos_y \
                    + (1 - ray->step_y) / 2) / ray->dir_y;
            if (ray->side == 0)
                ray->wall_hit_x = game->player.pos_y \
                    + ray->wall_dist * ray->dir_y;
            else
                ray->wall_hit_x = game->player.pos_x \
                    + ray->wall_dist * ray->dir_x;
            ray->wall_hit_x -= floor(ray->wall_hit_x);
        }
    }
}

void init_draw(t_ray *ray, t_game *game)
{
    ray->line_height = (int)(game->mlx->height / ray->wall_dist);
    ray->draw_start = (-ray->line_height) / 2 + game->mlx->height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + game->mlx->height / 2;
    if (ray->draw_end >= game->mlx->height)
        ray->draw_end = game->mlx->height - 1;
}

void render_world(t_game *game)
{
    uint32_t        x;
    mlx_texture_t   *texture;

    texture = NULL;
    if (game->assets.world != NULL)
        mlx_delete_image(game->mlx, game->assets.world);
    game->assets.world = mlx_new_image(game->mlx, game->window_w, game->window_h);
    if (!game->assets.world)
        return;

    x = 0;
    while (x < game->assets.world->width)
    {
        init_ray_info(x, &game->ray, &game->player, game->mlx);
        init_side_step(&game->ray, &game->player);
        cast_ray(&game->ray, game);
        init_draw(&game->ray, game);
        texture = determine_texture(game, texture);
        render_walls(x, game, game->assets.world, texture);
        x++;
    }
    mlx_image_to_window(game->mlx, game->assets.world, 0, 0);
}
