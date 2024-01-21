/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:09:10 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 04:26:48 by mait-elk         ###   ########.fr       */
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

char	**_nsx_read_maps(char *filename)
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
			_nsx_free_2d(maps);
		i++;
	}
	maps[i] = 0;
	close(fd);
	return (maps);
}
