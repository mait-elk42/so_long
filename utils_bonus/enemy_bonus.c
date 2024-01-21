/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:15:32 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 21:19:32 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_enemy_init_dir(t_vect2 *dir, t_nsx_dir bomb_dir)
{
	dir->x -= (bomb_dir == LEFT);
	dir->x += (bomb_dir == RIGHT);
	dir->y -= (bomb_dir == UP);
	dir->y += (bomb_dir == DOWN);
}

t_nsx_dir	_nsx_enemy_mv_dir(t_vect2 *dir, t_vect2 *targ, t_mlx *m)
{
	*dir = m->doorpos;
	*targ = m->plrpos;
	if (dir->x > targ->x && dir->y == targ->y)
	{
		targ->x = 1;
		return (LEFT);
	}
	if (dir->x < targ->x && dir->y == targ->y)
	{
		targ->x = m->window_size.x - 2;
		return (RIGHT);
	}
	if (dir->y < targ->y && dir->x == targ->x)
	{
		targ->y = m->window_size.y - 2;
		return (DOWN);
	}
	if (dir->y > targ->y && dir->x == targ->x)
	{
		targ->y = 1;
		return (UP);
	}
	return (None);
}
