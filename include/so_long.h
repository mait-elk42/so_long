/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/13 18:56:59 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "keys.h"
# include <fcntl.h>
# include <mlx.h>

# define OBJ_SCALE 32

typedef struct s_nsx_Gobject
{
	void				*sprite;
	int					sp_xsize;
	int					sp_ysize;
}	t_nsx_Gobject;

typedef struct s_vect2
{
	int		x;
	int		y;

}	t_vect2;

typedef struct s_nsx_player
{
	void				*sprite;
	t_vect2				pos;
	int					Coll_n;
} t_nsx_player;


typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_x;
	int				win_y;
	char			**maps;
	t_nsx_Gobject	*objects;
	t_nsx_player	player;
	int				Coll_Goal;
}	t_mlx;

void	_initialize_vect(t_vect2 *vect2, int x, int y);
void	_move_to(t_mlx	*mlx_info, int x, int y);


void	check_maps(t_mlx *mlx_info);
void	_nsx_invalid_maps(void);
void	_nsx_exit(char *last_msg, int status, char type);
void	_nsx_check_args(int ac, char **av);

void	_nsx_start_game(t_mlx *mlx_data);
int		key_down(int keycode, t_mlx *mlx_info);
int		key_up(int keycode, t_mlx *mlx_info);
int		exitfunc(t_mlx *mlx_info);
int		loop(t_mlx *mlx_info);
void	_painter_api(t_mlx *mlx_info, t_vect2 step, t_vect2 pos);

void	_nsx_print_walls(t_mlx *mlx_info);
void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx *m_data);
void	_nsx_new_player(char *xpmfile, t_nsx_player *gameobject, t_mlx *m_data);

void	_nsx_free_all(t_mlx *mlx_info);
#endif