/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:48 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 21:31:05 by mait-elk         ###   ########.fr       */
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
	if (mlx_info->maps[y][x] == 'E' && mlx_info->player.Coll_n == mlx_info->Coll_Goal)
		{
			_nsx_exit("YOU WIN !", 0, 0);
		}
	if (mlx_info->maps[y][x] == 'C')
		{
			mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->Floor.sprite, x * OBJ_SCALE, y * OBJ_SCALE);
			mlx_info->player.Coll_n++;
			mlx_info->maps[y][x] = '0';
		}
	if (mlx_info->maps[y][x] == '0')
	{
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->Floor.sprite, mlx_info->player.pos.x * OBJ_SCALE, mlx_info->player.pos.y * OBJ_SCALE);
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->player.sprite, x * OBJ_SCALE, y * OBJ_SCALE);
		mlx_info->maps[mlx_info->player.pos.y][mlx_info->player.pos.x] = '0';
		mlx_info->maps[y][x] = 'P';
		_initialize_vect(&mlx_info->player.pos, x, y);
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->Score_Board.sprite, 0, 0);
		mlx_info->player.steps_count++;
		if (mlx_info->player.steps_count < 255)
			mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 1, 0, _nsx_gettrgb(255, (mlx_info->player.steps_count % 255), 255 - (mlx_info->player.steps_count % 255), 0), ft_itoa(mlx_info->player.steps_count));
		else
			mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 1, 0, _nsx_gettrgb(255, 255, 0, 0), ft_itoa(mlx_info->player.steps_count));
	}
}
