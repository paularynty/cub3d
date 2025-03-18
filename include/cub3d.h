/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:27:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/18 14:44:01 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h> //delete this later
# include <stdbool.h>
# include <math.h>
# include <MLX42.h>
# include "structs.h"

# define TRUE 1
# define FALSE -1

# define VERTICAL 0
# define HORIZONTAL 1

# define MOVE_SPEED 0.04f
# define ROTATION_SPEED 1.0f
# define ANIMATION_SPEED 0.1f

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 32

# define IMG_WALL "assets/minimap/wall.png"
# define IMG_FLOOR "assets/minimap/floor.png"
# define IMG_PLAYER "assets/minimap/player.png"
# define IMG_CURSOR "assets/cursor_target.png"
# define IMG_FROG_1 "assets/frog/frog_1.png"
# define IMG_FROG_2 "assets/frog/frog_2.png"
# define IMG_FROG_3 "assets/frog/frog_3.png"
# define IMG_FROG_4 "assets/frog/frog_4.png"

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
void	move_player_minimap(t_game *game, double x, double y);
void	rotate_player(t_game *game, bool right, double delta_time);

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
int		render_floor_ceiling(t_game *game);

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
 * Checks if the character given as a parameter is a whitespace character.
 * 
 * @param[in] c The character to check.
 * 
 * @returns 1 if the character is a whitespace character, -1 if the character
 * is not.
 */
int		is_whitespace(int c);

int	draw_image(t_game *game, mlx_image_t *image, uint32_t x, uint32_t y);
mlx_image_t	*load_image(mlx_t *mlx, const char *image_path);

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
void	init_ray(int x, t_ray *ray, t_player *player, t_game *game);

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

void		fill_color(mlx_image_t *image, int color);
void		get_pixel_data(mlx_texture_t *texture, \
		t_color *color, size_t coords);
uint32_t		get_x_coord(t_game *game, mlx_texture_t *texture);

/**
 * Determines which texture should be drawn based on the cardinal direction
 * (north/south/east/west).
 */
mlx_texture_t	*determine_texture(t_game *game, mlx_texture_t *texture);

/**
 * Draws the walls of the 3D world in the window.
 */
void	render_walls(int x, t_game *game, mlx_image_t *image, \
	mlx_texture_t *texture);

/**
 * Calls necessary functions to cast rays through the map and draw the FOV.
 * 
 * @param[out] game Pointer to the game structure holding the `t_ray` ray
 * data.
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
void	game_hook(void *param);

/**
 * A function to handle window resizing.
 * 
 * @param[in] width The new width of the window.
 * @param[in] height The new height of the window.
 * @param[in] param An extra parameter to the function. Will contain
 * a pointer to the `t_game` structure.
 */
void	resize_window(int32_t width, int32_t height, void *param);

/**
 * Cleans up resources.
 * @param[in] *game Game data struct.
*/
void	cleanup(t_game *game);

/**
 * A mouse hook used for rotating the player with mouse movement.
 * 
 * @param[in] game A pointer to the `t_game`structure.
*/
// void	mouse_hook(t_game *game);

double	get_delta_time(void);

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

void	set_z_index(mlx_image_t *img, int z);

//init_frog.c
void	display_frog(t_game *game);
void	animate_frog(t_game *game);
int		init_frog_frames(t_game *game);

void	set_cursor(t_game *game);

#endif