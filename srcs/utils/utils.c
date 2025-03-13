/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:16:34 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/13 21:52:11 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	get_delta_time(void)
{
	double			current_time;
	double			delta_time;
	static double	last_time = 0;

	current_time = mlx_get_time();
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}

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

void	cleanup(t_game *game)
{
	if (game)
		free(game);
}
