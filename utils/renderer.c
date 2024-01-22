/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:18:13 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/22 00:17:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_auto_render(t_mlx *mlx_info, t_vect2 pos)
{
	_nsx_draw_xpm(mlx_info, pos, "textures/tiles/tile04.xpm");
	if (mlx_info->maps[pos.y][pos.x] == 'C')
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin0.xpm");
	else if (mlx_info->maps[pos.y][pos.x] == 'E')
		_nsx_draw_xpm(mlx_info, pos, "textures/door_close.xpm");
	else if (mlx_info->maps[pos.y][pos.x] == '1')
		_nsx_draw_xpm(mlx_info, pos, "textures/box.xpm");
	else if (mlx_info->maps[pos.y][pos.x] == 'P')
		_nsx_draw_xpm(mlx_info, pos, "textures/player_down.xpm");
}

void	_nsx_putcoin_nextframe(t_mlx *mlx_info, t_vect2 pos, int f)
{
	_nsx_draw_xpm(mlx_info, pos, "textures/tiles/tile04.xpm");
	if (f == 0)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin0.xpm");
	if (f == 1)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin1.xpm");
	if (f == 2)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin2.xpm");
	if (f == 3)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin3.xpm");
	if (f == 4)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin4.xpm");
	if (f == 5)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin5.xpm");
	if (f == 6)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin6.xpm");
	if (f == 7)
		_nsx_draw_xpm(mlx_info, pos, "textures/keys/coin7.xpm");
}
