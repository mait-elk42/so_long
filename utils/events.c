/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 23:00:33 by mait-elk         ###   ########.fr       */
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
	_nsx_game_closed(mlx_info);
	return (0);
}

int	loop(t_mlx *mlx_info)
{
	static t_vect2	i;
	static int	init;
	static int	n;

	if (mlx_info->Enemies_count)
	{
		if (!init)
		{
			_initialize_vect(&i, mlx_info->Enemy.pos.x, mlx_info->Enemy.pos.y);
			init = 1;
		}
		if (n < 5000)
		{
			ft_printf("{%d}\n", i.x);
			n++;
		}
		else
		{
			n = 0;
			if (mlx_info->player.pos.x < i.x && mlx_info->maps[i.y][i.x-1] != '1')
				i.x--;
			else
			if (mlx_info->player.pos.x > i.x && mlx_info->maps[i.y][i.x+1] != '1')
				i.x++;
			if (mlx_info->player.pos.y < i.y && mlx_info->maps[i.y-1][i.x] != '1')
				i.y--;
			else
			if (mlx_info->player.pos.y > i.y && mlx_info->maps[i.y+1][i.x] != '1')
				i.y++;
			if (ft_strchr("1EC", mlx_info->maps[mlx_info->Enemy.pos.y][mlx_info->Enemy.pos.x]))
				_nsx_draw_image(mlx_info, mlx_info->Enemy.pos, mlx_info->Floor);
			if (mlx_info->maps[mlx_info->Enemy.pos.y][mlx_info->Enemy.pos.x] == '1')
				_nsx_draw_image(mlx_info, mlx_info->Enemy.pos, mlx_info->Box);
			else
			if (mlx_info->maps[mlx_info->Enemy.pos.y][mlx_info->Enemy.pos.x] == 'E')
				_nsx_draw_image(mlx_info, mlx_info->Enemy.pos, mlx_info->door_close);
			else
			if (mlx_info->maps[mlx_info->Enemy.pos.y][mlx_info->Enemy.pos.x] == 'C')
				_nsx_draw_image(mlx_info, mlx_info->Enemy.pos, mlx_info->Collection);
			else
				_nsx_draw_image(mlx_info, mlx_info->Enemy.pos, mlx_info->Floor);
			_nsx_draw_image(mlx_info, i, mlx_info->Enemy);
			mlx_info->Enemy.pos = i;
		}
	}
	return (0);
}
