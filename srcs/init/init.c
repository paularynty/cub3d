#include "cub3d.h"

// static int	render_image(t_game *game, mlx_image_t *image, size_t x, size_t y)
// {
// 	if (mlx_image_to_window(game->mlx, image,
// 		x * TILESIZE, y * TILESIZE) == FALSE)
// 		return (print_error("Failed to put wall image to window"));
// 	return (TRUE);
// }

static mlx_image_t	*load_image(mlx_t *mlx, const char *image_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	image = NULL;
	texture = mlx_load_png(image_path);
	if (!texture)
	{
		print_error("Failed to load texture");
		return (NULL);
	}
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		print_error("Failed to transform texture to image");
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}

int32_t	validate_file(int argc, char *file)
{
	int32_t	map_file;
	size_t	path_len;

	if (argc != 2)
		return (print_error("Usage: ./cub3D [path_to_map].cub"));
	if (!file[0])
		return (print_error("Empty path"));
	path_len = ft_strlen(file);
	if (path_len < 4 || ft_strncmp(&file[path_len - 4], ".cub", 4))
		return (print_error("Invalid file format\nSupported file format: .cub"));
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
		return (print_error("Could not find map file"));
	return (map_file);
}

static int	init_mlx(t_game *game, int width, int height)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, height, "CUB3D YEEEEEEEEESSSSSSSSSSSSSsS", true);
	if (!mlx)
		return (FALSE);
	game->mlx = mlx;
	return (TRUE);
}

static void	set_cursor(t_game *game)
{
	void			*cursor;
	mlx_texture_t	*cursor_texture;

	cursor_texture = mlx_load_png(IMG_CURSOR);
	cursor = mlx_create_cursor(cursor_texture);
	mlx_delete_texture(cursor_texture);
	mlx_set_cursor(game->mlx, cursor);
}

static int	draw_image(t_game *game, mlx_image_t *image, size_t x, size_t y)
{
	if (mlx_image_to_window(game->mlx, image,
		x * 32, y * 32) == FALSE)
		return (print_error("Failed to put wall image to window"));
	return (TRUE);
}

static int	render_minimap(t_game *game, t_map *map)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	printf("map width is %d\n", map->width);
	printf("map height is %d\n", map->height);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (!draw_image(game, game->minimap.wall, x, y))
					return (FALSE);
			}
			else if (map->map[y][x] == '0')
			{
				if (!draw_image(game, game->minimap.floor, x, y))
					return (FALSE);
			}
			else if (map->map[y][x] == 'N' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'S' || map->map[y][x] == 'W')
			{
				if (!draw_image(game, game->minimap.floor, x, y))
					return (FALSE);
				if (!draw_image(game, game->minimap.player, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

// static void	set_z_index(mlx_image_t *img, int z)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < img->count)
// 	{
// 		img->instances[i].z = z;
// 		i++;
// 	}
// }

int	init(t_game *game, t_map *map)
{
	if (init_mlx(game, game->window_w, game->window_h) == FALSE)
		return (print_error("Failed to initialize MLX"));
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	set_cursor(game);
	game->minimap.minimap = mlx_new_image(game->mlx, game->window_w, game->window_h);
	if (mlx_image_to_window(game->mlx, game->minimap.minimap, 0, 0) == -1)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	game->minimap.floor = load_image(game->mlx, IMG_FLOOR);
	if (!game->minimap.floor)
		return (FALSE);
	game->minimap.wall = load_image(game->mlx, IMG_WALL);
	if (!game->minimap.wall)
		return (FALSE);
	game->minimap.player = load_image(game->mlx, IMG_PLAYER);
	if (!game->minimap.wall)
		return (FALSE);
	if (render_minimap(game, map) == FALSE)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	// set_z_index(game->minimap.wall, -200);
	// set_z_index(game->minimap.floor, -200);
	return (TRUE);
}
