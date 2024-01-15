/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:36:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 19:43:26 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_invalid_maps(void)
{
	ft_printf("\033[31mError\n[ Invalid Maps!! ]\033[0m\n");
	exit(-1);
}

void	_nsx_invalid_xpmfile(char *fname)
{
	ft_printf("\033[31mError :\n[ Invalid Texture : %s ]\033[0m\n", fname);
	exit(-1);
}

void	_nsx_exit(char *last_msg, int status, char type)
{
	if (type == 'E')
		ft_printf("\033[31mError :\n[ %s ]\033[0m\n", last_msg);
	else
		ft_printf("\033[34mMessage :\n[ %s ]\033[0m\n", last_msg);
	exit(status);
}

void	_nsx_game_closed(t_mlx *mlx_info)
{
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	_nsx_free_all(mlx_info);
	_nsx_exit("Game Closed !", 0, 0);
	exit(0);
}

void	_nsx_Log(char *msg, char *about)
{
	ft_printf("\033[33mLog :\n[ %s %s ]\033[0m\n", msg, about);
}