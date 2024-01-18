/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 23:01:30 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_nsx_get_filelines(char *filename)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = _nsx_p_open(filename);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**get_maps(char *filename)
{
	char	**maps;
	int		fd;
	int		len;
	int		i;

	i = 0;
	fd = _nsx_p_open(filename);
	len = _nsx_get_filelines(filename);
	maps = _nsx_p_malloc((len + 1) * sizeof(char *));
	while (i < len)
	{
		maps[i] = get_next_line(fd);
		if (!maps[i])
		{
			while (i--)
				free(maps[i]);
			free(maps);
			_nsx_invalid_maps();
		}
		i++;
	}
	maps[i] = 0;
	close(fd);
	return (maps);
}


int	main(int ac, char **av)
{
	t_mlx	mlx_info;

	_nsx_check_extension_args(ac, av);
	mlx_info.maps = get_maps(av[1]);
	check_maps(&mlx_info);
	mlx_info.mlx_ptr = mlx_init();
	if (!mlx_info.mlx_ptr)
		_nsx_exit("MLX Can't Init The Connection", -1, 'E');
	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, mlx_info.win_x * OBJ_SCALE, mlx_info.win_y * OBJ_SCALE, "GAME");
	if (!mlx_info.mlx_ptr)
		_nsx_exit("MLX Can't Create The Window", -1, 'E');
	mlx_info.doorpos.x = 0;
	_nsx_start_game(&mlx_info);
	return (0);
}
