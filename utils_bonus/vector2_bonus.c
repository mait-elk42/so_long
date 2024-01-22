/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:48 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/22 00:54:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_initialize_vect(t_vect2 *vect2, int x, int y)
{
	vect2->x = x;
	vect2->y = y;
}

int	_nsx_vv_eqor(t_vect2 vect1, t_vect2 vect2)
{
	return (vect1.x == vect2.x || vect1.y == vect2.y);
}
