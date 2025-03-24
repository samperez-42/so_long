/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/24 15:41:03 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Need to read the whole map in a while loop using gnl
// 

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
	int i = 0;
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

/* void	init_mlx(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "Pedrito.txt", true);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
} */
