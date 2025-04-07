/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/04/07 11:18:53 by samperez         ###   ########.fr       */
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
	if (map_control(map, fd))
		return (EXIT_FAILURE);
	init_mlx();
	free_all(map);
}
