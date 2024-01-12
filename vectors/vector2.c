/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:48 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/12 12:18:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_initialize_vect(t_vect2 *vect2, int x, int y)
{
	vect2->x = x;
	vect2->y = y;
}

void	_move_to(t_mlx	*mlx_info, int x, int y)
{
	if (mlx_info->maps[y][x] != '1')
	{
		mlx_info->maps[mlx_info->player->y][mlx_info->player->x] = '0';
		mlx_info->maps[y][x] = 'P';
		mlx_info->player->x = x;
		mlx_info->player->y = y;
	}
}