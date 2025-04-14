/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:41 by samperez          #+#    #+#             */
/*   Updated: 2025/04/14 12:07:25 by samperez         ###   ########.fr       */
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
		ft_printf("Error\nWrong map format\n");
		return (-1);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCan't open the map\n");
		return (-1);
	}
	return (fd);
}

static int	check_consecutive_new_lines(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			free(line);
			ft_printf("Error\nConsecutive new lines detected\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_map_empty(char *tmp, t_game *map, int fd)
{
	if (!tmp)
	{
		ft_printf("Error\nEmpty map\n");
		free_all(map);
		close(fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	read_map(t_game *map, int fd)
{
	char	*line;
	char	*tmp;

	tmp = get_next_line(fd);
	if (check_map_empty(tmp, map, fd))
		return (EXIT_FAILURE);
	line = NULL;
	while (tmp != NULL)
	{
		line = ft_gnl_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	if (check_consecutive_new_lines(line) == EXIT_FAILURE)
	{
		free_all(map);
		return (EXIT_FAILURE);
	}
	map->map = ft_split(line, '\n');
	map->map_save = ft_split(line, '\n');
	free(line);
	return (EXIT_SUCCESS);
}
