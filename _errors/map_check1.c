/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:45:34 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/10 14:36:22 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_valid_block(char c)
{
	if (c != 'P' && c != 'E'
		&& c != '0' && c != '1')
		_invalid_maps();
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
		_invalid_maps();
	while (maps[*ylen])
		(*ylen)++;
	while (maps[0][*xlen] && maps[0][*xlen] != '\n')
		(*xlen)++;
	if (*ylen == *xlen || maps[*ylen - 1][*xlen] == '\n')
		_invalid_maps();
}

void	check_maps(char **maps, int *WIN_X, int *WIN_Y)
{
	int	x;
	int	y;
	int	xlen;
	int	ylen;

	y = 0;
	_nsx_check_last(maps, &xlen, &ylen);
	*WIN_X = xlen;
	*WIN_Y = ylen;
	while (maps[y])
	{
		x = 0;
		while (maps[y][x] && maps[y][x] != '\n')
		{
			_nsx_valid_block(maps[y][x]);
			if (_nsx_valid_wall(x, y, xlen, ylen) && maps[y][x] != '1')
				_invalid_maps();
			x++;
		}
		if (x != xlen)
			_invalid_maps();
		y++;
	}
}
