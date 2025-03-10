#include "cub3d.h"

// static void	update_movement_minimap(t_game *game, int x, int y)
// {
// 	game->map.map[game->player.pos_y][game->player.pos_x] = '0';
// 	game->map.map[y][x] = 'N';
// 	game->minimap.player->instances[0].x = x * TILESIZE;
// 	game->minimap.player->instances[0].y = y * TILESIZE;
// }

static void	update_movement_minimap_float(t_game *game, double x, double y)
{
	game->map.map[(int)game->player.pos_y][(int)game->player.pos_x] = '0';
	// game->map.map[(int)y][(int)x] = 'N';
	game->minimap.player->instances[0].x = (int)x * TILESIZE;
	game->minimap.player->instances[0].y = (int)y * TILESIZE;
}

void	move_player_minimap(t_game *game, double x, double y)
{
	if (game->map.map[(int)y][(int)x] == '1')
		return ;
	else if (game->map.map[(int)y][(int)x] == '0')
		update_movement_minimap_float(game, x, y);
	game->player.pos_x = x;
	game->player.pos_y = y;
}
