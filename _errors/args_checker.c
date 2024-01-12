/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:08:09 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/11 21:20:36 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	_nsx_check_args(int ac, char **av)
{
	char	*filename;
	if (ac != 2 || av[1][0] == '\0')
		_nsx_exit("INVALID ARGS", -1, 'E');
	filename = av[1];
	while (*filename)
	{
		if (*filename == '.')
			break ;
		filename++;
	}
	if (!(*filename == '.' && *(filename+1) == 'b' && *(filename+2) == 'e'
		&& *(filename+3) == 'r' && *(filename+4) == '\0'))
		_nsx_exit("\033[31mINVALID EXTENSION! DID YOU MEAN .ber ?\e[0m", -1, 'E');
}
