/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/19 23:42:23 by mait-elk         ###   ########.fr       */
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
		i++;
	}
	maps[i] = 0;
	close(fd);
	return (maps);
}

void	_nsx_init_vars(t_mlx *mlx_info)
{
	_nsx_new_gameobject("textures/player_down.xpm", &mlx_info->player, mlx_info);
	_nsx_new_gameobject("textures/tiles/tile04.xpm", &mlx_info->Floor, mlx_info);
	_nsx_new_gameobject("textures/tiles/sboard.xpm", &mlx_info->Score_Board, mlx_info);
	_nsx_new_gameobject("textures/foods/food0.xpm", &mlx_info->Collection, mlx_info);
	_nsx_new_gameobject("textures/door/door_open.xpm", &mlx_info->door_open, mlx_info);
	_nsx_new_gameobject("textures/door/door_close.xpm", &mlx_info->door_close, mlx_info);
	_nsx_new_gameobject("textures/box.xpm", &mlx_info->Box, mlx_info);
	// _nsx_new_gameobject("textures/enemy.xpm", &mlx_info->Enemy, mlx_info);
	mlx_info->P_Coll_n = 0;
	mlx_info->Coll_Goal = 0;
	mlx_info->door_locked = 1;
	mlx_info->P_steps_count = 0;
}

void	_nsx_flood_fill_help(t_mlx *mlx_info, char *mapsfile)
{
	char		**cpmaps;
	t_ff_check	result;

	cpmaps = get_maps(mapsfile);
	result.c = 0;
	result.e = 0;
	_nsx_flood_fill(cpmaps, mlx_info->player.pos.x, mlx_info->player.pos.y, &result);
	_nsx_free_2d(cpmaps);
	if (result.c == mlx_info->Coll_Goal && result.e)
		ft_printf("valiiid\n");
	else
		_nsx_exit("INVALID PATH!!", -1, 'E');
}

int	main(int ac, char **av)
{
	t_mlx	mlx_info;

	_nsx_check_extension_args(ac, av);
	mlx_info.maps = get_maps(av[1]);
	mlx_info.mlx_ptr = mlx_init();
	if (!mlx_info.mlx_ptr)
		_nsx_exit("MLX Can't Init The Connection", -1, 'E');
	_nsx_init_vars(&mlx_info);
	check_maps(&mlx_info);
	_nsx_flood_fill_help(&mlx_info, av[1]);

	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, mlx_info.window_size.x * OBJ_SCALE, mlx_info.window_size.y * OBJ_SCALE, "so_long<mait-elk>");
	if (!mlx_info.mlx_ptr)
		_nsx_exit("MLX Can't Create The Window", -1, 'E');
	_nsx_start_game(&mlx_info);
	return (0);
}
