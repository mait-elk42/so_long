/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/12 12:31:36 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_get_fileinfo(char *filename, int *len, int *newfd)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		_nsx_exit("CAN'T OPN FL(so_long.c:L136)", -1, 'E');
	while (get_next_line(fd))
		i++;
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		_nsx_exit("CAN'T OPN FL(so_long.c:L142)", -1, 'E');
	*newfd = fd;
	*len = i;
}

void	get_maps(char *filename, char ***maps)
{
	int		fd;
	int		len;
	int		i;

	_nsx_get_fileinfo(filename, &len, &fd);
	*maps = malloc((len * sizeof(char *)) + 1);
	if (!*maps)
		_nsx_exit("CAN'T ALLOC Mm(so_long.c, L144)", -1, 'E');
	i = 0;
	while (i < len)
	{
		(*maps)[i] = get_next_line(fd);
		if (!(*maps)[i])
			_nsx_invalid_maps();
		i++;
	}
	(*maps)[i] = 0;
	close(fd);
}


int	main(int ac, char **av)
{
	t_mlx	m_data;

	_nsx_check_args(ac, av);
	get_maps(av[1], &m_data.maps);
	check_maps(m_data.maps, &m_data.win_x, &m_data.win_y);
	m_data.mlx_ptr = mlx_init();
	if (!m_data.mlx_ptr)
		_nsx_exit("MLX Can't Init The Connection Fso_long.c L66", -1, 'E');
	m_data.win_ptr = mlx_new_window(m_data.mlx_ptr, m_data.win_x * OBJ_SCALE, m_data.win_y * OBJ_SCALE, "GAME");
	if (!m_data.mlx_ptr)
		_nsx_exit("MLX Can't Init The Window Fso_long.c L69", -1, 'E');
	_nsx_start_game(&m_data);
	return (0);
}
