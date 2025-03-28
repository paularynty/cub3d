/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/28 10:37:11 by mrahmat-         ###   ########.fr       */
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
		split_free(map->map);
}

static void	mlx_cleanup(t_game *game)
{
	mlx_delete_image(game->mlx, game->assets.ceiling);
	mlx_delete_image(game->mlx, game->assets.floor);
	mlx_delete_image(game->mlx, game->assets.world);
	mlx_delete_image(game->mlx, game->assets.minimap_floor);
	mlx_delete_image(game->mlx, game->assets.minimap_player);
	mlx_delete_image(game->mlx, game->assets.minimap_wall);
	mlx_delete_image(game->mlx, game->assets.frog_image[0]);
	mlx_delete_image(game->mlx, game->assets.frog_image[1]);
	mlx_delete_image(game->mlx, game->assets.frog_image[2]);
	mlx_delete_image(game->mlx, game->assets.frog_image[3]);
	mlx_terminate(game->mlx);
}

void	cleanup(t_game *game)
{
	free_map(&game->map);
	mlx_cleanup(game);
	free(game);
}
