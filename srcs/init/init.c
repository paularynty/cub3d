#include "cub3d.h"

// static int	render_image(t_game *game, mlx_image_t *image, size_t x, size_t y)
// {
// 	if (mlx_image_to_window(game->mlx, image,
// 		x * TILESIZE, y * TILESIZE) == FALSE)
// 		return (print_error("Failed to put wall image to window"));
// 	return (TRUE);
// }

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

int	init(t_game *game, t_map *map)
{
	if (init_mlx(game, game->window_w, game->window_h) == FALSE)
		return (print_error("Failed to initialize MLX"));
	//mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	set_cursor(game);
	render_game(game);
	if (init_minimap(game, map) == FALSE)
		return (FALSE);
	return (TRUE);
}
