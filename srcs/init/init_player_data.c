/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:40:25 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/14 12:18:04 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_direction_ns(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	init_player_direction_we(t_player *player, char dir)
{
	if (dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

int	init_player(t_player *player, size_t x, size_t y, char dir)
{
	if (player->pos_x != 0 || player->pos_y != 0)
		return (print_error("Too many players in map, need only one (1)"));
	player->pos_x = x + 0.2;
	player->pos_y = y + 0.2;
	if (dir == 'N' || dir == 'S')
		init_player_direction_ns(player, dir);
	else if (dir == 'W' || dir == 'E')
		init_player_direction_we(player, dir);
	return (TRUE);
}
