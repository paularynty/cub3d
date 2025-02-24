#include "cub3d.h"

void	key_hooks(mlx_key_data_t data, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
}

// int	minimap(void)
// {
// 	return (TRUE);
// }