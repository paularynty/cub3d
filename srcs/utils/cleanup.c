/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- < mrahmat-@student.hive.fi >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/28 12:08:25 by mrahmat-         ###   ########.fr       */
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
	if (map->textures.east)
		mlx_delete_texture(map->textures.east);
	if (map->textures.west)
		mlx_delete_texture(map->textures.west);
	if (map->textures.north)
		mlx_delete_texture(map->textures.north);
	if (map->textures.south)
		mlx_delete_texture(map->textures.south);
}

static void	mlx_cleanup(t_game *game)
{
	if (game->assets.ceiling)
		mlx_delete_image(game->mlx, game->assets.ceiling);
	if (game->assets.floor)
		mlx_delete_image(game->mlx, game->assets.floor);
	if (game->assets.world)
		mlx_delete_image(game->mlx, game->assets.world);
	if (game->assets.minimap_floor)
		mlx_delete_image(game->mlx, game->assets.minimap_floor);
	if (game->assets.minimap_player)
		mlx_delete_image(game->mlx, game->assets.minimap_player);
	if (game->assets.minimap_wall)
		mlx_delete_image(game->mlx, game->assets.minimap_wall);
	if (game->assets.frog_image[0])
		mlx_delete_image(game->mlx, game->assets.frog_image[0]);
	if (game->assets.frog_image[1])
		mlx_delete_image(game->mlx, game->assets.frog_image[1]);
	if (game->assets.frog_image[2])
		mlx_delete_image(game->mlx, game->assets.frog_image[2]);
	if (game->assets.frog_image[3])
		mlx_delete_image(game->mlx, game->assets.frog_image[3]);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	cleanup(t_game *game)
{
	free_map(&game->map);
	mlx_cleanup(game);
	free(game);
}
