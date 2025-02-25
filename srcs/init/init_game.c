#include "cub3d.h"

static int	render_image(t_game *game, mlx_image_t *image, size_t x, size_t y)
{
	if (mlx_image_to_window(game->mlx, image,
		x * TILESIZE, y * TILESIZE) == FALSE)
		return (print_error("Failed to put wall image to window"));
	return (TRUE);
}

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

int	init_game(t_game *game)
{
	size_t	window_width;
	size_t	window_height;

	window_width = SCREEN_WIDTH / 2;
	window_height = SCREEN_HEIGHT / 2;
	if (init_mlx(game, window_width, window_height) == FALSE)
		return (print_error("Failed to initialize MLX"));
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	set_cursor(game);
	game->minimap.floor = load_image(game->mlx, IMG_FLOOR);
	if (!game->minimap.floor)
		return (FALSE);
	game->minimap.wall = load_image(game->mlx, IMG_WALL);
	if (!game->minimap.wall)
		return (FALSE);
	if (!render_image(game, game->minimap.wall, 5, 5) 
		|| !render_image(game, game->minimap.floor, 5, 5))
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
