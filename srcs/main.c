#include "cub3d.h"

static void	test_draw(int x, t_game *game, mlx_image_t *image)
{
	int			y;
	uint32_t	color;

	color = rgba(1, 0, 0, 255);
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		if (game->ray.side == 0)
			mlx_put_pixel(image, x, y, color);
		else
			mlx_put_pixel(image, x, y, color / 2);
		y++;
	}
}

static void	init_image(mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, rgba(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game		*game;
	int32_t		map_file;
	mlx_image_t	*image;

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
	/* for (size_t i = 0; i < game->map.height; i++)
		printf("%s\n", game->map.map[i]);
	printf("Floor: %d,%d,%d,%d\n", game->map.floor.r, game->map.floor.g, \
	game->map.floor.b, game->map.floor.a);
	printf("Ceiling: %d,%d,%d,%d\n", game->map.ceiling.r, game->map.ceiling.g, \
	game->map.ceiling.b, game->map.ceiling.a);
	printf("HERE map width is %zu\n", game->map.width); */
	if (init(game, &game->map) == FALSE)
		return (1);
	image = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (!image)
		return (1);
	init_image(image);
	for (int x = 0; x < game->mlx->width; x++)
	{
		init_ray_info(x, &game->ray, &game->player, game->mlx);
		init_side_step(&game->ray, &game->player);
		cast_ray(&game->ray, game);
		init_draw(&game->ray, game);
		test_draw(x, game, image);
	}
	mlx_image_to_window(game->mlx, image, 0, 0);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	free_map(&game->map);
	return (0);
}
