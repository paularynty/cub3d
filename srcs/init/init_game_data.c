/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:49 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 20:12:15 by prynty           ###   ########.fr       */
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

static void	init_game_variables(t_game *game)
{
	game->mlx = NULL;
	game->assets.world = NULL;
	game->assets.floor = NULL;
	game->assets.ceiling = NULL;
	game->assets.minimap_floor = NULL;
	game->assets.minimap_wall = NULL;
	game->assets.minimap_player = NULL;
	game->delta_time = -1;
	game->frames = 0;
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
	game->frog_x = (game->window_width / 2) + (game->window_width / 8);
	game->frog_y = (game->window_height / 2) + (game->window_height / 6);
	return (game);
}
