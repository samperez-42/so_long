/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:41 by samperez          #+#    #+#             */
/*   Updated: 2025/03/24 16:27:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(const char *map_file)
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
	if (fd == -1)
	{
		ft_printf("Error\nCAN'T OPEN THE MAP");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
