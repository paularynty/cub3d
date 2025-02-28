#include "cub3d.h"

static int	get_window_size(uint32_t *window_width, uint32_t *window_height)
{
	int32_t	screen_width;
	int32_t	screen_height;
	mlx_t	*temp;

	temp = mlx_init(1, 1, "", false);
	if (!temp)
		return (print_error("Failed to initialize window"));
	mlx_get_monitor_size(0, &screen_width, &screen_height);
	// printf("%d %d\n", screen_width, screen_height);
	mlx_terminate(temp);
	*window_width = screen_width / 2;
	*window_height = screen_height / 2;
	return (TRUE);
}

t_game	*init_game_data(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed");
		return (NULL);
	}
	game->mlx = NULL;
	if (get_window_size(&game->window_w, &game->window_h) == FALSE)
		return (NULL);
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
