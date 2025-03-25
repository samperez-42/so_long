/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:10:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/25 12:59:02 by samperez         ###   ########.fr       */
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

int		open_map(const char *map);
void	read_map(t_game *map, int fd);
int		parse_map(t_game *map);
int		is_map_rectangular(char **map);
void	free_all(t_game *map);

#endif