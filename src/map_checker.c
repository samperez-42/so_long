/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:49:43 by samperez          #+#    #+#             */
/*   Updated: 2025/04/14 11:52:17 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_chr(t_game *map, char current, int lines, int columns)
{
	if (current == 'P')
		map->p_num++;
	else if (current == 'C')
		map->coin++;
	else if (current == 'E')
	{
		map->exit_pos.x = columns;
		map->exit_pos.y = lines;
		map->exit++;
	}
	else if (current == '0' || current == '1')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_map_dimensions(t_game *map, int *lines, int *columns)
{
	int	c_columns;

	c_columns = 0;
	*lines = 0;
	*columns = 0;
	while (map->map[*lines])
	{
		c_columns = 0;
		while (map->map[*lines][c_columns])
		{
			if (count_chr(map, map->map[*lines][c_columns], *lines, c_columns))
				return (ft_printf("Error\nInvalid characters detected\n"));
			c_columns++;
		}
		if (*columns == 0)
			*columns = c_columns;
		else if (c_columns != *columns)
			return (ft_printf("Error\nMap is not rectangular\n"));
		(*lines)++;
	}
	if (map->coin < 1 || map->exit != 1 || map->p_num != 1)
		return (ft_printf("Error\nIncorrect number of objects\n"));
	map->width = *columns;
	map->height = *lines;
	return (EXIT_SUCCESS);
}

static int	check_map_enclosed(char **map, int *lines, int *columns)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j++ < *columns - 1)
	{
		if (map[i][j] != '1')
			return (EXIT_FAILURE);
	}
	while (i++ < *lines - 1)
	{
		if (map[i][0] != '1' || map[i][*columns - 1] != '1')
			return (EXIT_FAILURE);
	}
	j = 0;
	while (j++ < *columns - 1)
	{
		if (map[i - 1][j] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_game *map)
{
	int	lines;
	int	columns;

	if (check_map_dimensions(map, &lines, &columns) != EXIT_SUCCESS)
	{
		free_all(map);
		return (EXIT_FAILURE);
	}
	if (check_map_enclosed(map->map, &lines, &columns) != EXIT_SUCCESS)
	{
		free_all(map);
		return (ft_printf("Error\nMap is not enclosed\n"));
	}
	return (EXIT_SUCCESS);
}

int	map_control(t_game *map, int fd)
{
	if (read_map(map, fd))
		return (EXIT_FAILURE);
	if (parse_map(map))
		return (EXIT_FAILURE);
	if (flood_fill(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
