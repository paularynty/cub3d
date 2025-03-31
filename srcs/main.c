/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:37 by prynty            #+#    #+#             */
/*   Updated: 2025/03/31 13:10:08 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		return (print_error("Usage: ./cub3D [path_to_map].cub"));
	game = (t_game *){0};
	game = init_game_data(game);
	if (!game)
		return (1);
	if (create_map(game, argv[1]) == FALSE || init(game) == FALSE)
	{
		cleanup(game);
		return (1);
	}
	mlx_loop_hook(game->mlx, &game_hook, game);
	mlx_resize_hook(game->mlx, &resize_window, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
