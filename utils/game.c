/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 21:57:23 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_paint_sprite(t_mlx *mlx_info, char *base_texture, t_vect2 pos)
{
	t_nsx_Gobject	img;

	_nsx_new_gameobject(base_texture, &img, mlx_info);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, img.sprite, pos.x, pos.y);
	free(img.sprite);
}

void	_nsx_paint_line(t_mlx *mlx_info, int y, int i)
{
	int				max_x;
	int				x;

	x = OBJ_SCALE;
	max_x = OBJ_SCALE * mlx_info->win_x;
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->world[i].sprite, 0, y);
	while (x < max_x-OBJ_SCALE)
	{
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->world[i+1].sprite, x, y);
		x+= OBJ_SCALE;
	}
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->world[i+2].sprite, x, y);
}

void	_nsx_free_world(t_mlx *mlx_info)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		free(mlx_info->world[i].sprite);
		mlx_info->world[i].sprite = 0;
		i++;
	}
	free(mlx_info->world);
}

void	_nsx_alloc_world(t_mlx *mlx_info)
{
	char	*base_texture;
	int		i;

	base_texture = _nsx_p_malloc(26);
	i = 0;
	ft_memcpy(base_texture, "textures/tiles/tile00.xpm", 25);
	mlx_info->world = _nsx_p_malloc(sizeof(t_nsx_Gobject) * 9);
	while (i < 9)
	{
		_nsx_new_gameobject(base_texture, &mlx_info->world[i], mlx_info);
		base_texture[20]++;
		i++;
	}
	free(base_texture);
}

void	_nsx_print_maps(t_mlx *mlx_info)
{
	int		y;
	int		max_y;

	y = OBJ_SCALE;
	max_y = mlx_info->win_y * OBJ_SCALE;
	_nsx_alloc_world(mlx_info);
	_nsx_paint_line(mlx_info, 0, 0);
	while (y < max_y - OBJ_SCALE)
	{
		_nsx_paint_line(mlx_info, y, 3);
		y+=OBJ_SCALE;
	}
	_nsx_paint_line(mlx_info, y, 6);
	_nsx_free_world(mlx_info);
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
					_initialize_vect(&mlx_info->door.doorpos, i.x, i.y);
			// if (mlx_info->maps[i.y][i.x] == 'E' && mlx_info->Coll_Goal == mlx_info->player.Coll_n)
			// 		_nsx_exit("YOU WIN ! ", 0, 0);
			i.x++;
		}
		i.y++;
	}
}


void	_nsx_start_game(t_mlx	*mlx_data)
{
	_nsx_new_gameobject("textures/tiles/tile04.xpm", &mlx_data->Floor, mlx_data);
	_nsx_new_gameobject("textures/tiles/sboard.xpm", &mlx_data->Score_Board, mlx_data);
	_nsx_new_gameobject("textures/foods/food0.xpm", &mlx_data->Collection, mlx_data);
	_nsx_new_gameobject("textures/door/door_open.xpm", &mlx_data->door.door_open, mlx_data);
	_nsx_new_gameobject("textures/door/door_close.xpm", &mlx_data->door.door_close, mlx_data);
	_nsx_new_player("textures/player/plr_idle.xpm", &mlx_data->player, mlx_data);
	mlx_hook(mlx_data->win_ptr, 17, 0, exitfunc, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 0, key_down, mlx_data);
	mlx_loop_hook(mlx_data->mlx_ptr, loop, mlx_data);
	mlx_data->Coll_Goal = 0;
	mlx_data->door_locked = 1;
	mlx_data->printed = 0;
	mlx_data->player.steps_count = 0;
	_nsx_get_player_pos(mlx_data);
	_nsx_print_maps(mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
