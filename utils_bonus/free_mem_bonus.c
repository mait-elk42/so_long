/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:52:15 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 21:19:46 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_free_2d(char	**arr2d)
{
	int	i;

	i = 0;
	if (!arr2d)
		return ;
	while (arr2d[i])
	{
		free(arr2d[i]);
		i++;
	}
	free(arr2d);
}
