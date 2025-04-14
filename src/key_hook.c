/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:06:14 by samperez          #+#    #+#             */
/*   Updated: 2025/04/14 14:54:37 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_p_pos(t_game *map, int target_y, int target_x)
{
	map->p_pos.x = target_x;
	map->p_pos.y = target_y;
}

static void	move_player(t_game *map, int target_y, int target_x)
{
	if (map->map[target_y][target_x] == 'C')
	{
		map->coin--;
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		update_map(map, target_x, target_y);
		update_p_pos(map, target_y, target_x);
		map->map[map->p_pos.y][map->p_pos.x] = 'P';
	}
	else if (map->map[target_y][target_x] == '0')
	{
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		update_map(map, target_x, target_y);
		update_p_pos(map, target_y, target_x);
		map->map[map->p_pos.y][map->p_pos.x] = 'P';
	}
	else if (map->map[target_y][target_x] == 'E')
	{
		if (map->coin == 0)
			mlx_close_window(map->wind);
		map->map[map->p_pos.y][map->p_pos.x] = '0';
		update_map(map, target_x, target_y);
		update_p_pos(map, target_y, target_x);
		map->map[map->p_pos.y][map->p_pos.x] = 'P';
	}
	map->moves++;
}

void	move_p_y(t_game *map, int p_y, int p_x, char key)
{
	if (key == 'w')
	{
		if (map->map[p_y - 1][p_x] != '1')
			move_player(map, p_y - 1, p_x);
	}
	if (key == 's')
	{
		if (map->map[p_y + 1][p_x] != '1')
			move_player(map, p_y + 1, p_x);
	}
	ft_printf("Moves: %d\n", map->moves);
}

void	move_p_x(t_game *map, int p_y, int p_x, char key)
{
	if (key == 'a')
	{
		if (map->map[p_y][p_x - 1] != '1')
			move_player(map, p_y, p_x - 1);
	}
	if (key == 'd')
	{
		if (map->map[p_y][p_x + 1] != '1')
			move_player(map, p_y, p_x + 1);
	}
	ft_printf("Moves: %d\n", map->moves);
}

void	on_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*map;

	map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(map->wind);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_p_y(map, map->p_pos.y, map->p_pos.x, 'w');
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_p_y(map, map->p_pos.y, map->p_pos.x, 's');
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_p_x(map, map->p_pos.y, map->p_pos.x, 'a');
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_p_x(map, map->p_pos.y, map->p_pos.x, 'd');
	if (map->p_pos.x == map->exit_pos.x && map->p_pos.y == map->exit_pos.y)
	{
		check_exit_status(map, map->exit_pos.x, map->exit_pos.y);
		mlx_image_to_window(map->wind, map->img.p_i,
			map->exit_pos.x * PXL, map->exit_pos.y * PXL);
	}
	else
		check_exit_status(map, map->exit_pos.x, map->exit_pos.y);
}
