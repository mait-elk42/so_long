/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:08:42 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 20:19:50 by mait-elk         ###   ########.fr       */
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
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile00.xpm");
			else if (i.x == j.x - 1 && i.y == 0)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile02.xpm");
			else if (i.x == 0 && i.y == j.y - 1)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile06.xpm");
			else if (i.x == j.x - 1 && i.y == j.y - 1)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile08.xpm");
			else if (i.x > 0 && i.x < j.x - 1 && i.y == 0)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile01.xpm");
			else if (i.x > 0 && i.x < j.x - 1 && i.y == j.y - 1)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile07.xpm");
			else if (i.y > 0 && i.y < j.y - 1 && i.x == 0)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile03.xpm");
			else if (i.y > 0 && i.y < j.y - 1 && i.x == j.x - 1)
				_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile05.xpm");
			else
				_nsx_draw_xpm(mlx_info, i, "textures/box.xpm");
		}
}

void	_nsx_miniapi(t_vect2 i, t_mlx *mlx_info, char c)
{
	if (ft_strchr("0ECP", c))
		_nsx_draw_xpm(mlx_info, i, "textures/tiles/tile04.xpm");
	if (c == 'C')
		_nsx_draw_xpm(mlx_info, i, "textures/foods/food0.xpm");
	if (c == 'P')
		_nsx_draw_xpm(mlx_info, i, "textures/player_down.xpm");
	if (c == 'E')
		_nsx_draw_xpm(mlx_info, i, "textures/door_close.xpm");
}

void	_nsx_init_maps(t_mlx *mlx_info)
{
	char	**maps;
	t_vect2	i;
	t_vect2	j;

	maps = mlx_info->maps;
	_nsx_initialize_vect(&i, 0, 0);
	j = mlx_info->window_size;
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

void	_nsx_start_game(t_mlx	*mlx_info)
{
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr,
		mlx_info->window_size.x * OBJ_SCALE,
		mlx_info->window_size.y * OBJ_SCALE, "so_long<mait-elk>");
	if (!mlx_info->mlx_ptr)
		_nsx_exit("MLX Can't Create The Window", -1, 'E');
	_nsx_init_maps(mlx_info);
	mlx_hook(mlx_info->win_ptr, 17, 0, _nsx_exitfunc, mlx_info);
	mlx_hook(mlx_info->win_ptr, 2, 0, _nsx_key_down, mlx_info);
	mlx_loop_hook(mlx_info->mlx_ptr, _nsx_loop, mlx_info);
	mlx_loop(mlx_info->mlx_ptr);
}
