/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:52:05 by samperez          #+#    #+#             */
/*   Updated: 2025/04/09 12:25:14 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_all(t_game *map)
{
	if (map->map)
		free_map(map->map);
	if (map->map_save)
		free_map(map->map_save);
	free(map);
}

int	check_textures_exist(t_game *map)
{
	if (!map->img.coll || !map->img.wall || !map->img.exit_c
		|| !map->img.exit_o || !map->img.p || !map->img.tile)
	{
		return (ft_printf("Error\nFailed to open the textures\n"));
	}
	return (EXIT_SUCCESS);
}

void	free_textures(t_game *map)
{
	if (map->img.coll)
		mlx_delete_texture(map->img.coll);
	if (map->img.wall)
		mlx_delete_texture(map->img.wall);
	if (map->img.exit_c)
		mlx_delete_texture(map->img.exit_c);
	if (map->img.exit_o)
		mlx_delete_texture(map->img.exit_o);
	if (map->img.p)
		mlx_delete_texture(map->img.p);
	if (map->img.tile)
		mlx_delete_texture(map->img.tile);
}

void	destroy_images(t_game *map)
{
	mlx_delete_image(map->wind, map->img.collect_i);
	mlx_delete_image(map->wind, map->img.wall_i);
	mlx_delete_image(map->wind, map->img.p_i);
	mlx_delete_image(map->wind, map->img.exit_c_i);
	mlx_delete_image(map->wind, map->img.exit_o_i);
	mlx_delete_image(map->wind, map->img.ti_i);
	mlx_terminate(map->wind);
}
