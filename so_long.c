/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 19:00:20 by mait-elk         ###   ########.fr       */
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
		free(line);
		line = get_next_line(fd);
		i++;
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
	t_mlx	m_data;

	_nsx_check_extension_args(ac, av);
	m_data.maps = get_maps(av[1]);
	check_maps(&m_data);
	m_data.mlx_ptr = mlx_init();
	if (!m_data.mlx_ptr)
		_nsx_exit("MLX Can't Init The Connection Fso_long.c L66", -1, 'E');
	m_data.win_ptr = mlx_new_window(m_data.mlx_ptr, m_data.win_x * OBJ_SCALE, m_data.win_y * OBJ_SCALE, "GAME");
	if (!m_data.mlx_ptr)
		_nsx_exit("MLX Can't Init The Window Fso_long.c L69", -1, 'E');
	_nsx_start_game(&m_data);
	return (0);
}
