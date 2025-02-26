#include "cub3d.h"

// static int	draw_image(t_game *game, mlx_image_t *image, int32_t x, int32_t y)
// {
// 	mlx_image_to_window(game->mlx, image,
// 		x * TILESIZE, y * TILESIZE);
// 	if (mlx_image_to_window < 0)
// 	{
// 		print_error("Failed to put exit image to window");
// 		return (FALSE);
// 	}
// 	return (TRUE);
// }

// static int	draw_image(t_game *game, mlx_image_t *image, size_t x, size_t y)
// {
// 	if (mlx_image_to_window(game->mlx, image,
// 		x * TILESIZE, y * TILESIZE) == FALSE)
// 		return (print_error("Failed to put wall image to window"));
// 	return (TRUE);
// }

// static int	render_minimap(t_game *game)
// {
// 	int32_t	x;
// 	int32_t	y;

// 	y = 0;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < game->map.width)
// 		{
// 			if (game->map.map[y][x] == '1')
// 			{
// 				if (!draw_image(game, game->minimap.wall, x, y))
// 					return (FALSE);
// 			}
// 			else if (game->map.map[y][x] == '0')
// 			{
// 				if (!draw_image(game, game->minimap.floor, x, y))
// 					return (FALSE);
// 			}
// 			// else if (game->map[y][x] == 'C')
// 			// 	if (!draw_image(game, game->images.test, x, y))
// 			// 		return (FALSE);
// 			// else if (game->map[y][x] == 'E')
// 			// 	if (!draw_image(game, game->images.test, x, y))
// 			// 		return (FALSE);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (TRUE);
// }

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

// static void	draw_minimap(t_game *game, float scale)
// {
// 	int			y;
// 	int			x;
// 	int			tile_x;
// 	int			tile_y;

// 	y = -1;
// 	while (++y < game->minimap.minimap_size)
// 	{
// 		x = -1;
// 		while (++x < game->minimap.minimap_size)
// 		{
// 			tile_x = game->minimap.x0 + (x / scale);
// 			tile_y = game->minimap.y0 + (y / scale);
// 			if (tile_x >= 0 && tile_x < (int)(TILESIZE * game->map.width) &&
// 				tile_y >= 0 && tile_y < (int)(TILESIZE * game->map.height))
// 			{
// 				if (game->map.map[tile_y / TILESIZE][tile_x / TILESIZE] == '1')
// 					mlx_put_pixel(game->minimap.minimap, x, y, 0xFFFFFFFF);
// 				else
// 					mlx_put_pixel(game->minimap.minimap, x, y, 0x000000FF);
// 			}
// 		}
// 	}
// }

// static void	draw_minimap(t_game *game, t_map *map)
// {
// 	int	i;

// 	draw_tiles(game, map->map);
// 	draw_chars(game, map->map);
// 	set_z_index(game->minimap.wall, -200);
// 	set_z_index(game->minimap.floor, -200);
// }

// void	minimap(t_game *game)
// {
// 	float	scale;

// 	// mlx_delete_image(game->mlx, game->minimap.minimap);
// 	// game->minimap.minimap = mlx_new_image(game->mlx, game->window_width, game->window_height);
// 	scale = (float)game->map.width / 5000;
// 	game->minimap.minimap_size = fmin(game->window_w / 4, game->window_h / 4);
// 	game->minimap.view_width = game->minimap.minimap_size / scale;
// 	game->minimap.view_height = game->minimap.minimap_size / scale;
// 	game->minimap.x0 = 500 - game->minimap.view_width / 2;
// 	game->minimap.y0 = 500 - game->minimap.view_height / 2;
// 	// draw_minimap(game, scale);
// 	render_minimap(game);
// 	set_z_index(game->minimap.wall, -200);
// 	set_z_index(game->minimap.floor, -200);
// }
