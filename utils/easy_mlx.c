/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:40:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/22 00:10:11 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_draw_xpm(t_mlx *mlx_info, t_vect2 pos, char *xpmfile)
{
	void	*texture;

	texture = _nsx_xpm(mlx_info, xpmfile);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr,
		texture, pos.x * OBJ_SCALE, pos.y * OBJ_SCALE);
	mlx_destroy_image(mlx_info->mlx_ptr, texture);
}
