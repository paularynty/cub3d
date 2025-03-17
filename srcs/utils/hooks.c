/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:06:15 by prynty            #+#    #+#             */
/*   Updated: 2025/03/15 17:20:24 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_move(t_game *game, double x, double y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_minimap(game, x + game->player.dir_x * MOVE_SPEED, \
			y + game->player.dir_y * MOVE_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_minimap(game, x - game->player.dir_x * MOVE_SPEED, \
			y - game->player.dir_y * MOVE_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_minimap(game, x + game->player.dir_y * MOVE_SPEED, \
			y - game->player.dir_x * MOVE_SPEED);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_minimap(game, x - game->player.dir_y * MOVE_SPEED, \
			y + game->player.dir_x * MOVE_SPEED);
}

static void	key_rotate(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, true, game->delta_time);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, false, game->delta_time);
}

void	resize_window(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = param;
	game->window_height = height;
	game->window_width = width;
	mlx_resize_image(game->assets.floor, game->window_width, game->window_height / 2);
	mlx_resize_image(game->assets.ceiling, game->window_width, game->window_height / 2);
	render_world(game);
}

// static void	mouse_hook(t_game *game)
// {
// 	int32_t	pos_x;
// 	int32_t	pos_y;

// 	mlx_get_mouse_pos(game->mlx, &pos_x, &pos_y);
// 	if (pos_x < game->mouse_x)
// 		rotate_player(game, true, game->delta_time);
// 	else if (pos_x > game->mouse_x)
// 		rotate_player(game, false, game->delta_time);
// 	mlx_set_mouse_pos(game->mlx, game->window_width / 2, game->window_height / 2);
// }

void	game_hook(void *param)
{
	t_game	*game;
	double	x;
	double	y;

	game = (t_game *)param;
	x = game->player.pos_x;
	y = game->player.pos_y;
	game->delta_time = get_delta_time();
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	key_move(game, x, y);
	key_rotate(game);
	// mouse_hook(game);
	render_world(game);
}
