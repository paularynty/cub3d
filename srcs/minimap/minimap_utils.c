#include "cub3d.h"

static size_t	count_rows(char **map)
{
	size_t	y;

	y = 0;
	if (!map)
		return (FALSE);
	while (map[y])
		y++;
	return (y);
}

int	read_map(t_map *map, int32_t map_file)
{
	int32_t	byte;
	char	line[BUFFER_SIZE];

	ft_bzero(line, BUFFER_SIZE);
	byte = read(map_file, line, BUFFER_SIZE);
	close(map_file);
	if (byte == -1)
		return (print_error("Failed to read map"));
	else if (byte == 0)
		return (print_error("Empty map"));
	map->map = ft_split(line, '\n');
	if (!map->map)
		return (print_error("Failed to split map into 2D array"));
	map->width = ft_strlen(map->map[0]);
	map->height = count_rows(map->map);
	return (TRUE);
}
