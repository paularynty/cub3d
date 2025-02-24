#include "cub3d.h"

static int32_t	render_image(t_game *game, size_t width, size_t height)
{
	if (mlx_image_to_window(game->mlx, game->images.test,
		width * TILESIZE, height * TILESIZE) == -1)
	{
		print_error("Failed to put wall image to window");
		return (FALSE);
	}
	return (TRUE);
}

static mlx_image_t	*load_image(mlx_t *mlx, const char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	image = NULL;
	texture = mlx_load_png(file);
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

static int	init_game_images(t_game *game)
{
	game->images.test = load_image(game->mlx, IMG_TEST);
	if (!game->images.test)
		return (FALSE);
	return (TRUE);
}

static int	init_mlx(t_game *game, int width, int height)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, height, "CUB3D YEEEEEEEEESSSSSSSSSSSSSsS", true);
	if (!mlx)
		return (-1);
	game->mlx = mlx;
	return (TRUE);
}

int	init_game(t_game *game)
{
	size_t	width;
	size_t	height;

	width = 5;
	height = 5;
	if (width > SCREEN_WIDTH || height > SCREEN_HEIGHT)
		return (print_error("Map is too large. Try with smaller map"));
	if (init_mlx(game, 500, 500) == -1)
		return (print_error("Failed to initialize MLX"));
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	if (!init_game_images(game) || !render_image(game, width, height))
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
