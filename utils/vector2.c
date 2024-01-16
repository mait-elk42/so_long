/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:48 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 18:32:09 by mait-elk         ###   ########.fr       */
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
	if (mlx_info->maps[y][x] == 'E' && mlx_info->P_Coll_n == mlx_info->Coll_Goal)
		{
			_nsx_exit("YOU WIN !", 0, 0);
		}
	if (mlx_info->maps[y][x] == 'C')
		{
			_nsx_draw_image(mlx_info, (t_vect2){x, y}, mlx_info->Floor);
			mlx_info->P_Coll_n++;
			mlx_info->maps[y][x] = '0';
			if (mlx_info->P_Coll_n == mlx_info->Coll_Goal)
			{
				_nsx_draw_image(mlx_info, mlx_info->doorpos, mlx_info->Floor);
				_nsx_draw_image(mlx_info, mlx_info->doorpos, mlx_info->door_open);
			}
		}
	if (mlx_info->maps[y][x] == '0')
	{
		_nsx_draw_image(mlx_info, mlx_info->P_pos, mlx_info->Floor);
		_nsx_draw_image(mlx_info, (t_vect2){x, y},mlx_info->player);
		mlx_info->maps[mlx_info->P_pos.y][mlx_info->P_pos.x] = '0';
		mlx_info->maps[y][x] = 'P';
		_initialize_vect(&mlx_info->P_pos, x, y);
		_nsx_draw_image(mlx_info, (t_vect2){0, 0}, mlx_info->Score_Board);
		mlx_info->P_steps_count++;
		_nsx_draw_str(mlx_info, (t_vect2){0, 0}, ft_itoa(mlx_info->P_steps_count));
	}
}
