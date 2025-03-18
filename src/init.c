/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/18 15:28:22 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Need to read the whole map in a while loop using gnl
// 
void	read_map(char **map, int fd)
{
	char	*tmp;
	int		rows;
	int		chars;

	rows = 0;
	chars = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		chars += ft_strlen(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		rows++;
	}
	
}

void	init_mlx(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "Pedrito.txt", true);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
}