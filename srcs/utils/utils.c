/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:15:43 by prynty            #+#    #+#             */
/*   Updated: 2025/03/15 17:16:30 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	set_z_index(mlx_image_t *img, int z)
{
	size_t	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].z = z;
		i++;
	}
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
