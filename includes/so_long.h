/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:10:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/31 16:33:06 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	mlx_texture_t	*coll;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
	mlx_texture_t	*p;
	mlx_texture_t	*tile;
	mlx_image_t		*collect_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*exit_c_i;
	mlx_image_t		*exit_o_i;
	mlx_image_t		*p_i;
	mlx_image_t		*ti_i;
}	t_img;

/*
@param map The map used to place the elements
@param map_save A copy of the map used for flood_fill
@param moves The number of moves made by the player
@param img
@param p_pos The position of the player
@param exit_pos The position of the exit
@param exit The number of exits
@param exit_c A copy of exit used for flood_fill
@param coin The number of coins
@param coin_c A copy of coin used for flood_fill
@param p_num The number of players
@param p_c A copy of player used for flood_fill
@param height The height of the mlx window
@param width The width of the mlx window
@param wind The window itself
*/
typedef struct s_game
{
	char		**map;
	char		**map_save;
	int			moves;
	t_img		img;
	t_point		p_pos;
	t_point		exit_pos;
	int			exit;
	int			exit_c;
	int			coin;
	int			coin_c;
	int			p_num;
	int			p_c;
	int			height;
	int			width;
	int			null_check;
	mlx_t		*wind;
}	t_game;

/*
@brief This function opens the file passed as an argument to later process it
@param map The map file
@return fd - The file descriptor
*/
int		open_map(const char *map);
/*
@brief This function reads the whole map file using gnl in a loop
@param map The struct
@param fd The file descriptor
*/
int		read_map(t_game *map, int fd);
/*
@brief This function ensures the map is correct.
It checks if the map is rectangular, if there are invalid characters
or if there are an incorrect number of coins, players or exits
*/
int		parse_map(t_game *map);
/*
@brief This function frees the struct used in the so_long program
@param t_game*map The struct
*/
void	free_all(t_game *map);

#endif