/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:06:15 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 13:19:39 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_frog(t_game *game)
{
	static double	last_time = 0;
    double			current_time;
	double			delta_time;
    current_time = mlx_get_time();
    delta_time = current_time - last_time;
	if (delta_time >= ANIMATION_SPEED)
	{
		game->assets.frog_image[game->frames]->enabled = false;
		game->frames = (game->frames + 1) % 4;
		game->assets.frog_image[game->frames]->enabled = true;
		game->assets.frog_image[game->frames]->instances[0].x = game->frog_x;
        game->assets.frog_image[game->frames]->instances[0].y = game->frog_y;
        game->assets.frog_image[game->frames]->instances[0].z = 200;
		last_time = current_time;
	}
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
	render_world(game);
}
