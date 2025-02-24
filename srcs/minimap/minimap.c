#include "cub3d.h"

static int	draw_image(t_game *game, mlx_image_t *image, int32_t x, int32_t y)
{
	mlx_image_to_window(game->mlx, image,
		x * TILESIZE, y * TILESIZE);
	if (mlx_image_to_window < 0)
	{
		print_error("Failed to put exit image to window");
		return (-1);
	}
	return (TRUE);
}

int	render_minimap(t_game *game, t_map *map)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->map[y][x] == '1')
				if (!draw_image(game, game->images.wall, x, y))
					return (FALSE);
			// else if (game->map[y][x] == 'P')
			// 	if (!draw_image(game, game->images.test, x, y))
			// 		return (FALSE);
			// else if (game->map[y][x] == 'C')
			// 	if (!draw_image(game, game->images.test, x, y))
			// 		return (FALSE);
			// else if (game->map[y][x] == 'E')
			// 	if (!draw_image(game, game->images.test, x, y))
			// 		return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}
