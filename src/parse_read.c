/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:41 by samperez          #+#    #+#             */
/*   Updated: 2025/03/31 11:01:01 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map(const char *map_file)
{
	int	fd;
	int	len;

	len = ft_strlen(map_file);
	if (len <= 4 || map_file[len - 1] != 'r' || map_file[len - 2] != 'e'
		|| map_file[len - 3] != 'b' || map_file[len - 4] != '.')
	{
		ft_printf("Error\nWRONG MAP FORMAT\n");
		exit(EXIT_FAILURE);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		return (ft_printf("Error\nCAN'T OPEN THE MAP"));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

// Need to read the whole map in a while loop using gnl

void	read_map(t_game *map, int fd)
{
	char	*line;
	char	*tmp;

	tmp = get_next_line(fd);
	line = NULL;
	while (tmp != NULL)
	{
		line = ft_gnl_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	map->map = ft_split(line, '\n');
	map->map_save = ft_split(line, '\n');
	free(line);
}

int	parse_map(t_game *map)
{
	if (is_map_rectangular(map->map) == EXIT_FAILURE)
		return (ft_printf("Error\nMap is not rectangular\n"));
/* 	if (check_map_elements(map) == EXIT_FAILURE)
		return (ft_printf("Error\nIncorrect number of objects\n")); */
	return (EXIT_SUCCESS);
}
