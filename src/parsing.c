/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:37:41 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 16:12:07 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_extension(const char	*map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.')
		ft_printf("ERROR\nWRONG MAP FORMAT");
	
}
