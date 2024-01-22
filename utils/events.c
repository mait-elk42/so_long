/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/22 00:19:30 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_nsx_key_down(int keycode, t_mlx *mlx_info)
{
	t_vect2	newpos;

	if (keycode == K_ESC)
		_nsx_game_closed(mlx_info);
	newpos = mlx_info->plrpos;
	newpos.y -= (keycode == K_W || keycode == K_ARROW_UP);
	newpos.y += (keycode == K_S || keycode == K_ARROW_DOWN);
	newpos.x -= (keycode == K_A || keycode == K_ARROW_LEFT);
	newpos.x += (keycode == K_D || keycode == K_ARROW_RIGHT);
	_nsx_move_to(mlx_info, newpos);
	return (0);
}

int	_nsx_exitfunc(t_mlx *mlx_info)
{
	_nsx_game_closed(mlx_info);
	return (0);
}
