/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/13 23:25:55 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_valid_block(char c)
{
	if (c != 'P' && c != 'E' && c != '0' && c != '1' && c != 'C' && c != 'e')
		_nsx_invalid_maps();
}

int	_nsx_valid_wall(int x, int y, int xlen, int ylen)
{
	return (y == 0 || y == ylen - 1 || x == 0 || x == xlen - 1);
}

void	_nsx_check_last(char **maps, int *xlen, int *ylen)
{
	*xlen = 0;
	*ylen = 0;
	if (!maps || !maps[0] || !maps[0][0])
		_nsx_invalid_maps();
	while (maps[*ylen])
		(*ylen)++;
	while (maps[0][*xlen] && maps[0][*xlen] != '\n')
		(*xlen)++;
	if (*ylen == *xlen || maps[*ylen - 1][*xlen] == '\n')
		_nsx_invalid_maps();
}

void	check_maps(t_mlx *mlx_info)
{
	char	**maps;
	t_vect2	xy;
	t_vect2	xy_len;

	_initialize_vect(&xy, 0, 0);
	maps = mlx_info->maps;
	_nsx_check_last(maps, &mlx_info->win_x, &mlx_info->win_y);
	_initialize_vect(&xy_len, mlx_info->win_x, mlx_info->win_y);
	while (maps[xy.y])
	{
		xy.x = 0;
		while (maps[xy.y][xy.x] && maps[xy.y][xy.x] != '\n')
		{
			_nsx_valid_block(maps[xy.y][xy.x]);
			if (_nsx_valid_wall(xy.x, xy.y, xy_len.x, xy_len.y) && maps[xy.y][xy.x] != '1')
				_nsx_invalid_maps();
			xy.x++;
		}
		if (xy.x != xy_len.x)
			_nsx_invalid_maps();
		xy.y++;
	}
}
