/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:41:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 05:18:22 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx *m_data)
{
	gameobject->sprite = mlx_xpm_file_to_image(m_data->mlx_ptr, xpmfile, &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile(xpmfile);
	gameobject->pos = (t_vect2){0, 0};
}

void	_nsx_new_player(t_nsx_Gplayer *gameobject, t_mlx *m_data)
{
	gameobject->sprite_up = mlx_xpm_file_to_image(m_data->mlx_ptr, "textures/player_up.xpm", &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile("textures/player_up.xpm");
	gameobject->sprite_down = mlx_xpm_file_to_image(m_data->mlx_ptr, "textures/player_down.xpm", &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile("textures/player_down.xpm");
	gameobject->sprite_left = mlx_xpm_file_to_image(m_data->mlx_ptr, "textures/player_left.xpm", &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile("textures/player_left.xpm");
	gameobject->sprite_right = mlx_xpm_file_to_image(m_data->mlx_ptr, "textures/player_right.xpm", &gameobject->sp_xsize, &gameobject->sp_ysize);
	if (!gameobject->sprite)
		_nsx_invalid_xpmfile("textures/player_right.xpm");
	gameobject->pos = (t_vect2){0, 0};
}
