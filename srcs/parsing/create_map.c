/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:02:45 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/02/25 15:31:13 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_map *map, int32_t map_file)
{
	char	*line;
	char	*value;
	size_t	line_i;

	if (map == NULL || map_file == -1)
		return (-1);
	line = get_next_line(map_file);
	if (line == NULL)
		return (-1);
	while (line != NULL)
	{
		line_i = 0;
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		while (is_whitespace(line[line_i]) == 1)
			line_i++;
		if (ft_strncmp(&line[line_i], "NO", 2) == 0 || \
			ft_strncmp(&line[line_i], "SO", 2) == 0 || \
			ft_strncmp(&line[line_i], "WE", 2) == 0 || \
			ft_strncmp(&line[line_i], "EA", 2) == 0)
			add_texture(&line[line_i], map);
		else if (ft_strncmp(&line[line_i], "F", 1) == 0 || \
			ft_strncmp(&line[line_i], "C", 1) == 0)
			add_color(&line[line_i], map);
	}
}
