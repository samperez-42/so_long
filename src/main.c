/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:19:09 by samperez          #+#    #+#             */
/*   Updated: 2025/03/18 14:22:08 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	map = NULL;
	if (argc != 2)
		return (ft_printf("ERROR\nIncorrect number of arguments\n"));
	check_map_extension(argv[1]);
	fd = check_map(argv[1]);
	read_map(map, fd);


	close(fd);
}
