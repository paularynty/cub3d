/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:27:57 by mrahmat-          #+#    #+#             */
/*   Updated: 2025/03/12 12:52:17 by prynty           ###   ########.fr       */
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

# define MOVE_SPEED 0.2f
# define ROTATION_SPEED 0.04f

# define RED "\033[1;91m"
# define RESET "\033[0;39m"
# define TILESIZE 32

# define IMG_WALL "textures/minimap/wall.png"
# define IMG_FLOOR "textures/minimap/floor.png"
# define IMG_PLAYER "textures/minimap/player.png"
# define IMG_CURSOR "textures/cursor.png"

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
// void 	move_player(t_game *game, bool forward);
// void 	move_player(t_game *game, bool forward, double new_x, double new_y);
void 	rotate_player(t_game *game, bool right);


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
 * Determines which texture should be drawn based on the cardinal direction
 * (north/south/east/west).
 */
mlx_texture_t	*determine_texture(t_game *game, mlx_texture_t *texture);

/**
 * Draws the walls of the 3D world in the window.
 */
void	render_walls(int x, t_game *game, mlx_image_t *image, mlx_texture_t *texture);

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
void	key_hooks(mlx_key_data_t data, void *param);
// void	key_hooks(t_game *game);
// void	game_hook(void *param);

/**
 * Cleans up resources.
 * @param[in] *game Game data struct.
*/
void	cleanup(t_game *game);

#endif