#include "cub3d.h"

static void	get_pixel_data(mlx_texture_t *texture, t_color *color, \
	size_t pixel_coords)
{
	if (pixel_coords + 3 >= (texture->width * texture->height * 4))
		return ;
	color->r = texture->pixels[pixel_coords];
	color->g = texture->pixels[pixel_coords + 1];
	color->b = texture->pixels[pixel_coords + 2];
	color->a = texture->pixels[pixel_coords + 3];
	color->color = rgba(color->r, color->g, color->b, color->a);
}

uint32_t	get_x_coord(t_game *game, mlx_texture_t *texture)
{
	int	texture_x;

	if (game->ray.hit == true)
	{
		// if (game->ray.direction_up == false)
		// 	x = (1 - fmod(game->ray.dir_x, TILESIZE) / TILESIZE) \
		// 		* texture->width;
		// else
		texture_x = fmod(game->ray.dir_x, TILESIZE) / TILESIZE \
				* texture->width;
	}
	else
	{
		// if (game->ray.direction_left == true)
		// 	x = (1 - fmod(game->ray.dir_x, TILESIZE) / TILESIZE) \
		// 		* texture->width;
		// else
		texture_x = fmod(game->ray.dir_y, TILESIZE) / TILESIZE \
				* texture->width;
	}
	return (texture_x);
}

void	test_draw(int x, t_game *game, mlx_image_t *image, mlx_texture_t *texture)
{
	t_color		color;
	int			step;
	uint32_t	texture_x;
	uint32_t	texture_y;
	int			y;

	y = game->ray.draw_start;
	step = texture->height / game->ray.line_height;
	texture_x = get_x_coord(game, texture);
	texture_y = (y - (game->window_h / 2) + (game->ray.line_height / 2) * step);
	while (y < game->ray.draw_end)
	{
		get_pixel_data(texture, &color, ((texture->width * (int)texture_y + texture_x) * 4));
		mlx_put_pixel(image, x, y, color.color);
		y++;
		texture_y += step;
		if (texture_y >= texture->height)
			texture_y -= texture->height;
	}
}

// void	test_draw(int x, t_game *game, mlx_image_t *image, mlx_texture_t *texture)
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

/* static void	init_image(t_map *map, mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			if (y > image->height / 2)
				mlx_put_pixel(image, x, y, map->floor.color);
			else
				mlx_put_pixel(image, x, y, map->ceiling.color);
			x++;
		}
		y++;
	}
} */

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
	/* for (size_t i = 0; i < game->map.height; i++)
		printf("%s\n", game->map.map[i]);
	printf("Floor: %d,%d,%d,%d\n", game->map.floor.r, game->map.floor.g, \
	game->map.floor.b, game->map.floor.a);
	printf("Ceiling: %d,%d,%d,%d\n", game->map.ceiling.r, game->map.ceiling.g, \
	game->map.ceiling.b, game->map.ceiling.a);
	printf("HERE map width is %zu\n", game->map.width); */
	if (init(game, &game->map) == FALSE)
		return (1);
	game->assets.world = NULL;
	render_world(game);
	mlx_image_to_window(game->mlx, game->assets.world, 0, 0);
	mlx_key_hook(game->mlx, &key_hooks, game);
	mlx_loop(game->mlx);
	free_map(&game->map);
	return (0);
}
