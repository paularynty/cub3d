/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:44:37 by prynty            #+#    #+#             */
/*   Updated: 2025/03/13 21:44:39 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_frog(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (draw_image(game, game->assets.frog_image[i], game->frog_x, game->frog_y) == FALSE)
			return ;
		game->assets.frog_image[i]->enabled = false;
		i++;
	}
	game->assets.frog_image[0]->enabled = true;
}

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
	ft_bzero(&game->map, sizeof(t_map));
	if (create_map(game, map_file, argv[1]) == -1)
	{
		free_map(&game->map);
		return (1);
	}
	if (init(game, &game->map) == FALSE)
		return (1);
	display_frog(game);
	mlx_loop_hook(game->mlx, &game_hook, game);
	mlx_resize_hook(game->mlx, &resize_window, game);
	mlx_loop(game->mlx);
	free_map(&game->map);
	return (0);
}
