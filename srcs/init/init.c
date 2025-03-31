/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:08:42 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/31 20:54:11 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_file(t_game *game, char *file)
{
	size_t	path_len;

	if (!file[0])
		return (print_error("Empty path"));
	path_len = ft_strlen(file);
	if (path_len < 4 || ft_strncmp(&file[path_len - 4], ".cub", 4))
		return (print_error("Supported file format: .cub"));
	game->map.map_fd = open(file, O_RDONLY);
	if (game->map.map_fd < 0)
		return (print_error("Map file does not exist"));
	return (TRUE);
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
		"The Maze Runners", true);
	if (!game->mlx)
		return (print_error("Failed to initialize MLX"));
	set_cursor(game);
	if (init_frog_frames(game) == FALSE)
		return (FALSE);
	return (TRUE);
}
