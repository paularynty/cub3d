#include "cub3d.h"

int	validate_file(char *file)
{
	int	map_fd;
	int	path_len;

	if (!file[0])
		return (print_error("Empty path"));
	map_fd = open(file, O_RDONLY);
	if (map_fd < 0)
		return (print_error("Map file does not exist"));
	path_len = ft_strlen(file);
	if (path_len < 4 || ft_strncmp(&file[path_len - 4], ".cub", 4))
		return (print_error("Usage: ./cub3D [path_to_map].cub"));
	return (map_fd);
}
