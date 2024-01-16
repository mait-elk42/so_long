/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:15 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/16 18:33:14 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_free_all(t_mlx *mlx_info)
{
	free(mlx_info->mlx_ptr);
	free(mlx_info->Collection.sprite);
	free(mlx_info->door_open.sprite);
	free(mlx_info->door_close.sprite);
	free(mlx_info->player.sprite);
	free(mlx_info->Score_Board.sprite);
}