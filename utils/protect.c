/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:17:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 02:39:48 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*_nsx_p_malloc(int size)
{
	void	*arr;
	int		i;

	arr = malloc(size);
	i = 0;
	if (!arr)
		_nsx_exit("Allocation Failure!", -1, 'E');
	while (size--)
		((char *)arr)[size] = '\0';
	return (arr);
}

int	_nsx_p_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		_nsx_exit("Can't Open File", -1, 'E');
	return (fd);
}

void	*_nsx_xpm(t_mlx *mlx_info, char *xpmfile)
{
	void	*texture;
	t_vect2	size;

	texture = mlx_xpm_file_to_image(mlx_info->mlx_ptr,
			xpmfile, &size.x, &size.y);
	if (!texture)
		_nsx_invalid_xpmfile(xpmfile);
	return (texture);
}
