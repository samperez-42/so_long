/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/04/09 12:34:19 by samperez         ###   ########.fr       */
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

int	init_mlx(t_game *map)
{
	map->wind = mlx_init(PXL * map->width, PXL * map->height, "so_long", 0);
	if (load_textures(map) == EXIT_SUCCESS)
	{
		//mlx_key_hook(map->wind, &on_key_press, map);
		mlx_loop(map->wind);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
