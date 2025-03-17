/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:36:45 by samperez          #+#    #+#             */
/*   Updated: 2025/03/17 12:37:27 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(WIDTH, HEIGHT, "Pedrito.txt", true);
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
}