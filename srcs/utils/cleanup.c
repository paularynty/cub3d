/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/15 17:17:28 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(RESET, 2);
	ft_putendl_fd(msg, 2);
	return (FALSE);
}

void	free_map(t_map *map)
{
	if (map->map)
	{
		split_free(map->map);
		map->map = NULL;
	}
}

static void	mlx_cleanup(t_game *game)
{
	mlx_destroy_cursor(game->assets.cursor);
	mlx_delete_image(game->mlx, game->assets.ceiling);
	mlx_delete_image(game->mlx, game->assets.floor);
	mlx_delete_texture(game->map.textures.north);
	mlx_delete_texture(game->map.textures.south);
	mlx_delete_texture(game->map.textures.east);
	mlx_delete_texture(game->map.textures.west);
	mlx_terminate(game->mlx);
}

void	cleanup(t_game *game)
{
	free_map(&game->map);
	mlx_cleanup(game);
	free(game);
}
