#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int32_t	map_file;

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
	for (size_t i = 0; i < game->map.height; i++)
		printf("%s\n", game->map.map[i]);
	// printf("Floor: %d,%d,%d,%d\n", game->map.floor.r, game->map.floor.g, \
	// 	game->map.floor.b, game->map.floor.a);
	// printf("Ceiling: %d,%d,%d,%d\n", game->map.ceiling.r, game->map.ceiling.g, \
	// 	game->map.ceiling.b, game->map.ceiling.a);
	// printf("HERE map width is %zu\n", game->map.width);
	if (init(game, &game->map) == FALSE)
		return (1);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	free_map(&game->map);
	return (0);
}
