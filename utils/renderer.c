/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:18:13 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 05:03:25 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_auto_render(t_mlx *mlx_info, t_vect2 pos)
{
	_nsx_draw_xpm(mlx_info, pos, "textures/tiles/tile04.xpm");
	if (mlx_info->maps[pos.y][pos.x] == 'C')
		_nsx_draw_xpm(mlx_info, pos, "textures/foods/food0.xpm");
	else if (mlx_info->maps[pos.y][pos.x] == 'E')
	{
		if (mlx_info->door_locked)
			_nsx_draw_xpm(mlx_info, pos, "textures/door_close.xpm");
		else
			_nsx_draw_xpm(mlx_info, pos, "textures/door_open.xpm");
	}
	else if (mlx_info->maps[pos.y][pos.x] == '1')
		_nsx_draw_xpm(mlx_info, pos, "textures/box.xpm");
	else if (mlx_info->maps[pos.y][pos.x] == 'P')
		_nsx_draw_xpm(mlx_info, pos, "textures/player_down.xpm");
}
