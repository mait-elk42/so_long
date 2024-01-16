/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:40:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 17:12:52 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_draw_image(t_mlx *mlx_info, t_vect2 pos, t_nsx_Gobject texture)
{
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr,
		texture.sprite, pos.x * OBJ_SCALE, pos.y * OBJ_SCALE);
}

void	_nsx_draw_str(t_mlx *mlx_info, t_vect2 pos, char *s)
{
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
		pos.x, pos.y, -1, s);
}

void	_nsx_show_score(t_mlx *mlx_info)
{
	char	*s;

	s = ft_itoa(mlx_info->P_steps_count);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 0, 0, -1, s);
}
