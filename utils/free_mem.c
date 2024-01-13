/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:15 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/13 16:02:49 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_free_all(t_mlx *mlx_info)
{
	free(mlx_info->mlx_ptr);
	// while (mlx_info->objects)
	// {
	// 	free(mlx_info->objects);
	// 	mlx_info->objects++;		
	// }
}