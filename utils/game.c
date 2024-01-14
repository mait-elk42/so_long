/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/14 20:26:01 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_paint_line(t_mlx *mlx_info, int a, int b, int c, int y)
{
	int	x;
	int	max_x;

	x = OBJ_SCALE;
	max_x = OBJ_SCALE * mlx_info->win_x;
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[a].sprite, 0, y);
	while (x < max_x-OBJ_SCALE)
	{
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[b].sprite, x, y);
		x+= OBJ_SCALE;
	}
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[c].sprite, x, y);
}

void	_nsx_print_maps(t_mlx *mlx_info)
{
	int	y;
	int	max_y;

	y = OBJ_SCALE;
	max_y = mlx_info->win_y * OBJ_SCALE;
	_nsx_paint_line(mlx_info, 0, 1, 2, 0);
	while (y < max_y - OBJ_SCALE)
	{
		_nsx_paint_line(mlx_info, 3, 4, 5, y);
		y+=OBJ_SCALE;
	}
	_nsx_paint_line(mlx_info, 6, 7, 8, y);
}

void	_nsx_get_player_pos(t_mlx *mlx_info)
{
	t_vect2	i;
	
	_initialize_vect(&i, 0, 0);
	while (i.y < mlx_info->win_y)
	{
		i.x = 0;
		while (i.x < mlx_info->win_x)
		{
			if (mlx_info->maps[i.y][i.x] == 'P')
					_initialize_vect(&mlx_info->player.pos, i.x, i.y);
			if (mlx_info->maps[i.y][i.x] == 'C')
					mlx_info->Coll_Goal++;
			if (mlx_info->maps[i.y][i.x] == 'E')
					_initialize_vect(&mlx_info->doorpos, i.x, i.y);
			// if (mlx_info->maps[i.y][i.x] == 'E' && mlx_info->Coll_Goal == mlx_info->player.Coll_n)
			// 		_nsx_exit("YOU WIN ! ", 0, 0);
			i.x++;
		}
		i.y++;
	}
}

void	_nsx_start_game(t_mlx	*mlx_data)
{
	mlx_data->objects = malloc(sizeof(t_nsx_Gobject) * 13);
	_nsx_new_gameobject("textures/tiles/tile00.xpm", &mlx_data->objects[0], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile01.xpm", &mlx_data->objects[1], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile02.xpm", &mlx_data->objects[2], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile03.xpm", &mlx_data->objects[3], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile04.xpm", &mlx_data->objects[4], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile05.xpm", &mlx_data->objects[5], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile06.xpm", &mlx_data->objects[6], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile07.xpm", &mlx_data->objects[7], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile08.xpm", &mlx_data->objects[8], mlx_data);
	_nsx_new_gameobject("textures/tiles/tile09.xpm", &mlx_data->objects[9], mlx_data);
	_nsx_new_gameobject("textures/foods/food2.xpm", &mlx_data->objects[10], mlx_data);
	_nsx_new_gameobject("textures/door/door0.xpm", &mlx_data->objects[11], mlx_data);
	_nsx_new_gameobject("textures/door/door1.xpm", &mlx_data->objects[12], mlx_data);
	_nsx_new_player("textures/player/plr_idle.xpm", &mlx_data->player, mlx_data);
	mlx_hook(mlx_data->win_ptr, 17, 0, exitfunc, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_down, mlx_data);
	mlx_loop_hook(mlx_data->mlx_ptr, loop, mlx_data);
	mlx_data->Coll_Goal = 0;
	mlx_data->door_locked = 1;
	_nsx_get_player_pos(mlx_data);
	_nsx_print_maps(mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
