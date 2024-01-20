/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/20 20:19:36 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_init_vars(t_mlx *mlx_info)
{
	mlx_info->P_Coll_n = 0;
	mlx_info->Coll_Goal = 0;
	mlx_info->door_locked = 1;
	mlx_info->P_steps_count = 0;
	_nsx_initialize_vect(&mlx_info->window_size, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx_info;

	_nsx_check_extension_args(ac, av);
	mlx_info.maps = _nsx_read_maps(av[1]);
	mlx_info.mlx_ptr = mlx_init();
	if (!mlx_info.mlx_ptr)
		_nsx_exit("MLX Can't Init The Connection", -1, 'E');
	_nsx_init_vars(&mlx_info);
	_nsx_check_maps(&mlx_info);
	_nsx_flood_fill_help(&mlx_info, av[1]);
	_nsx_start_game(&mlx_info);
	return (0);
}
