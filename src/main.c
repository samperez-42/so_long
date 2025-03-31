/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/03/31 11:22:21 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*map;

	if (argc != 2)
		return (ft_printf("Error\nIncorrect number of arguments\n"));
	fd = open_map(argv[1]);
	map = ft_calloc(1, sizeof(t_game));
	if (!map)
		return (ft_printf("Error\nMalloc failed\n"));
	read_map(map, fd);
	parse_map(map);
//	flood_fill(map->map_save);
	free_all(map);
}
