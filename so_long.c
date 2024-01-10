/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:18:59 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/10 20:33:09 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exitfunc(t_mlx_ *mlx_info)
{
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	ft_printf("\n%s\n", "DESTROYED");
	exit (0);
}

void	_painter_api(t_mlx_ *mlx_info, t_vect2 step, t_vect2 pos)
{
	// char c;

	// c = mlx_info->maps[pos.y][pos.x];
	// (void)c;
	// if (c == '1' && (step.x == 0 || step.y == 0 || pos.x == mlx_info->win_x-1 || pos.y == mlx_info->win_y-1))
	if (pos.x == 0 && pos.y == 0)
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[0].sprite , step.x, step.y);
	else if (pos.x == mlx_info->win_x-1 && pos.y == 0)
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[2].sprite , step.x, step.y);
	else if (pos.y == 0 || pos.y == mlx_info->win_y)
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[1].sprite , step.x, step.y);
	else
		mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->objects[0].sprite , step.x, step.y);
}

int	loop(t_mlx_ *mlx_info)
{
	t_vect2	step;
	t_vect2	pos;
	t_vect2	max;

	_initialize_vect(&step, 0, 0);
	_initialize_vect(&pos, 0, 0);
	_initialize_vect(&max, mlx_info->win_x, mlx_info->win_y);
	mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	while (pos.y < max.y)
	{
		pos.x = 0;
		step.x = 0;
		while (pos.x < max.x)
		{
			_painter_api(mlx_info, step, pos);
			pos.x++;
			step.x += OBJ_SCALE;
		}
		pos.y++;
		step.y += OBJ_SCALE;
	}
	return (0);
}

int	key_down(int keycode, t_mlx_ *mlx_info)
{
	(void)mlx_info;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
		exit (0);
	}
	return (0);
}

int	get_file_linescount(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd))
	{
		i++;
	}
	close(fd);
	return (i);
}

char	**get_maps(char *filename)
{
	char	**res;
	int		fd;
	int		len;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	len = get_file_linescount(filename);
	if (len == -1)
		return (0);
	res = malloc((len * sizeof(char *)) + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = get_next_line(fd);
		if (!res[i])
			return (0);
		i++;
	}
	res[i] = 0;
	close(fd);
	return (res);
}

void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx_ *m_data)
{
	gameobject->sprite = mlx_xpm_file_to_image(m_data->mlx_ptr, xpmfile, &gameobject->x, &gameobject->y);
}

int	main(int ac, char **av)
{
	t_mlx_	m_data;
	char		**maps;
	int			WIN_X;
	int			WIN_Y;

	if (ac != 2)
		return (-1);
	maps = get_maps(av[1]);
	check_maps(maps, &WIN_X, &WIN_Y);
	m_data.mlx_ptr = mlx_init();
	m_data.win_x = WIN_X;
	m_data.win_y = WIN_Y;
	m_data.win_ptr = mlx_new_window(m_data.mlx_ptr, WIN_X * OBJ_SCALE, WIN_Y * OBJ_SCALE, "GAME");
	m_data.maps = maps;
	m_data.objects = malloc(sizeof(t_nsx_Gobject) * 9);
	_nsx_new_gameobject("sprites/tile00.xpm", &m_data.objects[0], &m_data);
	_nsx_new_gameobject("sprites/tile01.xpm", &m_data.objects[1], &m_data);
	_nsx_new_gameobject("sprites/tile02.xpm", &m_data.objects[2], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[3], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[4], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[5], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[6], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[7], &m_data);
	_nsx_new_gameobject("sprites/tile03.xpm", &m_data.objects[8], &m_data);
	mlx_hook(m_data.win_ptr, 17, 0, exitfunc, &m_data);
	mlx_hook(m_data.win_ptr, 2, 0, key_down, &m_data);
	mlx_loop_hook(m_data.mlx_ptr, loop, &m_data);
	mlx_loop(m_data.mlx_ptr);
	return (0);
}
