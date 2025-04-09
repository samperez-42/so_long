/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:14 by samperez          #+#    #+#             */
/*   Updated: 2025/04/09 13:48:05 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	on_key_press(mlx_key_data_t keydata, void *param)
{
	t_game *map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->wind);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_printf("W\n");
	//move_p_y(map, map->p_pos.y, map->p_pos.x, 'w');
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_printf("S\n");	
	//move_p_y(map, map->p_pos.y, map->p_pos.x, 's');
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_printf("A\n");	
	//move_p_x(map, map->p_pos.y, map->p_pos.x, 'a');
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_printf("D\n");	
	//move_p_x(map, map->p_pos.y, map->p_pos.x, 'd');
}
