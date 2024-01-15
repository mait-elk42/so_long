/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 14:11:32 by mait-elk         ###   ########.fr       */
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

void	_nsx_paint_line(t_mlx *mlx_info, char *base_texture, int y, int i)
{
	int				max_x;
	int				x;

	x = OBJ_SCALE;
	max_x = OBJ_SCALE * mlx_info->win_x;
	base_texture[20] = i;
	_nsx_paint_sprite(mlx_info, base_texture, (t_vect2){0, y});
	base_texture[20]= i+1;
	while (x < max_x-OBJ_SCALE)
	{
		_nsx_paint_sprite(mlx_info, base_texture, (t_vect2){x, y});
		x+= OBJ_SCALE;
	}
	base_texture[20] = i+2;
	_nsx_paint_sprite(mlx_info, base_texture, (t_vect2){x, y});
}

void	_nsx_print_maps(t_mlx *mlx_info)
{
	char	*base_texture;
	int		y;
	int		max_y;

	y = OBJ_SCALE;
	max_y = mlx_info->win_y * OBJ_SCALE;
	base_texture = _nsx_p_malloc(26);
	//FIX THIS 
	ft_memcpy(base_texture, "textures/tiles/tile00.xpm", 25);
	_nsx_paint_line(mlx_info, base_texture, 0, '0');
	while (y < max_y - OBJ_SCALE)
	{
		_nsx_paint_line(mlx_info, base_texture, y, '3');
		y+=OBJ_SCALE;
	}
	_nsx_paint_line(mlx_info, base_texture, y, '6');
	free(base_texture);
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
	_nsx_new_gameobject("textures/tiles/tile04.xpm", mlx_data->Floor, mlx_data);
	_nsx_new_gameobject("textures/foods/food2.xpm", &mlx_data->objects[10], mlx_data);
	_nsx_new_gameobject("textures/door/door0.xpm", &mlx_data->objects[11], mlx_data);
	_nsx_new_gameobject("textures/door/door1.xpm", &mlx_data->objects[12], mlx_data);
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
