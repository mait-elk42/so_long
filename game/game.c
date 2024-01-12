/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/12 13:28:36 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx *m_data)
{
	gameobject->sprite = mlx_xpm_file_to_image(m_data->mlx_ptr, xpmfile, &gameobject->x, &gameobject->y);
	gameobject->x = 0;
	gameobject->y = 0;
}

void	_painter_api(t_mlx *mlx_info, t_vect2 step, t_vect2 pos)
{
	t_nsx_Gobject	*objects;
	void			*mlx_ptr;
	void			*win_ptr;
	t_vect2			win_xy;
	char			c;

	c = mlx_info->maps[pos.y][pos.x];
	objects = mlx_info->objects;
	mlx_ptr = mlx_info->mlx_ptr;
	win_ptr = mlx_info->win_ptr;
	_initialize_vect(&win_xy, mlx_info->win_x, mlx_info->win_y);
	if (pos.x == 0 && pos.y == 0 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[0].sprite , step.x, step.y);
	else if (pos.x == win_xy.x-1 && pos.y == 0 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[2].sprite , step.x, step.y);
	else if (pos.y == win_xy.y-1 && pos.x == 0 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[6].sprite , step.x, step.y);
	else if (pos.y == win_xy.y-1 && pos.x == win_xy.x-1 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[8].sprite , step.x, step.y);
	else if (pos.y == win_xy.y-1 && pos.x < win_xy.x-1 && pos.x > 0 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[7].sprite , step.x, step.y);
	else if ((pos.y == 0 || pos.y == win_xy.y) && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[1].sprite , step.x, step.y);
	else if (pos.x == 0 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[3].sprite , step.x, step.y);
	else if (pos.x == win_xy.x-1 && c == '1')
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[5].sprite , step.x, step.y);
	else if (pos.x > 0 && pos.x < win_xy.x-1)
		mlx_put_image_to_window(mlx_ptr, win_ptr, objects[4].sprite , step.x, step.y);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_info->player->sprite , step.x, step.y);
		mlx_info->player->x = pos.x;
		mlx_info->player->y = pos.y;
	}
}

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

void	_nsx_paint_walls(t_mlx *mlx_info)
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
	// _initialize_vect(&xy, OBJ_SCALE , OBJ_SCALE);
	// while (xy.y < max_xy.y-OBJ_SCALE)
	// {
	// 	xy.x = OBJ_SCALE;
	// 	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[3].sprite , 0, xy.y);
	// 	while (xy.x < max_xy.x-OBJ_SCALE)
	// 	{
	// 		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[4].sprite , xy.x, xy.y);
	// 		xy.x+= OBJ_SCALE;
	// 	}
	// 	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[5].sprite , xy.x, xy.y);
	// 	xy.y += OBJ_SCALE;
	// }
	// xy.x = OBJ_SCALE;
	// mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[6].sprite , 0, xy.y);
	// while (xy.x < max_xy.x-OBJ_SCALE)
	// {
	// 	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[7].sprite , xy.x, xy.y);
	// 	xy.x+=OBJ_SCALE;
	// }
	// mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[8].sprite , xy.x, xy.y);
}

void	_nsx_start_game(t_mlx	*mlx_data)
{
	mlx_data->objects = malloc(sizeof(t_nsx_Gobject) * 9);
	mlx_data->player = malloc(sizeof(t_nsx_Gobject));
	_nsx_new_gameobject("./sprites/tiles/tile00.xpm", &mlx_data->objects[0], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile01.xpm", &mlx_data->objects[1], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile02.xpm", &mlx_data->objects[2], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile03.xpm", &mlx_data->objects[3], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile04.xpm", &mlx_data->objects[4], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile05.xpm", &mlx_data->objects[5], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile06.xpm", &mlx_data->objects[6], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile07.xpm", &mlx_data->objects[7], mlx_data);
	_nsx_new_gameobject("./sprites/tiles/tile08.xpm", &mlx_data->objects[8], mlx_data);
	_nsx_new_gameobject("./sprites/player/idle/plr_idle0.xpm", mlx_data->player, mlx_data);
	mlx_hook(mlx_data->win_ptr, 17, 0, exitfunc, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_down, mlx_data);
	mlx_loop_hook(mlx_data->mlx_ptr, loop, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}