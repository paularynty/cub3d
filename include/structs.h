/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:47:32 by prynty            #+#    #+#             */
/*   Updated: 2025/03/17 15:21:33 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_assets
{
	mlx_image_t		*ceiling;
	mlx_image_t		*floor;
	mlx_image_t		*world;
	mlx_texture_t	*frog_texture[4];
	mlx_image_t		*frog_image[4];
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
 * @param angle The player angle based on their cardinal direction (NSEW).
 * @param pos_x The horizontal position of the player in the map.
 * @param pos_y The vertical position of the player in the map.
 * @param dir_x The horizontal direction where the player is looking in the map.
 * @param dir_y The vertical direction where the player is looking in the map.
 * @param plane_x The horizontal plane to determine the FOV.
 * @param plane_y The vertical plane to determine the FOV.
 */
typedef struct s_player
{
	double		angle;
	double		pos_x;
	double		pos_y;
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
 * @param width Holds the width of the map.
 * @param height Holds the height of the map.
 */
typedef struct s_map
{
	char			**map;
	t_color			floor;
	t_color			ceiling;
	t_textures		textures;
	size_t			width;
	size_t			height;
}	t_map;

/**
 * Structure for ray calculations and to hold the length of the ray.
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
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			hit;
	double		wall_dist;
	double		wall_hit_x;
	uint32_t	texture_x;
	uint32_t	texture_y;
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
	uint32_t	window_width;
	uint32_t	window_height;
	double		mouse_x;
	int			mouse_toggle;
	double		delta_time;
	uint32_t	frog_x;
	uint32_t	frog_y;
	size_t		frames;
}	t_game;

#endif