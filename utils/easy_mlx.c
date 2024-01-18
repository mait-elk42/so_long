/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:40:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 05:11:36 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_draw_image(t_mlx *mlx_info, t_vect2 pos, void *texture)
{
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr,
		texture, pos.x * OBJ_SCALE, pos.y * OBJ_SCALE);
}

void	_nsx_draw_xpm(t_mlx *mlx_info, t_vect2 pos, char *xpmfile)
{
	void	*texture;
	t_vect2	size;

	texture = mlx_xpm_file_to_image(mlx_info->mlx_ptr, xpmfile, &size.x, &size.y);
	if (!texture)
		_nsx_invalid_xpmfile(xpmfile);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr,
		texture, pos.x * OBJ_SCALE, pos.y * OBJ_SCALE);
	free(texture);
}

void	_nsx_show_score(t_mlx *mlx_info)
{
	char	*s;

	s = ft_itoa(mlx_info->P_steps_count);
	_nsx_draw_image(mlx_info, (t_vect2){0, 0}, mlx_info->Score_Board.sprite);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 0, 0, -1, s);
}
