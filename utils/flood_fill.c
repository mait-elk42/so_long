/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:54:57 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 12:21:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	_nsx_flood_fill(char **maps, int x, int y, t_ff_check *res)
{
	if (x < 0 || y < 0 || maps[y][x] == '1' ||
		maps[y][x] == 'F')
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
