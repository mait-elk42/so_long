/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:41:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 16:41:00 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx *m_data)
{
	_nsx_Log("Loading Texture :", xpmfile);
	gameobject->sprite = mlx_xpm_file_to_image(m_data->mlx_ptr, xpmfile, &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile(xpmfile);
	_nsx_Log("SUCCESS", xpmfile);
}
