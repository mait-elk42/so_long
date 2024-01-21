/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:15:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 20:53:16 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		_nsx_move_to(mlx_info, newpos, P_UP);
	if ((keycode == K_S || keycode == K_ARROW_DOWN))
		_nsx_move_to(mlx_info, newpos, P_DOWN);
	if ((keycode == K_A || keycode == K_ARROW_LEFT))
		_nsx_move_to(mlx_info, newpos, P_LEFT);
	if ((keycode == K_D || keycode == K_ARROW_RIGHT))
		_nsx_move_to(mlx_info, newpos, P_RIGHT);
	return (0);
}

int	_nsx_exitfunc(t_mlx *mlx_info)
{
	_nsx_game_closed(mlx_info);
	return (0);
}

int	_nsx_loop(t_mlx *mlx_info)
{
	static t_nsx_dir		bomb_dir;
	static t_vect2			dir;
	static t_vect2			targ;
	static int				n;

	_nsx_loop_coin(mlx_info);
	if (!bomb_dir && _nsx_vv_eqor(mlx_info->plrpos, mlx_info->doorpos))
		bomb_dir = _nsx_enemy_mv_dir(&dir, &targ, mlx_info);
	if (dir.x == mlx_info->plrpos.x && dir.y == mlx_info->plrpos.y)
		_nsx_exit("YOU LOOSE!", 0, 0);
	if (n < 1000)
		return (n++, 0);
	n = 0;
	if (bomb_dir == None)
		return (0);
	if (dir.x == targ.x && dir.y == targ.y)
		(_nsx_auto_render(mlx_info, dir), bomb_dir = 0);
	if ((dir.x != targ.x && dir.y != targ.y) || bomb_dir)
	{
		_nsx_auto_render(mlx_info, dir);
		_nsx_enemy_init_dir(&dir, bomb_dir);
		_nsx_draw_xpm(mlx_info, dir, "textures/bomb.xpm");
	}
	return (0);
}

int	_nsx_loop_coin(t_mlx *mlx_info)
{
	static int	i;
	static int	f;
	t_vect2		pos;

	_nsx_initialize_vect(&pos, 0, 0);
	if (i < 1000)
		return (i++, 0);
	while (mlx_info->maps[pos.y])
	{
		pos.x = 0;
		while (mlx_info->maps[pos.y][pos.x])
		{
			if (mlx_info->maps[pos.y][pos.x] == 'C')
				_nsx_putcoin_nextframe(mlx_info, pos, f);
			pos.x++;
		}
		pos.y++;
	}
	f++;
	if (f == 8)
		f = 0;
	i = 0;
	return (0);
}
