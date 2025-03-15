/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:06:15 by prynty            #+#    #+#             */
/*   Updated: 2025/03/14 12:05:11 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	increment_frames(t_game *game)
{
	game->frames++;
	if (game->frames == INT_MAX - 1)
	{
		game->frames = 0;
	}
}

static void	animate_frog(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->assets.frog_image[i]->instances->x = game->frog_x;
		game->assets.frog_image[i]->instances->y = game->frog_y;
		i++;
	}
	game->assets.frog_image[game->frames / 6]->enabled = false;
	game->frames = (game->frames + 1) % 33;
	game->assets.frog_image[game->frames / 6]->enabled = true;
}

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
	game->window_h = height;
	game->window_w = width;
	render_world(game);
}

static void	mouse_hook(t_game *game)
{
	int32_t	pos_x;
	int32_t	pos_y;

	mlx_get_mouse_pos(game->mlx, &pos_x, &pos_y);
	if (pos_x < game->mouse_x)
		rotate_player(game, true, game->delta_time);
	else if (pos_x > game->mouse_x)
		rotate_player(game, false, game->delta_time);
	mlx_set_mouse_pos(game->mlx, game->window_w / 2, game->window_h / 2);
}

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
		mlx_close_window(game->mlx);
	key_move(game, x, y);
	key_rotate(game);
	mouse_hook(game);
	increment_frames(game);
	animate_frog(game);
	render_world(game);
}
