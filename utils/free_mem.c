/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:15 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/19 22:54:30 by mait-elk         ###   ########.fr       */
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

void	_nsx_free_2d(char	**arr2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!arr2d)
		return ;
	while (arr2d[i])
	{
		j = 0;
		while (arr2d[i][j])
		{
			arr2d[i][j] = '\0';
			j++;
		}
		free(arr2d[i]);
		i++;
	}
	free(arr2d);
}