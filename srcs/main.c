#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	map;
	int32_t	map_file;

	map_file = validate_file(argc, argv[1]);
	if (map_file == FALSE)
		return (1);
	ft_bzero(&map, sizeof(game->map));
	game = (t_game *){0};
	if (!read_map(&map, map_file))
		return (1);
	game = init_game_data(game);
	if (!game)
		return (1);
	if (init(game, &map) == FALSE)
		return (1);
	mlx_key_hook(game->mlx, &key_hooks, game);
	// mlx_loop_hook(game->mlx, &game_hook, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
