/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:54:57 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 02:17:37 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	_nsx_flood_fill(char **maps, int x, int y, t_ff_check *res)
{
	if (maps[y][x] == '1' || maps[y][x] == 'F')
		return (0);
	if (maps[y][x] == 'E')
	{
		res->e = 1;
		return (0);
	}
	if (maps[y][x] == 'C')
		res->c++;
	maps[y][x] = 'F';
	_nsx_flood_fill(maps, x - 1, y, res);
	_nsx_flood_fill(maps, x, y - 1, res);
	_nsx_flood_fill(maps, x + 1, y, res);
	_nsx_flood_fill(maps, x, y + 1, res);
	return (0);
}

void	_nsx_flood_fill_help(t_mlx *mlx_info, char *mapsfile)
{
	t_ff_check	result;
	char		**cpmaps;

	cpmaps = _nsx_read_maps(mapsfile);
	result.c = 0;
	result.e = 0;
	_nsx_flood_fill(cpmaps, mlx_info->plrpos.x,
		mlx_info->plrpos.y, &result);
	_nsx_free_2d(cpmaps);
	if (result.c != mlx_info->coll_goal || !result.e)
		_nsx_invalid_maps();
}
