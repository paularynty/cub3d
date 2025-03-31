/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:27:41 by prynty            #+#    #+#             */
/*   Updated: 2025/03/31 16:25:32 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_color(mlx_image_t *image, int color, uint32_t width, \
		uint32_t height)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_pixel(image, x, y, (uint32_t)color);
			++x;
		}
		++y;
	}
}

void	get_pixel_data(mlx_texture_t *texture, t_color *color, size_t coords)
{
	if (coords + 3 >= (texture->width * texture->height * 4))
		return ;
	color->r = texture->pixels[coords];
	color->g = texture->pixels[coords + 1];
	color->b = texture->pixels[coords + 2];
	color->a = texture->pixels[coords + 3];
	color->color = rgba(color->r, color->g, color->b, color->a);
}
