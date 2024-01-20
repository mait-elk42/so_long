/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:15 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 19:22:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_free_all(t_mlx *mlx_info)
{
	(void)mlx_info;
	// mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->Collection.sprite);
	// free(mlx_info->Collection.sprite);
	// mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->door_open.sprite);
	// // free(mlx_info->door_open.sprite);
	// mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->door_close.sprite);
	// // free(mlx_info->door_close.sprite);
	// mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->player.sprite);
	// // free(mlx_info->player.sprite);
	// mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->Score_Board.sprite);
	// // free(mlx_info->Score_Board.sprite);
	// free(mlx_info->mlx_ptr);
}

void	_nsx_free_2d(char	**arr2d)
{
	int	i;

	i = 0;
	if (!arr2d)
		return ;
	while (arr2d[i])
	{
		free(arr2d[i]);
		i++;
	}
	free(arr2d);
}