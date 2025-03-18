/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:41 by samperez          #+#    #+#             */
/*   Updated: 2025/03/18 14:11:18 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_extension(const char	*map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len <= 4 || map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.')
	{
		ft_printf("ERROR\nWRONG MAP FORMAT\n");
		exit(EXIT_FAILURE);
	}
}

int	check_map(const char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR\nCAN'T OPEN THE MAP");
		exit(EXIT_FAILURE);
	}
	else
		return (fd);
}
