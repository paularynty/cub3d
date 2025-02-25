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

// int	render_minimap(t_game *game, t_map *map)
// {
// 	int32_t	x;
// 	int32_t	y;

// 	y = 0;
// 	while (y < map->rows)
// 	{
// 		x = 0;
// 		while (x < map->columns)
// 		{
// 			if (map->map[y][x] == '1')
// 				if (!draw_image(game, game->images.wall, x, y))
// 					return (FALSE);
// 			else if (game->map[y][x] == '0')
// 				if (!draw_image(game, game->images.floor, x, y))
// 					return (FALSE);
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

// static void	draw_minimap(t_game *game, t_minimap *minimap, float scale)
// {
// 	int			y;
// 	int			x;
// 	int			tile_x;
// 	int			tile_y;

// 	y = -1;
// 	while (++y < minimap->minimap_size)
// 	{
// 		x = -1;
// 		while (++x < minimap->minimap_size)
// 		{
// 			tile_x = minimap.x0 + (x / scale);
// 			tile_y = minimap.y0 + (y / scale);
// 			if (tile_x >= 0 && tile_x < (int)(TILESIZE * game->map.width) &&
// 				tile_y >= 0 && tile_y < (int)(TILESIZE * game->map.height))
// 			{
// 				if (game->map.map[tile_y / TILESIZE][tile_x / TILESIZE] == '1')
// 					mlx_put_pixel(minimap->minimap, x, y, 0xFFFFFFFF);
// 				else
// 					mlx_put_pixel(minimap->minimap, x, y, 0x000000FF);
// 			}
// 		}
// 	}
// }

// void	minimap(t_game *game, t_minimap *minimap, int width, int height)
// {
// 	minimap->minimap_size = fmin(width / 4, height / 4);
// 	draw_minimap(game, minimap, scale);
// }
