/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:17:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/15 11:36:43 by mait-elk         ###   ########.fr       */
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
		_nsx_exit("CAN'T ALLOC", -1, 'E');
	while (size--)
		((char *)arr)[size] = '\0';
	return (arr);
}

int	_nsx_p_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		_nsx_exit("CAN'T OPN FL(so_long.c:L23)", -1, 'E');
	return (fd);
}
