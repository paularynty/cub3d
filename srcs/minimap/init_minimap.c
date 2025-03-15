/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:34:46 by prynty            #+#    #+#             */
/*   Updated: 2025/03/13 21:45:24 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_image(t_game *game, mlx_image_t *image, uint32_t x, uint32_t y)
{
	if (mlx_image_to_window(game->mlx, image,
		x * TILESIZE, y * TILESIZE) == FALSE)
		return (print_error("Failed to put image to window"));
	return (TRUE);
}

static int	render_minimap_elements(t_game *game, t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
			{
				if (!draw_image(game, game->minimap.wall, x, y))
					return (FALSE);
			}
			else if (map->map[y][x] == 'N' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'S' || map->map[y][x] == 'W')
			{
				if (!draw_image(game, game->minimap.player, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

static int	render_minimap_floor(t_game *game, t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] != ' ')
			{
				if (!draw_image(game, game->minimap.floor, x, y))
					return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

static void	set_z_index(mlx_image_t *img, int z)
{
	size_t	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].z = z;
		i++;
	}
}

static mlx_image_t	*load_image(mlx_t *mlx, const char *image_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	image = NULL;
	texture = mlx_load_png(image_path);
	if (!texture)
	{
		print_error("Failed to load texture");
		return (NULL);
	}
	if (texture == NULL)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		print_error("Failed to transform texture to image");
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}

int	init_minimap(t_game *game, t_map *map)
{
	game->minimap.minimap = mlx_new_image(game->mlx, 200, 200);
	if (mlx_image_to_window(game->mlx, game->minimap.minimap, 200, 200) == -1)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	game->minimap.floor = load_image(game->mlx, IMG_FLOOR);
	if (!game->minimap.floor)
		return (FALSE);
	game->minimap.wall = load_image(game->mlx, IMG_WALL);
	if (!game->minimap.wall)
		return (FALSE);
	game->minimap.player = load_image(game->mlx, IMG_PLAYER);
	if (!game->minimap.wall)
		return (FALSE);
	set_z_index(game->minimap.wall, 1);
	set_z_index(game->minimap.floor, 1);
	if (render_minimap_floor(game, map) == FALSE 
		|| render_minimap_elements(game, map) == FALSE)
	{
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}
