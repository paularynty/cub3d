/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/10 12:18:56 by prynty           ###   ########.fr       */
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

// void	game_hook(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	minimap(game);
// }

void	key_hooks(t_game *game)
{
	// t_game	*game;
	mlx_key_data_t	data;
	size_t	x;
	size_t	y;

	// game = (t_game *)param;
	x = game->player.pos_x;
	y = game->player.pos_y;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP) 
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		move_player_minimap(game, x, y - 1);
		move_player(game, true);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		move_player_minimap(game, x, y + 1);
		move_player(game, false);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_minimap(game, x - 1, y);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_minimap(game, x + 1, y);
}

void	game_hook(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	key_hooks(game);
	// rotate_player(game, right);
}

void	cleanup(t_game *game)
{
	if (game)
		free(game);
}
