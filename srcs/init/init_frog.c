/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:46:13 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 20:07:21 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_frog_frames(t_game *game)
{
	int	i;

	game->assets.frog_texture[0] = mlx_load_png(IMG_FROG_1);
	game->assets.frog_texture[1] = mlx_load_png(IMG_FROG_2);
	game->assets.frog_texture[2] = mlx_load_png(IMG_FROG_3);
	game->assets.frog_texture[3] = mlx_load_png(IMG_FROG_4);
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
	return (TRUE);
}

void	display_frog(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (draw_image(game, game->assets.frog_image[i], \
				game->frog_x, game->frog_y) == FALSE)
			return ;
		game->assets.frog_image[i]->enabled = false;
		i++;
	}
	game->assets.frog_image[0]->enabled = true;
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
		game->assets.frog_image[game->frames]->instances[0].x = game->frog_x;
		game->assets.frog_image[game->frames]->instances[0].y = game->frog_y;
		mlx_set_instance_depth(game->assets.frog_image[game->frames]->instances,
			250);
		accumulated_time = 0;
	}
}
