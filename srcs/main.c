/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:37 by prynty            #+#    #+#             */
/*   Updated: 2025/04/10 18:18:58 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_data(t_game *game)
{
	if (game->map.map == NULL)
		return (print_error("No map in map file"));
	if (game->map.ceiling.color == 0)
		return (print_error("No ceiling color specified in map file"));
	if (game->map.floor.color == 0)
		return (print_error("No floor color specified in map file"));
	if (game->map.textures.east == NULL)
		return (print_error("No texture for east wall specified in map file"));
	if (game->map.textures.west == NULL)
		return (print_error("No texture for west wall specified in map file"));
	if (game->map.textures.north == NULL)
		return (print_error("No texture for north wall specified in map file"));
	if (game->map.textures.south == NULL)
		return (print_error("No texture for south wall specified in map file"));
	return (1);
}

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
	if (check_data(game) < 0)
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
