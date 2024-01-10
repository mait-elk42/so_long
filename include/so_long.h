/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/10 16:46:31 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "libft.h"

# define OBJ_SCALE 32

typedef struct s_nsx_Gobject
{
	void	*sprite;
	int		x;
	int		y;

}	t_nsx_Gobject;

typedef struct s_vect2
{
	int		x;
	int		y;

}	t_vect2;
void	_initialize_vect(t_vect2 *vect2, int x, int y);

typedef struct s_mlx_
{
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**maps;
	t_nsx_Gobject	*objects;
}	t_mlx_;

void	_invalid_maps(void);
void	check_maps(char **maps, int *WIN_X, int *WIN_Y);
#endif