/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:54:57 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 23:12:20 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	_nsx_flood_fill(t_mlx *mlx_info, int x, int y)
{
	if (x < 0 || y < 0 || mlx_info->maps[y][x] == '1')
		return (0);
	ft_printf("%c\n", mlx_info->maps[y][x]);
	// mlx_info->maps[y][x] = 'F';
	_nsx_flood_fill(mlx_info, x - 1, y);
	// _nsx_flood_fill(mlx_info, x + 1, y);
	// _nsx_flood_fill(mlx_info, x, y - 1);
	// _nsx_flood_fill(mlx_info, x, y + 1);
	return (0);
}