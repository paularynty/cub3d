/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:37 by prynty            #+#    #+#             */
/*   Updated: 2025/03/28 12:03:06 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	int32_t		map_file;

	map_file = validate_file(argc, argv[1]);
	if (map_file == FALSE)
		return (1);
	game = (t_game *){0};
	game = init_game_data(game);
	if (!game)
		return (1);
	if (create_map(game, map_file, argv[1]) == -1)
	{
		cleanup(game);
		return (1);
	}
	if (init(game, &game->map) == FALSE)
		return (1);
	display_frog(game);
	mlx_loop_hook(game->mlx, &game_hook, game);
	mlx_resize_hook(game->mlx, &resize_window, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
