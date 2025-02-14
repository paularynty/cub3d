#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

# define TRUE 1
# define FALSE -1

# define RED "\033[1;91m"
# define RESET "\033[0;39m"

//init/init_map.c
int	validate_file(char *file);

//utils/utils.c
int	print_error(char *msg);

#endif