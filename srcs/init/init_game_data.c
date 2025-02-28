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
	return (game);
}

int	init_player(t_player *player, size_t x, size_t y, char dir)
{
	if (player->pos_x != 0 || player->pos_y != 0)
		return (print_error("Too many players in the map! (Needed 1)"));
	player->pos_x = x;
	player->pos_y = y;
	if (dir == 'N')
		player->dir = NORTH;
	else if (dir == 'S')
		player->dir = SOUTH;
	else if (dir == 'E')
		player->dir = EAST;
	else if (dir == 'W')
		player->dir = WEST;
	return (1);
}
