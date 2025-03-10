/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:55:20 by prynty            #+#    #+#             */
/*   Updated: 2025/03/10 12:13:26 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_player(t_game *game, bool forward) 
{
    float	step;
	float	new_x;
	float 	new_y;

	if (forward)
		step = MOVE_SPEED;
	else
		step = -MOVE_SPEED;
    new_x = step * game->player.pos_x + game->player.dir_x;
    new_y = step * game->player.pos_y + game->player.dir_y;

    // // Collision detection (only move if the next position is not a wall)
    // if (game->map.map[(int)newX][(int)player->y] == 0) player->x = newX;
    // if (worldMap[(int)player->x][(int)newY] == 0) player->y = newY;
}

void rotate_player(t_game *game, bool right)
{
    float rotation_angle;
    float temp_dir_x;
    float temp_plane_x;
    float cos_angle;
    float sin_angle;
	
	if (right)
    	rotation_angle = ROTATION_SPEED;
	else
		rotation_angle = -ROTATION_SPEED;
    temp_plane_x = game->player.plane_x;
    temp_dir_x = game->player.dir_x;
    cos_angle = cos(rotation_angle);
    sin_angle = sin(rotation_angle);

    // Rotate direction vector
    game->player.dir_x = temp_dir_x * cos_angle - game->player.dir_y * sin_angle;
    game->player.dir_y = temp_dir_x * sin_angle + game->player.dir_y * cos_angle;

    // Rotate camera plane and maintain correct field of view
    game->player.plane_x = temp_plane_x * cos_angle - game->player.plane_y * sin_angle;
    game->player.plane_y = temp_plane_x * sin_angle + game->player.plane_y * cos_angle;
}