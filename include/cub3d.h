#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h> //delete this later
# include <math.h>
# include "MLX42.h"

# define TRUE 1
# define FALSE -1

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 50

#ifdef BUFFER_SIZE
# undef BUFFER_SIZE
# define BUFFER_SIZE 2014
#endif

# define IMG_WALL "textures/minimap/wall.png"
# define IMG_FLOOR "textures/minimap/floor.png"
# define IMG_PLAYER "textures/minimap/player.png"
# define IMG_CURSOR "textures/cursor.png"

/**
 * A struct to store RGB color values.
 * 
 * @param r Holds the value of the red color.
 * @param g Holds the value of the green color.
 * @param b Holds the value of the blue color.
 * @param a Holds the value of the color transparency (alpha).
 * @param color Holds the converted color.
 */
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
	int32_t	color;
}	t_color;

/**
 * An enum for the directions.
 * 
 * @param NORTH has a value of `0`.
 * @param EAST has a value of `1`.
 * @param SOUTH has a value of `2`.
 * @param WEST has a value of `3`.
 */
enum	e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
};


typedef struct s_minimap
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*minimap;
	int			minimap_size;
	int			view_width;
	int			view_height;
	int			x0;
	int			y0;
}	t_minimap;

/**
 * A struct for the player information.
 * 
 * @param pos_x The horizontal position of the player in the map.
 * @param pos_y The vertical position of the player in the map.
 * @param dir The direction where the player is looking in the map.
 */
typedef struct s_player
{
	int32_t		pos_x;
	int32_t		pos_y;
	double		dir;
}	t_player;

/**
 * A structure to hold the information of the map.
 * 
 * @param map An array that holds the map.
 * @param floor Holds the color of the floor.
 * @param ceiling Holds the color of the ceiling.
 * @param north Holds the image used for the north part of the map.
 * @param south Holds the image used for the south part of the map.
 * @param east Holds the image used for the east part of the map.
 * @param west Holds the image used for the west part of the map.
 * @param width Holds the width of the map.
 * @param height Holds the height of the map.
 */
typedef struct s_map
{
	char			**map;
	t_color			floor;
	t_color			ceiling;
	mlx_image_t		*north;
	mlx_image_t		*south;
	mlx_image_t		*east;
	mlx_image_t		*west;
	int32_t			width;
	int32_t			height;
}	t_map;

/**
 * The main structure that holds everything needed for the game.
 * 
 * @param mlx A pointer to the MLX structure.
 * @param minimap A variable for the minimap feature.
 * @param map A variable that holds the map information.
 * @param player A variable that holds the player information.
 */
typedef struct s_game
{
	mlx_t		*mlx;
	t_minimap	minimap;
	t_map		map;
	t_player	player;
	uint32_t	window_w;
	uint32_t	window_h;
}	t_game;

/******************************************************************************/
/*                                                                            */
/*                                 INIT.C                                */
/*                                                                            */
/******************************************************************************/

/**
 * Checks that the file given to the program as an argument is a valid and 
 * existing file with the .cub file extension.
 * 
 * @param[in] file A pointer to the file path.
 * @returns file descriptor of the file.
*/
int32_t	validate_file(int argc, char *file);

t_game	*init_game_data(t_game *game);
int		init(t_game *game, t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                  MINIMAP.C                                 */
/*                                                                            */
/******************************************************************************/

/**
 * Initializes minimap data and draws the minimap on the game screen.
 * Params to be added.
*/
void	minimap(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                                MINIMAP_UTILS.C                             */
/*                                                                            */
/******************************************************************************/



/******************************************************************************/
/*                                                                            */
/*                                 READ_MAP.C                                 */
/*                                                                            */
/******************************************************************************/
int		read_map(t_map *map, int32_t fd);

/******************************************************************************/
/*                                                                            */
/*                                   PARSING                                  */
/*                                                                            */
/******************************************************************************/

/**
 * Checks if the character given as a parameter is a whitespace character.
 * 
 * @param[in] c The character to check.
 * 
 * @returns 1 if the character is a whitespace character, -1 if the character
 * is not.
 */
int		is_whitespace(int c);

/******************************************************************************/
/*                                                                            */
/*                                   UTILS.C                                  */
/*                                                                            */
/******************************************************************************/
int		print_error(char *msg);
// void	game_hook(void *param);
void	key_hooks(mlx_key_data_t data, void *param);

/**
 * Cleans up resources.
 * @param[in] *game Game data struct.
*/
void	cleanup(t_game *game);

#endif