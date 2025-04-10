/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/04/10 17:50:39 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	split_free(char **arr, int err, char *err_msg)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	if (err == 1)
		return (print_error(err_msg));
	else
		return (FALSE);
}

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
		split_free(map->map, 0, NULL);
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
	if (game->assets.world)
		mlx_delete_image(game->mlx, game->assets.world);
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
