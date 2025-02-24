#include "cub3d.h"

t_game	*init_game_data(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed");
		return (NULL);
	}
	game->mlx = NULL;
	game->map_height = 0;
	game->map_width = 0;
	return (game);
}
