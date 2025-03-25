/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/03/25 12:56:03 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*map;

	map = ft_calloc(1, sizeof(t_game));
	if (!map)
		return (ft_printf("Error\nMalloc failed\n"));
	if (argc != 2)
		return (ft_printf("Error\nIncorrect number of arguments\n"));
	fd = open_map(argv[1]);
	read_map(map, fd);
	parse_map(map);
	free_all(map);
}
