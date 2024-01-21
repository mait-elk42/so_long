/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:40:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 21:19:27 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_draw_xpm(t_mlx *mlx_info, t_vect2 pos, char *xpmfile)
{
	void	*texture;

	texture = _nsx_xpm(mlx_info, xpmfile);
	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr,
		texture, pos.x * OBJ_SCALE, pos.y * OBJ_SCALE);
	mlx_destroy_image(mlx_info->mlx_ptr, texture);
}

void	_nsx_show_score(t_mlx *mlx_info)
{
	t_vect2		pos;
	char		*s;

	_nsx_initialize_vect(&pos, 0, 0);
	s = ft_itoa(mlx_info->p_steps_count);
	_nsx_draw_xpm(mlx_info, pos, "textures/tiles/sboard.xpm");
	mlx_string_put(mlx_info->mlx_ptr,
		mlx_info->win_ptr, pos.x, pos.y, -1, s);
	ft_printf("%s\n", s);
	free(s);
}
