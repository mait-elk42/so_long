/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 22:53:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_border(t_mlx *mlx_info, t_vect2 i, t_vect2 j)
{
	char	**maps;

	maps = mlx_info->maps;
	if (maps[i.y][i.x] == '1')
		{
			if (i.x == 0 && i.y == 0)
				_nsx_draw_image(mlx_info, i, mlx_info->world[0]);
			else if (i.x == j.x - 1 && i.y == 0)
				_nsx_draw_image(mlx_info, i, mlx_info->world[2]);
			else if (i.x == 0 && i.y == j.y - 1)
				_nsx_draw_image(mlx_info, i, mlx_info->world[5]);
			else if (i.x == j.x - 1 && i.y == j.y - 1)
				_nsx_draw_image(mlx_info, i, mlx_info->world[7]);
			else if (i.x > 0 && i.x < j.x - 1 && i.y == 0)
				_nsx_draw_image(mlx_info, i, mlx_info->world[1]);
			else if (i.x > 0 && i.x < j.x - 1 && i.y == j.y - 1)
				_nsx_draw_image(mlx_info, i, mlx_info->world[6]);
			else if (i.y > 0 && i.y < j.y - 1 && i.x == 0)
				_nsx_draw_image(mlx_info, i, mlx_info->world[3]);
			else if (i.y > 0 && i.y < j.y - 1 && i.x == j.x - 1)
				_nsx_draw_image(mlx_info, i, mlx_info->world[4]);
			else
				_nsx_draw_image(mlx_info, i, mlx_info->Box);
		}
}

void	_nsx_miniapi(t_vect2 i, t_mlx *mlx_info, char c)
{
	if (ft_strchr("0ECPe", c))
		_nsx_draw_image(mlx_info, i, mlx_info->Floor);
	if (c == 'C')
	{
		mlx_info->Coll_Goal++;
		_nsx_draw_image(mlx_info, i, mlx_info->Collection);
	}
	if (c == 'P')
	{
		_initialize_vect(&mlx_info->player.pos, i.x, i.y);
		_nsx_draw_image(mlx_info, i, mlx_info->player);
	}
	if (c == 'E')
	{
		
		_initialize_vect(&mlx_info->doorpos, i.x, i.y);
		_nsx_draw_image(mlx_info, i, mlx_info->door_close);
	}
	if (c == 'e')
	{
		_initialize_vect(&mlx_info->Enemy.pos, i.x, i.y);
		_nsx_draw_image(mlx_info, i, mlx_info->Enemy);
		mlx_info->Enemy.pos = i;
		mlx_info->Enemies_count++;
	}
}

void	_nsx_init_maps(t_mlx *mlx_info)
{
	char	**maps;
	t_vect2	i;
	t_vect2	j;

	maps = mlx_info->maps;
	mlx_info->door_locked = 1;
	mlx_info->P_steps_count = 0;
	mlx_info->Coll_Goal = 0;
	_initialize_vect(&i, 0, 0);
	_initialize_vect(&j, mlx_info->win_x, mlx_info->win_y);
	while (i.y < j.y)
	{
		i.x = 0;
		while (i.x < j.x)
		{
			_nsx_border(mlx_info, i, j);
			_nsx_miniapi(i, mlx_info, maps[i.y][i.x]);
			i.x++;
		}
		i.y++;
	}
	_nsx_show_score(mlx_info);
}

void	_nsx_init_textures(t_mlx *mlx_info)
{
	mlx_info->world = _nsx_p_malloc(sizeof(t_nsx_Gobject) * 8);
	_nsx_new_gameobject("textures/player.xpm", &mlx_info->player, mlx_info);
	_nsx_new_gameobject("textures/tiles/tile00.xpm", &mlx_info->world[0], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile01.xpm", &mlx_info->world[1], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile02.xpm", &mlx_info->world[2], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile03.xpm", &mlx_info->world[3], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile05.xpm", &mlx_info->world[4], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile06.xpm", &mlx_info->world[5], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile07.xpm", &mlx_info->world[6], mlx_info);
	_nsx_new_gameobject("textures/tiles/tile08.xpm", &mlx_info->world[7], mlx_info);

	_nsx_new_gameobject("textures/tiles/tile04.xpm", &mlx_info->Floor, mlx_info);
	_nsx_new_gameobject("textures/tiles/sboard.xpm", &mlx_info->Score_Board, mlx_info);
	_nsx_new_gameobject("textures/foods/food0.xpm", &mlx_info->Collection, mlx_info);
	_nsx_new_gameobject("textures/door/door_open.xpm", &mlx_info->door_open, mlx_info);
	_nsx_new_gameobject("textures/door/door_close.xpm", &mlx_info->door_close, mlx_info);
	_nsx_new_gameobject("textures/box.xpm", &mlx_info->Box, mlx_info);
	_nsx_new_gameobject("textures/enemy.xpm", &mlx_info->Enemy, mlx_info);
}

void	_nsx_start_game(t_mlx	*mlx_data)
{
	_nsx_init_textures(mlx_data);
	_nsx_init_maps(mlx_data);
	mlx_hook(mlx_data->win_ptr, 17, 0, exitfunc, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_down, mlx_data);
	mlx_loop_hook(mlx_data->mlx_ptr, loop, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
