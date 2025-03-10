/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:27:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/10 12:21:42 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define MOVESPEED 0.01
# define ROTSPEED 0.01

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 32

#ifdef BUFFER_SIZE
# undef BUFFER_SIZE
# define BUFFER_SIZE 2014
#endif

# define IMG_WALL "textures/minimap/wall.png"
# define IMG_FLOOR "textures/minimap/floor.png"
# define IMG_PLAYER "textures/minimap/player.png"
# define IMG_CURSOR "textures/cursor.png"

typedef struct s_assets
{
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	mlx_image_t	*world;
}	t_assets;

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
 * A struct to store the texture images.
 * 
 * @param north Holds the north texture.
 * @param south Holds the south texture.
 * @param east Holds the east texture.
 * @param west Holds the west textrure.
*/
typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}	t_textures;

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
 * @param dir_x The horizontal direction where the player is looking in the map.
 * @param dir_y The vertical direction where the player is looking in the map.
 * @param plane_x The horizontal plane to determine the FOV.
 * @param plane_y The vertical plane to determine the FOV.
 */
typedef struct s_player
{
	int32_t		pos_x;
	int32_t		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

/**
 * A structure to hold the information of the map.
 * 
 * @param map An array that holds the map.
 * @param floor Holds the color of the floor.
 * @param ceiling Holds the color of the ceiling.
 * @param textures Holds the textures that will be converted to images.
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
	t_textures		textures;
	mlx_image_t		*north;
	mlx_image_t		*south;
	mlx_image_t		*east;
	mlx_image_t		*west;
	size_t			width;
	size_t			height;

}	t_map;


/**
 * A structure for ray calculations and to hold the length of the ray.
 * 
 * @param dir_x The horizontal direction of the ray.
 * @param dir_y The vertical direction of the ray.
 * @param delta_dist_x The horizontal distance the ray travels from one
 * horizontal coordinate to the next.
 * @param delta_dist_y The vertical distance the ray travels from one
 * vertical coordinate to the next.
 * @param side_dist_x The horizontal distance from the players position
 * to the next horizontal coordinate.
 * @param side_dist_y The vertical distance from the players position
 * to the next vertical coordinate.
 * @param camera_x The horizontal coordinate in camera space.
 * @param plane_x The horizontal plane in camera space.
 * @param plane_y The vertical plane in camera space.
 * @param step_x Holds the value to horizontally increment the ray length
 * in the map.
 * @param step_y Holds the value to vertically increment the ray length
 * in the map.
 * @param map_x The horizontal index for the map.
 * @param map_y The vertical index for the map.
 * @param side A flag to see if the ray hit a horizontal or a vertical
 * side of a wall.
 * @param line_height The height of the line to be drawn.
 * @param draw_start The pixel coordinate from where to start drawing.
 * @param draw_end The pixel coordinate where to stop drawing.
 */
typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	camera_x;
	double	plane_x;
	double	plane_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;


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
	t_assets	assets;
	t_minimap	minimap;
	t_map		map;
	t_player	player;
	t_ray		ray;
	uint32_t	window_w;
	uint32_t	window_h;
}	t_game;

/******************************************************************************/
/*                                                                            */
/*                                   INIT.C                                   */
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

/******************************************************************************/
/*                                                                            */
/*                             INIT_PLAYER_DATA.C                             */
/*                                                                            */
/******************************************************************************/

/**
 * Initializes the player structure with the starting position of the player.
 * 
 * @param[out] player A pointer to the player structure.
 * @param[in] x The horizontal coordinate of the player.
 * @param[in] y The vertical coordinate of the player.
 * @param[in] dir The direction where the player is looking at.
 * 
 * @returns 1 if the initialization was successful, -1 in case of an error.
 */
int		init_player(t_player *player, size_t x, size_t y, char dir);

/******************************************************************************/
/*                                                                            */
/*                                 INIT_GAME.C                                */
/*                                                                            */
/******************************************************************************/

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
int		init_minimap(t_game *game, t_map *map);

/**
 * Handles player movement in the minimap.
 * Params to be added.
*/
void	move_player_minimap(t_game *game, size_t x, size_t y);


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
int		read_map(t_map *map, char *line, int32_t fd, char *filename);

/******************************************************************************/
/*                                                                            */
/*                                 RENDER.C                                   */
/*                                                                            */
/******************************************************************************/

//initializes floor and ceiling images in 3D
//fills images with indicated color (saved from map parsing) with mlx_put_pixel
//puts images to window, first half will be ceiling, second half floor
int		render_game(t_game *game);


/******************************************************************************/
/*                                                                            */
/*                                   PARSING                                  */
/*                                                                            */
/******************************************************************************/

/**
 * Validates the map to ensure that everything was correctly formatted.
 * 
 * @param[out] game The game structure containing the map and 
 * the player structures.
 * 
 * @returns 1 if everything was correct, -1 in case of an error.
 */
int		final_validation(t_game *game);

/**
 * Iterates through the map and assigns the width of the map to `map->width`.
 * 
 * @param[out] map A pointer to the map structure.
 * 
 * @returns 1 if the function `fill_map` succeeds, -1 in case of an error.
 */
int		get_map_width(t_map *map);

/**
 * Converts the map to a rectangle by adding spaces around the outer part
 * of the map.
 * 
 * @param[out] map A pointer to the map structure that holds the map.
 * 
 * @returns 1 if the conversion was successful, -1 in case of an error.
 */
int		fill_map(t_map *map);

/**
 * Validates that the middle part of the map is surrounded by walls
 * 
 * @param[in] line The line from the map file.
 * 
 * @returns 1 if the line is correct, -1 in case of an error.
 */
int		validate_space(char *line);

/**
 * Checks that the line has only walls.
 * 
 * @param[in] line The line from the map file.
 * 
 * @returns 1 if the line has only walls, -1 in case of an error.
 */
int		check_walls(char *line);

/**
 * Validates the characters in the map.
 * 
 * @param[in] line The line from the map file.
 * 
 * @returns The length of the line.
 */
size_t	validate_map_line(char *line);

/**
 * Parses the map file and stores the map values needed for the game.
 * 
 * @param[out] map The `t_map` structure pointer to store the values in.
 * @param[in] map_file The map file descriptor.
 * @param[in] filename The path to the map file.
 * 
 * @returns -1 in case of an error, 1 in case of success. 
 */
int		create_map(t_game *game, int32_t map_file, char *filename);

/**
 * Frees the static buffer in `get_next_line()`.
 * 
 * @param[out] line The allocated line.
 * @param[in] fd The file descriptor to read from.
 * 
 * @returns -1 To indicate that there has been an error in the program. 
*/
int		free_gnl(char **line, int fd);

/**
 * Frees a NULL terminated array of character strings.
 * 
 * @param[out] arr The array to free.
*/
void	split_free(char **arr);

/**
 * Converts RGBA to int value.
 * 
 * @param[in] r The value od red color.
 * @param[in] g The value of green color.
 * @param[in] b The value of blue color.
 * @param[in] a The value of transparency.
 * 
 * @returns The int value of the RGBA color.
*/
int32_t	rgba(int32_t r, int32_t g, int32_t b, int32_t a);

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
/*                                 RAYCASTER                                  */
/*                                                                            */
/******************************************************************************/

/**
 * Initializes the variables found in the `t_ray` structure.
 * 
 * @param[in] x The horizontal coordinate on the window.
 * @param[out] ray A pointer to the `t_ray` structure.
 * @param[in] player A pointer to the `t_player` structure containing the player
 * location and direction info.
 * @param[in] mlx A pointer to the `mlx_t` structure containing the info about
 * the window.
 */
void	init_ray_info(int x, t_ray *ray, t_player *player, mlx_t *mlx);

/**
 * Initializes the `side_dist_x` and `side_dist_y` 
 * and also the `step_x` and `step_y` variables found in structure `t_ray`.
 * 
 * @param[out] ray A pointer to the `t_ray` structure.
 * @param[in] player A pointer to the `t_player` structure.
 */
void	init_side_step(t_ray *ray, t_player *player);

/**
 * Casts a ray using the DDA algorithm until it hits a wall.
 * 
 * @param[out] ray A pointer to the `t_ray` structure.that holds the
 * information about the ray to be casted.
 * @param[in] game A pointer to the `t_game` the map.
 */
void	cast_ray(t_ray *ray, t_game *game);

/**
 * Initializes the variables needed for the wall drawing.
 * 
 * @param[out] ray A pointer to the `t_ray` structure.
 * @param[in] game A pointer to the `t_game` structure.
 */
void	init_draw(t_ray *ray, t_game *game);

/**
 * Draws the 3D world of the map to the window.
 * DELETE LATER WHEN TEXTURES ARE WORKING!!
 */
void	test_draw(int x, t_game *game, mlx_image_t *image);

/**
 * Calls all the necessary functions to cast rays through the map and draw the FOV.
 * 
 * @param[out] game A pointer to the game structure, that holds the `t_ray`
 * variable.
 */
void	render_world(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                                   UTILS.C                                  */
/*                                                                            */
/******************************************************************************/

/**
 * Frees the allocated memory in the map structure.
 * 
 * @param[out] map the map structure.
 */
void	free_map(t_map *map);
int		print_error(char *msg);
// void	game_hook(void *param);
void	key_hooks(mlx_key_data_t data, void *param);

/**
 * Cleans up resources.
 * @param[in] *game Game data struct.
*/
void	cleanup(t_game *game);

#endif