/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 23:00:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_nsx_is_wall(t_vect2 xy, t_vect2 xy_len)
{
	return (!xy.y || xy.y == xy_len.y - 1 || !xy.x || xy.x == xy_len.x - 1);
}

void	_nsx_is_rectangle(char **maps, int *xlen, int *ylen)
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
	t_vect2	xy_len;
	t_vect2	xy;

	_initialize_vect(&xy, 0, 0);
	maps = mlx_info->maps;
	_nsx_is_rectangle(maps, &mlx_info->win_x, &mlx_info->win_y);
	_initialize_vect(&xy_len, mlx_info->win_x, mlx_info->win_y);
	while (maps[xy.y])
	{
		xy.x = 0;
		while (maps[xy.y][xy.x] && maps[xy.y][xy.x] != '\n')
		{
			if ((_nsx_is_wall(xy, xy_len) && maps[xy.y][xy.x] != '1')
				|| !ft_strchr("01PEC", maps[xy.y][xy.x]))
				_nsx_invalid_maps();
			xy.x++;
		}
		if (xy.x != xy_len.x)
			_nsx_invalid_maps();
		xy.y++;
	}
}
