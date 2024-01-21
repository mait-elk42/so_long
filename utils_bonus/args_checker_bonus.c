/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:08:09 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 21:19:22 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_nsx_check_extension_args(int ac, char **av)
{
	char	*filename;

	if (ac != 2 || av[1][0] == '\0')
		_nsx_exit("INVALID ARGS", -1, 'E');
	filename = av[1];
	while (*filename && *filename != '.')
		filename++;
	if (!(*filename == '.' && *(filename +1) == 'b' && *(filename +2) == 'e'
			&& *(filename +3) == 'r' && *(filename +4) == '\0'))
		_nsx_invalid_maps();
}
