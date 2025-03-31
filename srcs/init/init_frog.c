/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:07:36 by prynty            #+#    #+#             */
/*   Updated: 2025/03/31 21:09:38 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display_frog(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx_image_to_window(game->mlx, game->assets.frog_image[i], \
				game->frog_x, game->frog_y) == FALSE)
			return (FALSE);
		game->assets.frog_image[i]->enabled = false;
		mlx_set_instance_depth(game->assets.frog_image[i]->instances, 250);
		i++;
	}
	game->assets.frog_image[0]->enabled = true;
	return (TRUE);
}

int	init_frog_frames(t_game *game)
{
	int	i;

	game->assets.frog_texture[0] = mlx_load_png(IMG_FROG_1);
	game->assets.frog_texture[1] = mlx_load_png(IMG_FROG_2);
	game->assets.frog_texture[2] = mlx_load_png(IMG_FROG_3);
	game->assets.frog_texture[3] = mlx_load_png(IMG_FROG_4);
	if (!game->assets.frog_texture[0] || !game->assets.frog_texture[1]
		|| !game->assets.frog_texture[2] || !game->assets.frog_texture[3])
		return (print_error("Failed to load frog texture"));
	i = 0;
	while (i < 4)
	{
		(game->assets.frog_image)[i] = mlx_texture_to_image(game->mlx, \
				(game->assets.frog_texture)[i]);
		if (!(game->assets.frog_image)[i])
			return (print_error("Failed to create frog image"));
		mlx_delete_texture((game->assets.frog_texture)[i]);
		i++;
	}
	if (display_frog(game) == FALSE)
		return (print_error("Failed to display frog"));
	return (TRUE);
}

void	animate_frog(t_game *game)
{
	static double	accumulated_time = 0;

	accumulated_time += game->delta_time;
	if (accumulated_time >= ANIMATION_SPEED)
	{
		game->assets.frog_image[game->frames]->enabled = false;
		game->frames = (game->frames + 1) % 4;
		game->assets.frog_image[game->frames]->enabled = true;
		game->assets.frog_image[game->frames]->instances[game->frames].x \
			= game->frog_x;
		game->assets.frog_image[game->frames]->instances[game->frames].y \
			= game->frog_y;
		accumulated_time = 0;
	}
}
