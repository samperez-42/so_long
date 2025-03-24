/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/03/24 15:21:36 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*map;

	map = ft_calloc(1, sizeof(t_game));
	if (!map)
		return (ft_printf("ERROR\nMalloc failed\n"));
	if (argc != 2)
		return (ft_printf("ERROR\nIncorrect number of arguments\n"));
	fd = check_map(argv[1]);
	read_map(map, fd);
	free_all(map);
}
