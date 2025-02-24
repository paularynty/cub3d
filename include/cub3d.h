#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h> //delete this later
# include "./MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 50

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160

# define IMG_TEST "textures/wall.png"

typedef struct s_image
{
	mlx_image_t	*test;
}	t_image;


typedef struct s_game
{
	mlx_t		*mlx;
	t_image		images;
	size_t		map_width;
	size_t		map_height;
}	t_game;


//init/init_map.c
int		validate_file(char *file);

//init/init_game.c
t_game	*init_game_data(t_game *game);
int		init_game(t_game *game);

//minimap/minimap.c
void	key_hooks(mlx_key_data_t data, void *param);

//utils/utils.c
int		print_error(char *msg);

#endif