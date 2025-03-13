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
	mlx_terminate(temp);
	*window_width = screen_width / 2;
	*window_height = screen_height / 2;
	return (TRUE);
}

static void	init_game_variables(t_game *game)
{
	game->mlx = NULL;
	game->assets.world = NULL;
	game->assets.floor = NULL;
	game->assets.ceiling = NULL;
}

t_game	*init_game_data(t_game *game)
{
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error("Memory allocation failed");
		return (NULL);
	}
	init_game_variables(game);
	if (get_window_size(&game->window_w, &game->window_h) == FALSE)
		return (NULL);
	return (game);
}
