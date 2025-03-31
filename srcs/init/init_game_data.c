/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:49 by prynty            #+#    #+#             */
/*   Updated: 2025/03/31 16:49:45 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_window_size(uint32_t *window_width, uint32_t *window_height)
{
	int32_t	screen_width;
	int32_t	screen_height;
	mlx_t	*temp;

	temp = mlx_init(1, 1, "", false);
	if (!temp)
		return (print_error("Failed to initialize window"));
	mlx_get_monitor_size(0, &screen_width, &screen_height);
	mlx_terminate(temp);
	*window_width = screen_width / 2;
	*window_height = screen_height / 2;
	return (TRUE);
}

static void	init_player_data(t_player *player)
{
	player->angle = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->pos_x = 0;
	player->pos_y = 0;
}

static void	init_map(t_map *map)
{
	map->map = NULL;
	map->textures.east = NULL;
	map->textures.west = NULL;
	map->textures.north = NULL;
	map->textures.south = NULL;
	map->height = 0;
	map->width = 0;
	map->ceiling = (t_color){0};
	map->floor = (t_color){0};
	map->map_fd = -1;
}

static void	init_game_variables(t_game *game)
{
	game->mlx = NULL;
	game->assets.world = NULL;
	game->assets.frog_image[0] = NULL;
	game->assets.frog_image[1] = NULL;
	game->assets.frog_image[2] = NULL;
	game->assets.frog_image[3] = NULL;
	game->delta_time = -1;
	game->frames = 0;
	init_player_data(&game->player);
	init_map(&game->map);
}

t_game	*init_game_data(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed");
		return (NULL);
	}
	init_game_variables(game);
	if (get_window_size(&game->window_width, &game->window_height) == FALSE)
		return (NULL);
	return (game);
}
