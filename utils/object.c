/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:41:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 04:26:53 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_new_obj(char *xpmfile, t_nsx_gobject *obj, t_mlx *m_data)
{
	obj->sprite = mlx_xpm_file_to_image(m_data->mlx_ptr,
			xpmfile, &obj->sp_xsize, &obj->sp_ysize);
	if (!obj->sprite)
		_nsx_invalid_xpmfile(xpmfile);
	obj->pos = (t_vect2){0, 0};
}
