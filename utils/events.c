/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 22:53:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_down(int keycode, t_mlx *mlx_info)
{
	t_vect2	newpos;

	if (keycode == K_ESC)
		_nsx_game_closed(mlx_info);
	newpos = mlx_info->player.pos;
	newpos.y -= (keycode == K_W || keycode == K_ARROW_UP);
	newpos.y += (keycode == K_S || keycode == K_ARROW_DOWN);
	newpos.x -= (keycode == K_A || keycode == K_ARROW_LEFT);
	newpos.x += (keycode == K_D || keycode == K_ARROW_RIGHT);
	if ((keycode == K_W || keycode == K_ARROW_UP))
		_move_to(mlx_info, newpos, _nsx_xpm(mlx_info, P_up));
	if ((keycode == K_S || keycode == K_ARROW_DOWN))
		_move_to(mlx_info, newpos, _nsx_xpm(mlx_info, P_down));
	if ((keycode == K_A || keycode == K_ARROW_LEFT))
		_move_to(mlx_info, newpos, _nsx_xpm(mlx_info, P_left));
	if ((keycode == K_D || keycode == K_ARROW_RIGHT))
		_move_to(mlx_info, newpos, _nsx_xpm(mlx_info, P_right));
	return (0);
}

int	exitfunc(t_mlx *mlx_info)
{
	_nsx_game_closed(mlx_info);
	return (0);
}

int	loop(t_mlx *mlx_info)
{
	// t_nsx_Gobject			oldplace;
	// static _nsx_direction	bomb_direction;
	// static t_vect2 			dir;
	// static t_vect2 			targ;
	// static int 				going;
	// static int				n;
	// static int				player_dead;

	(void)mlx_info;
	// if (mlx_info->Enemies_count > 0 && !player_dead)
	// {
	// 	if (n < 500)
	// 		n++;
	// 	else
	// 	{
	// 		n = 0;
	// 		if (mlx_info->player.pos.y == mlx_info->Enemy.pos.y || mlx_info->player.pos.x == mlx_info->Enemy.pos.x || going)
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
	// 	}
	// }
	return (0);
}
