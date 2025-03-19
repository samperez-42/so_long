/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:10:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/19 15:10:32 by samperez         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;


typedef struct s_img
{
	mlx_t		*window;
	
}	t_img;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	t_player	player;
	int			lines;
	int			columns;
	int			coins;
	int			exit;
	int			exit_copy;
	
}	t_game;

void	check_map_extension(const char *map_name);
int		check_map(const char *map);
void	read_map(char **map, int fd);
void	free_map(char **map);

#endif