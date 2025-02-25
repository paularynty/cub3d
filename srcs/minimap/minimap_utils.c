#include "cub3d.h"

// static void	validate_objects(t_map *map)
// {
// 	if (map->c_count < 1)
// 		map_error(map, "Collectible not found");
// 	if (map->p_count < 1)
// 		map_error(map, "Player not found");
// 	if (map->p_count > 1)
// 		map_error(map, "More than 1 player");
// 	if (map->e_count < 1)
// 		map_error(map, "Exit not found");
// 	if (map->e_count > 1)
// 		map_error(map, "More than 1 exit");
// 	validate_paths_to_objects(map);
// }

// static void	validate_map(t_map *map, int32_t row, int32_t col)
// {
// 	if (map->columns > MAX_COL || map->rows > MAX_ROW)
// 		map_error(map, "Exceeds the maximum size");
// 	while (++row < map->rows)
// 	{
// 		if ((int32_t)(ft_strlen(map->map[row])) != map->columns)
// 			map_error(map, "Is not rectangular");
// 		col = -1;
// 		while (++col < map->columns)
// 		{
// 			if (!ft_strchr("01CEP\n", map->map[row][col]))
// 				map_error(map, "Contains invalid characters");
// 			if ((row == 0 || row == map->rows -1 || col == 0
// 					|| col == map->columns -1) && map->map[row][col] != '1')
// 				map_error(map, "Is not surrounded by walls");
// 			count_objects(map, row, col);
// 		}
// 	}
// 	validate_objects(map);
// }

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
	printf("check: %d\n", byte);
	if (byte == -1)
		return (print_error("Failed to read map"));
	else if (byte == 0)
		return (print_error("Empty map"));
	// else if (byte > MAX_ROW * (MAX_COL + 1))
	// 	map_error(NULL, "Is too large");
	map->map = ft_split(line, '\n');
	if (!map->map)
		return (print_error("Failed to split map into 2D array"));
	map->width = ft_strlen(map->map[0]);
	map->height = count_rows(map->map);
	// if (ft_count_char(line, '\n') > map->rows - 1)
	// 	map_error(map, "Contains empty lines");
	// validate_map(map, -1, -1);
	return (TRUE);
}
