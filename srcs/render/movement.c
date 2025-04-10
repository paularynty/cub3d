/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:55:20 by prynty            #+#    #+#             */
/*   Updated: 2025/04/10 17:20:43 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == '1' \
		|| game->map.map[(int)y][(int)x] == ' ')
		return ;
	else if (game->map.map[(int)y][(int)x] == '0')
		game->map.map[(int)game->player.pos_y][(int)game->player.pos_x] = '0';
	game->player.pos_x = x;
	game->player.pos_y = y;
}

void	rotate_player(t_game *game, bool right, double delta_time)
{
	double	rotation_angle;
	double	temp_dir_x;
	double	temp_plane_x;
	double	cos_angle;
	double	sin_angle;

	if (right)
		rotation_angle = ROTATION_SPEED * delta_time;
	else
		rotation_angle = -ROTATION_SPEED * delta_time;
	temp_plane_x = game->player.plane_x;
	temp_dir_x = game->player.dir_x;
	cos_angle = cos(rotation_angle);
	sin_angle = sin(rotation_angle);
	game->player.dir_x = temp_dir_x * cos_angle \
		- game->player.dir_y * sin_angle;
	game->player.dir_y = temp_dir_x * sin_angle \
		+ game->player.dir_y * cos_angle;
	game->player.plane_x = temp_plane_x * cos_angle \
		- game->player.plane_y * sin_angle;
	game->player.plane_y = temp_plane_x * sin_angle \
		+ game->player.plane_y * cos_angle;
}
