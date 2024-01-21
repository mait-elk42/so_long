/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/21 05:22:22 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "keys.h"
# include <fcntl.h>
# include <mlx.h>

# define OBJ_SCALE 32

# define P_UP "textures/player_up.xpm"
# define P_DOWN "textures/player_down.xpm"
# define P_LEFT "textures/player_left.xpm"
# define P_RIGHT "textures/player_right.xpm"

typedef enum e_nsx_dir
{
	None,
	UP,
	LEFT,
	DOWN,
	RIGHT
}	t_nsx_dir;

typedef struct s_ff_check
{
	int	c;
	int	e;
}	t_ff_check;

typedef struct s_vect2
{
	int		x;
	int		y;

}	t_vect2;

typedef struct s_nsx_gobject
{
	void				*sprite;
	int					sp_xsize;
	int					sp_ysize;
	t_vect2				pos;
}	t_nsx_gobject;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**maps;
	t_vect2			window_size;
	t_vect2			doorpos;
	t_vect2			plrpos;
	int				p_steps_count;
	int				p_coll_n;
	int				coll_goal;
	int				door_locked;
}	t_mlx;

void		_nsx_initialize_vect(t_vect2 *vect2, int x, int y);
int			_nsx_vv_eqor(t_vect2 vect1, t_vect2 vect2);
void		_nsx_move_to(t_mlx	*mlx_info, t_vect2 newpos, char	*texturepath);

void		_nsx_check_maps(t_mlx *mlx_info);
void		_nsx_invalid_maps(void);
void		_nsx_invalid_xpmfile(char *fname);
void		_nsx_exit(char *last_msg, int status, char type);
void		_nsx_check_extension_args(int ac, char **av);

void		_nsx_start_game(t_mlx *mlx_data);
int			_nsx_key_down(int keycode, t_mlx *mlx_info);
int			_nsx_exitfunc(t_mlx *mlx_info);
int			_nsx_loop(t_mlx *mlx_info);

void		_nsx_new_obj(char *xpmfile, t_nsx_gobject *obj, t_mlx *m_data);

void		_nsx_free_all(t_mlx *mlx_info);
void		_nsx_free_2d(char	**arr2d);
int			_nsx_p_open(char *filename);
void		*_nsx_p_malloc(int size);

void		_nsx_game_closed(t_mlx *mlx_info);
void		_nsx_show_score(t_mlx *mlx_info);

void		_nsx_draw_xpm(t_mlx *mlx_info, t_vect2 pos, char *xpmfile);
void		*_nsx_xpm(t_mlx *mlx_info, char *xpmfile);

void		_nsx_flood_fill_help(t_mlx *mlx_info, char *mapsfile);
char		**_nsx_read_maps(char *filename);

void		_nsx_auto_render(t_mlx *mlx_info, t_vect2 pos);

void		_nsx_enemy_init_dir(t_vect2 *dir, t_nsx_dir bomb_dir);
t_nsx_dir	_nsx_enemy_mv_dir(t_vect2 *dir, t_vect2 *targ, t_mlx *m);

#endif