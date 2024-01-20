/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 20:58:00 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	_nsx_key_down(int keycode, t_mlx *mlx_info)
{
	t_vect2	newpos;

	if (keycode == K_ESC)
		_nsx_game_closed(mlx_info);
	newpos = mlx_info->plrpos;
	newpos.y -= (keycode == K_W || keycode == K_ARROW_UP);
	newpos.y += (keycode == K_S || keycode == K_ARROW_DOWN);
	newpos.x -= (keycode == K_A || keycode == K_ARROW_LEFT);
	newpos.x += (keycode == K_D || keycode == K_ARROW_RIGHT);
	if ((keycode == K_W || keycode == K_ARROW_UP))
		_nsx_move_to(mlx_info, newpos, P_up);
	if ((keycode == K_S || keycode == K_ARROW_DOWN))
		_nsx_move_to(mlx_info, newpos, P_down);
	if ((keycode == K_A || keycode == K_ARROW_LEFT))
		_nsx_move_to(mlx_info, newpos, P_left);
	if ((keycode == K_D || keycode == K_ARROW_RIGHT))
		_nsx_move_to(mlx_info, newpos, P_right);
	return (0);
}

int	_nsx_exitfunc(t_mlx *mlx_info)
{
	_nsx_game_closed(mlx_info);
	return (0);
}

int	_nsx_loop(t_mlx *mlx_info)
{
	// static _nsx_direction	bomb_direction;
	static t_vect2 			dir;
	static t_vect2 			targ;
	static int 				going;
	static int				n;
	static int				player_dead;

	(void)mlx_info;
	if (!player_dead)
	{
		if (!going && mlx_info->plrpos.y == 1)
		{
			dir = mlx_info->doorpos;
			targ = mlx_info->plrpos;
			going = 1;
		}
		if (n < 1000)
		{
			n++;
		}
		else
		{
			
			n = 0;
			if (!going)
				return (0);
			if (dir.x < targ.x || going)
			{
				_nsx_draw_xpm(mlx_info, dir, "textures/tiles/tile04.xpm");
				dir.x++;
				_nsx_draw_xpm(mlx_info, dir, "textures/bomb.xpm");
			}
			if (dir.x >= targ.x)
			{
				_nsx_draw_xpm(mlx_info, dir, "textures/tiles/tile04.xpm");
				if (mlx_info->maps[targ.y][targ.x] == 'P')
					_nsx_exit("YOU LOOSE HH!", 0, 0);
				going = 0;
			}
	// 		{
	// 			if (!going)
	// 			{
	// 				dir = mlx_info->Enemy.pos;
	// 				targ = mlx_info->player.pos;
	// 				if (dir.x > targ.x)
	// 					bomb_direction = LEFT;
	// 				if (dir.x < targ.x)
	// 					bomb_direction = RIGHT;
	// 				if (dir.x == targ.x && dir.y < targ.y)
	// 					bomb_direction = DOWN;
	// 				if (dir.x == targ.x && dir.y > targ.y)
	// 					bomb_direction = UP;
	// 				going = 1;
	// 			}
	// 			oldplace = mlx_info->Floor;
	// 			if ((dir.x == targ.x && (bomb_direction == LEFT || bomb_direction == RIGHT)) || (dir.y == targ.y && (bomb_direction == UP || bomb_direction == DOWN)))
	// 			{
	// 				if (mlx_info->maps[dir.y][dir.x] == 'P')
	// 					_nsx_Log("PLAYER DEAD !", "");
	// 				_nsx_draw_image(mlx_info, targ, mlx_info->Floor);
	// 				going = 0;
	// 				bomb_direction = 0;
	// 				return (0);
	// 			}
	// 			_nsx_draw_image(mlx_info, dir, oldplace);
	// 			if (mlx_info->maps[dir.y][dir.x] == 'C')
	// 					oldplace = mlx_info->Collection;
	// 			else if (mlx_info->maps[dir.y][dir.x] == '1')
	// 					oldplace = mlx_info->Box;
	// 			else if (mlx_info->maps[dir.y][dir.x] == 'E' && mlx_info->door_locked)
	// 					oldplace = mlx_info->door_close;
	// 			else if (mlx_info->maps[dir.y][dir.x] == 'E')
	// 					oldplace = mlx_info->door_open;
	// 			else if (mlx_info->maps[dir.y][dir.x] == 'e')
	// 					oldplace = mlx_info->Enemy;
	// 			_nsx_draw_image(mlx_info, dir, oldplace);
	// 			dir.x -= (dir.x > targ.x && bomb_direction == LEFT);
	// 			dir.x += (dir.x < targ.x && bomb_direction == RIGHT);
	// 			dir.y += (dir.y < targ.y && bomb_direction == DOWN);
	// 			dir.y -= (dir.y > targ.y && bomb_direction == UP);
	// 			_nsx_draw_xpm(mlx_info, dir, "textures/bomb.xpm");
	// 			ft_printf("SENDING BOMB ! to (x%d y%d)\n", dir.x, dir.y);
	// 		}
		}
	}
	return (0);
}
