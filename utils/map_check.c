/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 20:15:49 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_nsx_is_wall(t_vect2 i, t_vect2 j)
{
	return (i.y == 0 || i.y == j.y - 1
		|| i.x == 0 || i.x == j.x - 1);
}

void	_nsx_is_rectangle(char **maps, t_vect2 *window_size)
{
	if (!maps || !maps[0] || !maps[0][0])
		_nsx_invalid_maps();
	while (maps[window_size->y])
		(window_size->y)++;
	while (maps[0][window_size->x] && maps[0][window_size->x] != '\n')
		(window_size->x)++;
	if (maps[window_size->y - 1][window_size->x] == '\n')
		_nsx_invalid_maps();
	if (window_size->y == window_size->x)
		_nsx_invalid_maps();
}

void	_nsx_mini_api_checker(t_vect2 i, t_mlx *mlx_info, int is_last)
{
	static int	players;
	static int	exits;

	if (!ft_strchr("01PEC", mlx_info->maps[i.y][i.x]))
		_nsx_invalid_maps();
	if (mlx_info->maps[i.y][i.x] == 'C')
		mlx_info->Coll_Goal++;
	if (mlx_info->maps[i.y][i.x] == 'P')
	{
		if (players >= 1)
			_nsx_invalid_maps();
		players++;
		_nsx_initialize_vect(&mlx_info->plrpos, i.x, i.y);
	}
	if (mlx_info->maps[i.y][i.x] == 'E')
	{
		if (exits >= 1)
			_nsx_invalid_maps();
		exits++;
		_nsx_initialize_vect(&mlx_info->doorpos, i.x, i.y);
	}
	if (is_last && (exits == 0 || players == 0 || mlx_info->Coll_Goal == 0))
		_nsx_invalid_maps();
}

void	_nsx_check_maps(t_mlx *mlx_info)
{
	t_vect2	i;
	t_vect2	j;

	_nsx_initialize_vect(&i, 0, 0);
	_nsx_is_rectangle(mlx_info->maps, &mlx_info->window_size);
	j = mlx_info->window_size;
	while (i.y < j.y)
	{
		i.x = 0;
		while (i.x < j.x)
		{
			if (_nsx_is_wall(i, j) && mlx_info->maps[i.y][i.x] != '1')
				_nsx_invalid_maps();
			_nsx_mini_api_checker(i, mlx_info,
				(i.y +1 == j.y && i.x +1 == j.x));
			i.x++;
		}
		if (i.x != j.x)
			_nsx_invalid_maps();
		i.y++;
	}
}
