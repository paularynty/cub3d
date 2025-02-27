#include "cub3d.h"

static int	validate_args(int argc)
{
	if (argc != 2)
		return (print_error("Usage: ./cub3D [path_to_map].cub"));
	return (TRUE);
}

int	main(int argc, char **argv)
{
	//t_game	*game;
	t_map	map;
	int32_t	map_file;

	if (!validate_args(argc))
		return (1);
	map_file = validate_file(argv[1]);
	ft_bzero(&map, sizeof(t_map));
	if (!create_map(&map, map_file, argv[1]))
	{
		free_map(&map);
		return (1);
	}
	for (int i = 0; i < map.height; i++)
		printf("%s\n", map.map[i]);
	printf("Floor: %d,%d,%d,%d\n", map.floor.r, map.floor.g, map.floor.b, map.floor.a);
	printf("Ceiling: %d,%d,%d,%d\n", map.ceiling.r, map.ceiling.g, map.ceiling.b, map.ceiling.a);
	/* game = (t_game *){0};
	game = init_game_data(game);
	if (!game)
		return (1);
	if (!init_game(game))
		return (1);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx); */
	free_map(&map);
	return (0);
}
