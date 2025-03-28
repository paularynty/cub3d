/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:08:42 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/28 10:29:54 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	validate_file(int argc, char *file)
{
	int32_t	map_file;
	size_t	path_len;

	if (argc != 2)
		return (print_error("Usage: ./cub3D [path_to_map].cub"));
	if (!file[0])
		return (print_error("Empty path"));
	path_len = ft_strlen(file);
	if (path_len < 4 || ft_strncmp(&file[path_len - 4], ".cub", 4))
		return (print_error("Invalid file format\nSupported file format: .cub"));
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
		return (print_error("Could not find map file"));
	return (map_file);
}

void	set_cursor(t_game *game)
{
	void			*cursor;
	mlx_texture_t	*cursor_texture;

	cursor_texture = mlx_load_png(IMG_CURSOR);
	cursor = mlx_create_cursor(cursor_texture);
	mlx_delete_texture(cursor_texture);
	mlx_set_cursor(game->mlx, cursor);
	game->mouse_x = game->window_width / 2;
	game->mouse_toggle = FALSE;
}

int	init(t_game *game)
{
	game->mlx = mlx_init(game->window_width, game->window_height, \
		"The Maze Runners", false);
	if (!game->mlx)
		return (print_error("Failed to initialize MLX"));
	set_cursor(game);
	render_floor_ceiling(game);
	return (TRUE);
}
