/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/04/02 15:22:21 by samperez         ###   ########.fr       */
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
	if (read_map(map, fd))
		return (EXIT_FAILURE);
	if (parse_map(map))
		return (EXIT_FAILURE);
	if (flood_fill(map))
		return (EXIT_FAILURE);
	free_all(map);
}
