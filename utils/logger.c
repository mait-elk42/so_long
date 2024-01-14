/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:36:22 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/14 22:22:37 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_nsx_invalid_maps(void)
{
	ft_printf("\033[31mINVALID MAPS\033[0m\n");
	exit(-1);
}

void	_nsx_invalid_xpmfile(char *fname)
{
	ft_printf("\033[31mERROR WHEN CONVERING XPM : %s\033[0m\n", fname);
	exit(-1);
}

void	_nsx_exit(char *last_msg, int status, char type)
{
	if (type == 'E')
		ft_printf("\033[31mERROR : %s\n", last_msg);
	else
		ft_printf("\033[34mMESSAGE : %s\n", last_msg);
	exit(status);
}