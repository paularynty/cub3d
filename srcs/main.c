#include "cub3d.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	(void)argc;
	while (argv[i])
		print_error(argv[i++]);
	return (0);
}