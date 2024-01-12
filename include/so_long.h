/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/12 12:44:17 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>

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

typedef struct s_mlx
{
	int				win_x;
	int				win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**maps;
	t_nsx_Gobject	*objects;
	t_nsx_Gobject	*player;
}	t_mlx;

void	_initialize_vect(t_vect2 *vect2, int x, int y);
void	_move_to(t_mlx	*mlx_info, int x, int y);


void	check_maps(char **maps, int *WIN_X, int *WIN_Y);
void	_nsx_invalid_maps(void);
void	_nsx_exit(char *last_msg, int status, char type);
void	_nsx_check_args(int ac, char **av);

void	_nsx_start_game(t_mlx *mlx_data);
int		key_down(int keycode, t_mlx *mlx_info);
int		exitfunc(t_mlx *mlx_info);
int		loop(t_mlx *mlx_info);
void	_painter_api(t_mlx *mlx_info, t_vect2 step, t_vect2 pos);

void	_nsx_paint_walls(t_mlx *mlx_info);
#endif