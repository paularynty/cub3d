/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmat- <mrahmat-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:27:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/04/10 17:25:39 by mrahmat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
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

# define IMG_CURSOR "assets/cursor_target.png"

/******************************************************************************/
/*                                                                            */
/*                            init/init_game_data.c                           */
/*                                                                            */
/******************************************************************************/

/**
 * Allocates memory for the game structure and initializes game data.
 * 
 * @param[out] game A pointer to the game structure to be initialized.
 * 
 * @returns Pointer to the initialized game structure, or NULL in case of error.
 */
t_game	*init_game_data(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                          init/init_player_data.c                           */
/*                                                                            */
/******************************************************************************/

/**
 * Initializes the player structure with the starting position of the player.
 * 
 * @param[out] player Pointer to the player structure.
 * @param[in] x The horizontal coordinate of the player.
 * @param[in] y The vertical coordinate of the player.
 * @param[in] dir The direction where the player is looking at.
 * 
 * @returns 1 upon successful initialization, -1 in case of error.
 */
int		init_player(t_player *player, size_t x, size_t y, char dir);

/******************************************************************************/
/*                                                                            */
/*                                init/init.c                                 */
/*                                                                            */
/******************************************************************************/

/**
 * Checks that the file given to the program as an argument is a valid and 
 * existing file with the .cub file extension.
 * 
 * @param[in] game Pointer to the game struct.
 * @param[in] file Pointer to the file path.
 * @returns file descriptor of the file.
*/
int		validate_file(t_game *game, char *file);

/**
 * Loads and sets a custom cursor for the game.
 * 
 * @param[out] game Pointer to the game structure.
 */
void	set_cursor(t_game *game);

/**
 * Initializes the game engine and sets up initial game elements.
 * 
 * @param[out] game Pointer to the game structure.
 * 
 * @returns 1 upon successful initialization, -1 in case of an error.
 */
int		init(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                            parsing/create_map.c                            */
/*                                                                            */
/******************************************************************************/

/**
 * Parses the map file and stores the map values needed for the game.
 * 
 * @param[out] map The `t_map` structure pointer to store the values in.
 * @param[in] map_file The map file descriptor.
 * @param[in] filename The path to the map file.
 * 
 * @returns 1 upon success, -1 upon error. 
 */
int		create_map(t_game *game, char *filename);

/******************************************************************************/
/*                                                                            */
/*                         parsing/map_validation.c                           */
/*                                                                            */
/******************************************************************************/

/**
 * Validates the characters in the map.
 * 
 * @param[in] line Line from the map file.
 * 
 * @returns Length of the line.
 */
size_t	validate_map_line(char *line);

/**
 * Validates that the middle part of the map is surrounded by walls
 * 
 * @param[in] line Line from the map file.
 * 
 * @returns 1 if the line is correct, -1 in case of an error.
 */
int		validate_space(char *line);

/**
 * Checks that the line has only walls.
 * 
 * @param[in] line Line from the map file.
 * 
 * @returns 1 if the line has only walls, -1 in case of an error.
 */
int		check_walls(char *line);

/**
 * Validates the map to ensure that everything was correctly formatted.
 * 
 * @param[out] game The game structure containing the map and 
 * the player structures.
 * 
 * @returns 1 if everything was correct, -1 in case of an error.
 */
int		final_validation(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                          parsing/parsing_utils.c                           */
/*                                                                            */
/******************************************************************************/

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
 * Prints `err_msg` to STDERR if `err` flag is true.
 * 
 * @param[out] arr The array to free.
 * @param[in] err An error flag.
 * @param[in] err_msg Error message to print.
 * 
 * @returns -1
*/
int		split_free(char **arr, int err, char* err_msg);

/**
 * Checks if the character given as Parameter is a whitespace character.
 * 
 * @param[in] c The character to check.
 * 
 * @returns 1 if the character is a whitespace character, -1 if the character
 * is not.
 */
int		is_whitespace(int c);

/**
 * Copies the original map content in the given array
 * 
 * @param[in] map The `t_map` structure containing the original map data.
 * @param[out] new_map The array to copy the original content to.
 * @param[in] y The index of the map array to copy from/to.
 * 
 * @returns -1 in case of an error, 1 in case of success.
 */
int		copy_map_content(t_map *map, char **new_map, size_t y);

/**
 * Iterates through the map and assigns the width of the map to `map->width`.
 * 
 * @param[out] map Pointer to the map structure.
 * 
 * @returns 1 if `fill_map()` succeeds, -1 in case of an error.
 */
int		get_map_width(t_map *map);

/**
 * Checks the string containing RGB values.
 * 
 * @param[in] str The string to check.
 * 
 * @returns 1 if the string is valid, -1 if not.
 */
int		is_valid_color(char *str);

/******************************************************************************/
/*                                                                            */
/*                             parsing/fill_map.c                             */
/*                                                                            */
/******************************************************************************/

/**
 * Converts the map to a rectangle by adding spaces around the outer part
 * of the map.
 * 
 * @param[out] map Pointer to the map structure that holds the map.
 * 
 * @returns 1 if the conversion was successful, -1 in case of an error.
 */
int		fill_map(t_map *map);

/**
 * Reads a map from a file and stores it in the map structure.
 * 
 * @param[out] map Pointer to the map structure where the map will be stored.
 * @param[in] line Pointer to a line buffer used for reading the map.
 * @param[in] map_file The file descriptor of the map file.
 * @param[in] filename The name of the file being read.
 * 
 * @returns 1 if the map was successfully read, -1 in case of an error.
 */
int		read_map(t_map *map, char *line, int32_t fd, char *filename);

/******************************************************************************/
/*                                                                            */
/*                            raycaster/init_ray.c                            */
/*                                                                            */
/******************************************************************************/

/**
 * Initializes the `side_dist_x` and `side_dist_y` 
 * and also the `step_x` and `step_y` variables found in structure `t_ray`.
 * 
 * @param[out] ray Pointer to the `t_ray` structure.
 * @param[in] player Pointer to the `t_player` structure.
 */
void	init_side_step(t_ray *ray, t_player *player);

/**
 * Initializes the variables found in the `t_ray` structure.
 * 
 * @param[in] x The horizontal coordinate on the window.
 * @param[out] ray Pointer to the `t_ray` structure.
 * @param[in] player Pointer to the `t_player` structure containing the player
 * location and direction info.
 * @param[in] mlx Pointer to the `mlx_t` structure containing the info about
 * the window.
 */
void	init_ray(int x, t_ray *ray, t_player *player, t_game *game);

/******************************************************************************/
/*                                                                            */
/*                            raycaster/raycaster.c                           */
/*                                                                            */
/******************************************************************************/

/**
 * Casts a ray using the DDA algorithm until it hits a wall.
 * 
 * @param[out] ray Pointer to the `t_ray` structure.that holds the
 * information about the ray to be casted.
 * @param[in] game Pointer to the `t_game` the map.
 */
void	cast_ray(t_ray *ray, t_game *game);

/**
 * Initializes the variables needed for the wall drawing.
 * 
 * @param[out] ray Pointer to the `t_ray` structure.
 * @param[in] game Pointer to the `t_game` structure.
 */
void	init_draw(t_ray *ray, t_game *game);

/******************************************************************************/
/*                                                                            */
/*                            render/movement.c                               */
/*                                                                            */
/******************************************************************************/

/**
 * Moves the player to a new position if it is not a wall.
 * 
 * @param[out] game Pointer to the game structure.
 * @param[in] x The new x-coordinate of the player.
 * @param[in] y The new y-coordinate of the player.
 */
void	move_player(t_game *game, double x, double y);

/**
 * Rotates the player's direction.
 * 
 * @param[out] game Pointer to the game structure.
 * @param[in] right Boolean indicating direction of rotation \
 * 					(true for right, false for left).
 * @param[in] delta_time Time difference since the last frame \
 * 					to ensure smooth rotation.
 */
void	rotate_player(t_game *game, bool right, double delta_time);

/******************************************************************************/
/*                                                                            */
/*                             render/render.c                                */
/*                                                                            */
/******************************************************************************/

/**
 * Calls necessary functions to cast rays through the map and draw the FOV.
 * 
 * @param[out] game Pointer to the game structure holding the `t_ray` ray
 * data.
 */
void	render_world(t_game *game);

/**
 * Renders textured walls to the screen by mapping texture pixels onto the wall.
 * 
 * @param[in] x The x-coordinate for rendering the wall.
 * @param[in] game Pointer to the game structure.
 * @param[out] image Pointer to the image where the walls will be drawn.
 * @param[in] texture Pointer to the texture to be applied to the walls.
 */
void	render_walls(int x, t_game *game, mlx_image_t *image, \
				mlx_texture_t *texture);

/******************************************************************************/
/*                                                                            */
/*                          render/render_utils.c                             */
/*                                                                            */
/******************************************************************************/

/**
 * Fills an image with a specified color.
 * 
 * @param[out] image Pointer to the image to be filled.
 * @param[in] color The color to fill the image with.
 */
// void	fill_color(mlx_image_t *image, int color);
void	fill_color(mlx_image_t *image, int color, uint32_t width, \
	uint32_t height);

/**
 * Extracts pixel color data from a texture at the given coordinates.
 * 
 * @param[in] texture Pointer to the texture to extract data from.
 * @param[out] color Pointer to the color structure to store the pixel data.
 * @param[in] coords The position in the texture's pixel array.
 */
void	get_pixel_data(mlx_texture_t *texture, t_color *color, size_t coords);

/******************************************************************************/
/*                                                                            */
/*                              utils/cleanup.c                               */
/*                                                                            */
/******************************************************************************/

/**
 * Prints error to the standard error in the terminal. Function returns -1
 * by default, indicating failure at the function call site.
 * 
 * @param[in] msg Pointer to the character array containing the error message.
 * @returns -1, indicating an error.
 */
int		print_error(char *msg);

/**
 * Frees the allocated memory in the map structure.
 * 
 * @param[out] map the map structure.
 */
void	free_map(t_map *map);

/**
 * Cleans up resources.
 * @param[in] *game Game data struct.
*/
void	cleanup(t_game *game);

/******************************************************************************/
/*                                                                            */
/*                              utils/hooks.c                                 */
/*                                                                            */
/******************************************************************************/

/**
 * Handles the game loop, updating the game state and rendering the world.
 * 
 * @param[in] param Pointer to the game structure.
 */
void	game_hook(void *param);

/**
 * A function to handle window resizing.
 * 
 * @param[in] width The new width of the window.
 * @param[in] height The new height of the window.
 * @param[in] param An extrParameter to the function. Will contain
 * Pointer to the `t_game` structure.
 */
void	resize_window(int32_t width, int32_t height, void *param);

/******************************************************************************/
/*                                                                            */
/*                              utils/utils.c                                 */
/*                                                                            */
/******************************************************************************/

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
 * Calculates time difference between current and previous frame.
 * 
 * @returns The delta time in seconds.
 */
double	get_delta_time(void);

#endif