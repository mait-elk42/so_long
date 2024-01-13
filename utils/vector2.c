/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:48 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/13 19:03:17 by mait-elk         ###   ########.fr       */
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
		if (mlx_info->maps[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[4].sprite, x * OBJ_SCALE, y * OBJ_SCALE);
				mlx_info->player.Coll_n++;
				mlx_info->maps[y][x] = '0';
			}
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[4].sprite, mlx_info->player.pos.x * OBJ_SCALE, mlx_info->player.pos.y * OBJ_SCALE);
		mlx_info->maps[mlx_info->player.pos.y][mlx_info->player.pos.x] = '0';
		mlx_info->maps[y][x] = 'P';
		mlx_info->player.pos.x = x;
		mlx_info->player.pos.y = y;
		if (mlx_info->player.Coll_n == mlx_info->Coll_Goal)
			_nsx_exit("YOU COLLECTED ALL COLLECTABLES !! YOU WON !\n", 0, 'M');
	}
}
