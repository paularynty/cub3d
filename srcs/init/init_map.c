#include "cub3d.h"

int	validate_file(char *file)
{
	int	map_path_len;
	int	map_file;

	if (!file[0])
	{
		print_error("Empty path");
		return (FALSE);
	}
	map_file = open(file, O_RDONLY);
	if (map_file < 0)
	{
		print_error("Failed to open map, verify that map file exists");
		return (FALSE);
	}
	map_path_len = ft_strlen(file);
	if (map_path_len < 4 || ft_strncmp(&file[map_path_len - 4], ".ber", 4))
	{
		print_error("Invalid map path, use format ./so_long [map].ber");
		return (FALSE);
	}
	return (map_file);
}
