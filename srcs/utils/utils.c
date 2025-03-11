/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/11 14:27:59 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	if (map->map)
	{
		split_free(map->map);
		map->map = NULL;
	}
}

int	print_error(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(RESET, 2);
	ft_putendl_fd(msg, 2);
	return (FALSE);
}

static void	key_move(t_game *game, double x, double y)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_minimap(game, x + game->player.dir_x * MOVE_SPEED, \
			y + game->player.dir_y * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_minimap(game, x - game->player.dir_x * MOVE_SPEED, \
			y - game->player.dir_y * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_minimap(game, x - game->player.dir_y * MOVE_SPEED, \
			y + game->player.dir_x * MOVE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_minimap(game, x + game->player.dir_y * MOVE_SPEED, \
			y - game->player.dir_x * MOVE_SPEED);
}

static void	key_rotate(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, false);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, true);
}

void	key_hooks(mlx_key_data_t data, void *param)
{
	t_game	*game;
	double	x;
	double	y;

	game = (t_game *)param;
	x = game->player.pos_x;
	y = game->player.pos_y;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	key_move(game, x, y);
	key_rotate(game);
	render_world(game);
}

void	cleanup(t_game *game)
{
	if (game)
		free(game);
}
