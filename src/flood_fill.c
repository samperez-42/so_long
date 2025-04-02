/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:23 by samperez          #+#    #+#             */
/*   Updated: 2025/04/02 15:35:41 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	locate_player(t_game *map, char **map_c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_c[i])
	{
		j = 0;
		while (map_c[i][j])
		{
			if (map_c[i][j] == 'P')
			{
				map->p_pos.x = j;
				map->p_pos.y = i;
				if (map_c[i][j + 1] == '1' && map_c[i][j - 1] == '1' && map_c[i
					+ 1][j] == '1' && map_c[i - 1][j] == '1')
					return (ft_printf("Error\nPlayer trapped\n"));
				return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	check_path(t_game *map, char **map_c, int y, int x)
{
	if (map_c[y][x] == '1' || map_c[y][x] == '*')
		return ;
	else if (map_c[y][x] == 'C')
		map->coin_c++;
	else if (map_c[y][x] == 'E')
		map->exit_c++;
	map_c[y][x] = '*';
	check_path(map, map->map_save, y, x + 1);
	check_path(map, map->map_save, y, x - 1);
	check_path(map, map->map_save, y + 1, x);
	check_path(map, map->map_save, y - 1, x);
}

int	flood_fill(t_game *map)
{
	int	x;
	int	y;

	if (locate_player(map, map->map_save) != EXIT_SUCCESS)
	{
		free_all(map);
		return (EXIT_FAILURE);
	}
	x = map->p_pos.x;
	y = map->p_pos.y;
	check_path(map, map->map_save, y, x);
	if (map->coin != map->coin_c)
		return (ft_printf("Error\nNot all collectibles are reachable\n"));
	if (map->exit != map->exit_c)
		return (ft_printf("Error\nExit not reachable\n"));
	return (EXIT_SUCCESS);
}
