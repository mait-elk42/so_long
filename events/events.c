/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/12 12:43:53 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_down(int keycode, t_mlx *mlx_info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		_nsx_exit("GAME OVER", 0, 0);
	}
	if ((keycode == 13 || keycode == 126))
		_move_to(mlx_info, mlx_info->player->x, mlx_info->player->y-1);
	// else
	if ((keycode == 0 || keycode == 123) && mlx_info->maps[mlx_info->player->y][mlx_info->player->x-1] != '1')
		_move_to(mlx_info, mlx_info->player->x-1, mlx_info->player->y);
	// else
	if ((keycode == 1 || keycode == 125) && mlx_info->maps[mlx_info->player->y+1][mlx_info->player->x] != '1')
		_move_to(mlx_info, mlx_info->player->x, mlx_info->player->y+1);
	// else
	if ((keycode == 2 || keycode == 124) && mlx_info->maps[mlx_info->player->y][mlx_info->player->x+1] != '1')
		_move_to(mlx_info, mlx_info->player->x+1, mlx_info->player->y);
	ft_printf("%d\n", keycode);
	return (0);
}

int	exitfunc(t_mlx *mlx_info)
{
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	_nsx_exit("GAME OVER", 0, 0);
	return (0);
}

int	loop(t_mlx *mlx_info)
{
	t_vect2	step;
	t_vect2	pos;
	t_vect2	max;

	_initialize_vect(&step, 0, 0);
	_initialize_vect(&pos, 0, 0);
	_initialize_vect(&max, mlx_info->win_x, mlx_info->win_y);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	_nsx_paint_walls(mlx_info);
	// while (pos.y < max.y)
	// {
	// 	pos.x = 0;
	// 	step.x = 0;
	// 	while (pos.x < max.x)
	// 	{
	// 		_painter_api(mlx_info, step, pos);
	// 		pos.x++;
	// 		step.x += OBJ_SCALE;
	// 	}
	// 	pos.y++;
	// 	step.y += OBJ_SCALE;
	// }
	return (0);
}