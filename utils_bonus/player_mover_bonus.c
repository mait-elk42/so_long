/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:22:31 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 21:20:13 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_move_to(t_mlx	*mlx_info, t_vect2 newpos, char	*texturepath)
{
	if (mlx_info->maps[newpos.y][newpos.x] == 'E'
		&& mlx_info->p_coll_n == mlx_info->coll_goal)
		_nsx_exit("YOU WIN !", 0, 0);
	if (mlx_info->maps[newpos.y][newpos.x] == 'C')
	{
		_nsx_draw_xpm(mlx_info, newpos, "textures/tiles/tile04.xpm");
		mlx_info->p_coll_n++;
		mlx_info->maps[newpos.y][newpos.x] = '0';
		if (mlx_info->p_coll_n == mlx_info->coll_goal)
		{
			_nsx_draw_xpm(mlx_info, mlx_info->doorpos,
				"textures/door_open.xpm");
			mlx_info->door_locked = 0;
		}
	}
	if (mlx_info->maps[newpos.y][newpos.x] == '0')
	{
		_nsx_draw_xpm(mlx_info, mlx_info->plrpos, "textures/tiles/tile04.xpm");
		_nsx_draw_xpm(mlx_info, newpos, texturepath);
		mlx_info->maps[mlx_info->plrpos.y][mlx_info->plrpos.x] = '0';
		mlx_info->maps[newpos.y][newpos.x] = 'P';
		_nsx_initialize_vect(&mlx_info->plrpos, newpos.x, newpos.y);
		mlx_info->p_steps_count++;
		_nsx_show_score(mlx_info);
	}
}
