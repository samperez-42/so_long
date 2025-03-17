/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:10:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 16:11:42 by samperez         ###   ########.fr       */
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
# ifndef HEIGHT
#  define HEIGHT 600
# endif
# ifndef WIDTH
#  define WIDTH 1400
# endif

typedef struct mlxx
{
	void		*window;
	void		*context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	t_mlx;

void	check_map_extension(const char *map_name);

#endif