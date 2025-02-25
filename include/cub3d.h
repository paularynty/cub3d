#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h> //delete this later
# include "./MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE -1

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 50

# define SCREEN_WIDTH 3840
# define SCREEN_HEIGHT 2160

#ifdef BUFFER_SIZE
# undef BUFFER_SIZE
# define BUFFER_SIZE 2014
#endif

# define IMG_WALL "textures/minimap/wall/wall.png"
# define IMG_FLOOR "textures/minimap/wall/wall_vertical.png"

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
}	t_image;

typedef struct s_map
{
	char	**map;
	int32_t	columns;
	int32_t	rows;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_image		images;
	t_map		*map;
}	t_game;


//init/init_map.c
int32_t	validate_file(char *file);

//init/init_game.c
t_game	*init_game_data(t_game *game);
int		init_game(t_game *game);

//minimap/minimap.c
int		render_minimap(t_game *game, t_map *map);

//minimap/minimap_utils.c
void	key_hooks(mlx_key_data_t data, void *param);

//minimap/read_map.c
int		read_map(t_map *map, int32_t fd);

//utils/utils.c
int		print_error(char *msg);

#endif