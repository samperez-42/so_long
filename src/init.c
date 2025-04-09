/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/04/09 16:36:32 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_textures(t_game *map)
{
	map->img.coll = mlx_load_png("./textures/baguette.png");
	map->img.wall = mlx_load_png("./textures/muro.png");
	map->img.p = mlx_load_png("./textures/pearto.png");
	map->img.exit_c = mlx_load_png("./textures/puerta_cerrada.png");
	map->img.exit_o = mlx_load_png("./textures/puerta_abierta.png");
	map->img.tile = mlx_load_png("./textures/suelo.png");
	if (check_textures_exist(map) == EXIT_SUCCESS)
	{
		map->img.collect_i = mlx_texture_to_image(map->wind, map->img.coll);
		map->img.wall_i = mlx_texture_to_image(map->wind, map->img.wall);
		map->img.p_i = mlx_texture_to_image(map->wind, map->img.p);
		map->img.exit_c_i = mlx_texture_to_image(map->wind, map->img.exit_c);
		map->img.exit_o_i = mlx_texture_to_image(map->wind, map->img.exit_o);
		map->img.ti_i = mlx_texture_to_image(map->wind, map->img.tile);
		free_textures(map);
		return (EXIT_SUCCESS);
	}
	free_textures(map);
	return (EXIT_FAILURE);
}

void	draw_map(t_game *map, int lines, int columns)
{
	if (map->map[lines][columns] == '1')
		mlx_image_to_window(map->wind, map->img.wall_i, columns * PXL, lines * PXL);
	else if (map->map[lines][columns] == '0')
		mlx_image_to_window(map->wind, map->img.ti_i, columns * PXL, lines * PXL);
	else if (map->map[lines][columns] == 'P')
	{
		mlx_image_to_window(map->wind, map->img.ti_i, columns * PXL, lines * PXL);
		mlx_image_to_window(map->wind, map->img.p_i, columns * PXL, lines * PXL);
	}
	else if (map->map[lines][columns] == 'C')
	{
		mlx_image_to_window(map->wind, map->img.ti_i, columns * PXL, lines * PXL);
		mlx_image_to_window(map->wind, map->img.collect_i, columns * PXL, lines * PXL);
	}
	else if (map->map[lines][columns] == 'E')
	{
		mlx_image_to_window(map->wind, map->img.ti_i, columns * PXL, lines * PXL);
		mlx_image_to_window(map->wind, map->img.exit_c_i, columns * PXL, lines * PXL);	
	}
	if (map->map[lines][columns + 1])
		draw_map(map, lines, columns + 1);
	else if (map->map[lines + 1])
	{
		columns = 0;
		draw_map(map, lines + 1, columns);
	}
}

int	init_mlx(t_game *map)
{
	map->wind = mlx_init(PXL * map->width, PXL * (map->height + 1), "so_long", 0);
	if (load_textures(map) == EXIT_SUCCESS)
	{
		draw_map(map, 0, 0);
		mlx_key_hook(map->wind, &on_key_press, map);
		mlx_loop(map->wind);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
