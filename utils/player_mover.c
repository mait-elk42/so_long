/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:22:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/19 21:33:13 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_move_to(t_mlx	*mlx_info, t_vect2 newpos, void	*ptexture)
{
	if (mlx_info->maps[newpos.y][newpos.x] == 'E' && mlx_info->P_Coll_n == mlx_info->Coll_Goal)
		_nsx_exit("YOU WIN !", 0, 0);
	if (mlx_info->maps[newpos.y][newpos.x] == 'C')
	{
		_nsx_draw_image(mlx_info, newpos, mlx_info->Floor.sprite);
		mlx_info->P_Coll_n++;
		mlx_info->maps[newpos.y][newpos.x] = '0';
		if (mlx_info->P_Coll_n == mlx_info->Coll_Goal)
		{
			_nsx_Log("Door Is Open Now ! Go To him", "");
			_nsx_draw_image(mlx_info, mlx_info->doorpos, mlx_info->door_open.sprite);
			mlx_info->door_locked = 0;
		}
	}
	if (mlx_info->maps[newpos.y][newpos.x] == '0')
	{
		_nsx_draw_image(mlx_info, mlx_info->player.pos, mlx_info->Floor.sprite);
		_nsx_draw_image(mlx_info, newpos, ptexture);
		mlx_info->maps[mlx_info->player.pos.y][mlx_info->player.pos.x] = '0';
		mlx_info->maps[newpos.y][newpos.x] = 'P';
		_initialize_vect(&mlx_info->player.pos, newpos.x, newpos.y);
		mlx_info->P_steps_count++;
		_nsx_show_score(mlx_info);
		free(ptexture);
	}
}
