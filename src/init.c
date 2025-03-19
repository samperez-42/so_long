/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/19 12:56:25 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Need to read the whole map in a while loop using gnl
// 
void	read_map(char **map, int fd)
{
//	char	*tmp;
	int		rows;
	int		chars;

	rows = 0;
	chars = 0;
	map = (char **)malloc(sizeof(char **));
	map[rows] = get_next_line(fd);
	ft_printf("%s", map[rows]);
 	while (1)
	{
		map[rows] = get_next_line(fd);
		ft_printf("%s", map[rows]);
//		free(tmp); // Double free
//		tmp = NULL;
		if (map[rows] == NULL)
			break ;
		rows++;
	}
	free_map(map);
}

/* void	init_mlx(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "Pedrito.txt", true);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
} */
