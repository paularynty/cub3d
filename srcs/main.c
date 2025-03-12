#include "cub3d.h"

// void	test_draw(int x, t_game *game, mlx_image_t *image)
// {
// 	int			y;

// 	y = game->ray.draw_start;
// 	while (y < game->ray.draw_end)
// 	{
// 		if (game->ray.side == 0)
// 			mlx_put_pixel(image, x, y, rgba(255, 1, 1, 255));
// 		else
// 			mlx_put_pixel(image, x, y, rgba(127, 1, 1, 255));
// 		y++;
// 	}
// }

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
	game->assets.world = NULL;
	//render_world(game);
	//mlx_image_to_window(game->mlx, game->assets.world, 0, 0);
	mlx_loop_hook(game->mlx, &key_hooks, game);
	mlx_resize_hook(game->mlx, &resize_window, game);
	mlx_loop(game->mlx);
	free_map(&game->map);
	return (0);
}
