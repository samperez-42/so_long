/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:49:43 by samperez          #+#    #+#             */
/*   Updated: 2025/03/31 13:00:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_chars(t_game *map, char current)
{
	if (current == 'P')
		map->p_num++;
	else if (current == 'C')
		map->coin++;
	else if (current == 'E')
		map->exit++;
	else if (current == '0' || current == '1')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_map_dimensions(t_game *map, int *lines, int *columns)
{
	int	current_columns;

	current_columns = 0;
	*lines = 0;
	*columns = 0;
	while (map->map[*lines])
	{
		current_columns = 0;
		while (map->map[*lines][current_columns])
		{
			if (count_chars(map, map->map[*lines][current_columns])
			== EXIT_FAILURE)
				return (ft_printf("Error\nInvalid characters detected\n"));
			current_columns++;
		}
		if (*columns == 0)
			*columns = current_columns;
		else if (current_columns != *columns)
			return (EXIT_FAILURE);
		(*lines)++;
	}
	if (map->coin < 1 || map->exit != 1 || map->p_num != 1)
		return (ft_printf("Error\nIncorrect number of objects\n"));
	return (EXIT_SUCCESS);
}

int	parse_map(t_game *map)
{
	int	lines;
	int	columns;

	if (check_map_dimensions(map, &lines, &columns) == EXIT_FAILURE)
		return (ft_printf("Error\nMap is not rectangular\n"));
	return (EXIT_SUCCESS);
}
