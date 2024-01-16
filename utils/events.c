/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 17:57:43 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	_nsx_gettrgb(int t, int r, int g, int b)
{
	return (t << 24 | r  << 16 | g << 8 | b);
}

int	key_down(int keycode, t_mlx *mlx_info)
{
	if (keycode == 53)
		_nsx_game_closed(mlx_info);
	if ((keycode == K_W || keycode == K_ARROW_UP))
		_move_to(mlx_info, mlx_info->P_pos.x, mlx_info->P_pos.y-1);
	if ((keycode == K_S || keycode == K_ARROW_DOWN))
		_move_to(mlx_info, mlx_info->P_pos.x, mlx_info->P_pos.y+1);
	if ((keycode == K_A || keycode == K_ARROW_LEFT))
		_move_to(mlx_info, mlx_info->P_pos.x-1, mlx_info->P_pos.y);
	if ((keycode == K_D || keycode == K_ARROW_RIGHT))
		_move_to(mlx_info, mlx_info->P_pos.x+1, mlx_info->P_pos.y);
	// ft_printf("%d\n", keycode);
	return (0);
}

int	exitfunc(t_mlx *mlx_info)
{
	_nsx_game_closed(mlx_info);
	return (0);
}

int	loop(t_mlx *mlx_info)
{
	// t_vect2	step;
	// t_vect2	pos;
	// t_vect2	max;

	(void)mlx_info;
	// _initialize_vect(&step, 0, 0);
	// _initialize_vect(&pos, 0, 0);
	// _initialize_vect(&max, mlx_info->win_x, mlx_info->win_y);
	// if (mlx_info->P_Coll_n == mlx_info->Coll_Goal && mlx_info->door_locked)
	// 	{
	// 		ft_printf("THE DOOR IS OPENED!!!\n");
	// 		_nsx_draw_image(mlx_info, mlx_info->doorpos, mlx_info->Floor);
	// 		_nsx_draw_image(mlx_info, (t_vect2){mlx_info->doorpos.x + OBJ_SCALE, mlx_info->doorpos.y + OBJ_SCALE}, mlx_info->door.door_open);
	// 		mlx_info->door_locked = 0;
	// 	}
	return (0);
}