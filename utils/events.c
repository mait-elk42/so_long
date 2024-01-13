/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/13 23:23:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_painter_api(t_mlx *mlx_info, t_vect2 step, t_vect2 pos)
{
	// t_vect2	plrpos;
	char	**maps;

	// plrpos = mlx_info->player.pos;
	maps = mlx_info->maps;
	if (maps[pos.y][pos.x] == '1' && pos.x != mlx_info->win_x-1 && pos.y != mlx_info->win_y-1 && pos.x != 0 && pos.y != 0)
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[9].sprite, step.x, step.y);
	if (maps[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[10].sprite, step.x, step.y);
	if (maps[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[11].sprite, step.x, step.y);
	if (maps[pos.y][pos.x] == 'P')
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->player.sprite, step.x, step.y);
}

int	key_down(int keycode, t_mlx *mlx_info)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		_nsx_free_all(mlx_info);
		_nsx_exit("GAME OVER", 0, 0);
	}
	if ((keycode == K_W || keycode == K_ARROW_UP))
		_move_to(mlx_info, mlx_info->player.pos.x, mlx_info->player.pos.y-1);
	if ((keycode == K_S || keycode == K_ARROW_DOWN))
		_move_to(mlx_info, mlx_info->player.pos.x, mlx_info->player.pos.y+1);
	if ((keycode == K_A || keycode == K_ARROW_LEFT))
		_move_to(mlx_info, mlx_info->player.pos.x-1, mlx_info->player.pos.y);
	if ((keycode == K_D || keycode == K_ARROW_RIGHT))
		_move_to(mlx_info, mlx_info->player.pos.x+1, mlx_info->player.pos.y);
	// ft_printf("%d\n", keycode);
	return (0);
}

int	exitfunc(t_mlx *mlx_info)
{
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	_nsx_free_all(mlx_info);
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
	// mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	// if (mlx_info->player.Coll_n == mlx_info->Coll_Goal && mlx_info->door_frames < mlx_info->door_max_frames)
	// 	{
	// 		_nsx_exit("YOU WIN !", 0, 0);
	// 		ft_printf("THE DOOR IS OPENED!");
	// 		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[4].sprite, mlx_info->doorpos.x * OBJ_SCALE, mlx_info->doorpos.y * OBJ_SCALE);
	// 		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[mlx_info->door_frames+11].sprite, mlx_info->doorpos.x* OBJ_SCALE, mlx_info->doorpos.y* OBJ_SCALE);
	// 		mlx_info->door_frames++;
	// 	}
	while (pos.y < max.y)
	{
		pos.x = 0;
		step.x = 0;
		while (pos.x < max.x)
		{
			_painter_api(mlx_info, step, pos);
			pos.x++;
			step.x += OBJ_SCALE;
		}
		pos.y++;
		step.y += OBJ_SCALE;
	}
	return (0);
}