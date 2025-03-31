/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/31 20:21:35 by prynty           ###   ########.fr       */
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
	int	i;

	if (game->assets.world)
		mlx_delete_image(game->mlx, game->assets.world);
	i = 0;
	while (i < 4)
		mlx_delete_image(game->mlx, game->assets.frog_image[i++]);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	cleanup(t_game *game)
{
	free_map(&game->map);
	if (game->map.map_fd > 2)
		close(game->map.map_fd);
	mlx_cleanup(game);
	free(game);
}
