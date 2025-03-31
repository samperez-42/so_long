/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:49:43 by samperez          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:27 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_dimensions(char **map, int *lines, int *columns)
{
	int	current_columns;

	current_columns = 0;
	*lines = 0;
	*columns = 0;
	while (map[*lines])
	{
		current_columns = 0;
		while (map[*lines][current_columns])
		{
			if (map[*lines][current_columns] != '1'
				&& map[*lines][current_columns] != '0'
				&& map[*lines][current_columns] != 'E'
				&& map[*lines][current_columns] != 'C'
				&& map[*lines][current_columns] != 'P')
				return (ft_printf("Error\nInvalid characters detected\n"));
			current_columns++;
		}
		if (*columns == 0)
			*columns = current_columns;
		else if (current_columns != *columns)
			return (EXIT_FAILURE);
		(*lines)++;
	}
	return (EXIT_SUCCESS);
}

int	is_map_rectangular(char **map)
{
	int	lines;
	int	columns;

	if (check_map_dimensions(map, &lines, &columns) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
