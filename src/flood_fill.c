/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:23 by samperez          #+#    #+#             */
/*   Updated: 2025/04/02 12:46:34 by samperez         ###   ########.fr       */
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
				if (map_c[i][j + 1] == '1' && map_c[i][j - 1] == '1'
					&& map_c[i + 1][j] == '1' && map_c[i - 1][j] == '1')
					return (ft_printf("Error\nPlayer trapped\n"));
				return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/* static int	check_path(t_game *map, char **map_c)
{
	int	i;
	int	j;

	i = map->p_pos.x;
	j = map->p_pos.y;
 	while (condition)
	{
		if (map_c[i][j] == '1' || map_c[i][j] == '*')
		{
			return ;
		}
		else
			map_c[i][j] = '*';
	}
	return (EXIT_SUCCESS);
} */

int	flood_fill(t_game *map)
{
	if (locate_player(map, map->map_save) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
//	check_path(map, map->map_save);
	return (EXIT_SUCCESS);
}
