/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/18 05:12:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "keys.h"
# include <fcntl.h>
# include <mlx.h>

# define OBJ_SCALE 32

typedef enum	_nsx_direction
{
	None,
	UP,
	LEFT,
	DOWN,
	RIGHT
} _nsx_direction;

typedef struct s_vect2
{
	int		x;
	int		y;

}	t_vect2;

typedef struct s_nsx_Gobject
{
	void				*sprite;
	int					sp_xsize;
	int					sp_ysize;
	t_vect2				pos;
}	t_nsx_Gobject;

typedef struct t_nsx_Gplayer
{
	void				*sprite;
	void				*sprite_up;
	void				*sprite_down;
	void				*sprite_left;
	void				*sprite_right;
	int					sp_xsize;
	int					sp_ysize;
	t_vect2				pos;
} t_nsx_Gplayer;

typedef struct s_nsx_color
{
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
} t_nsx_color;

typedef struct s_mlx
{
	unsigned long	P_steps_count;
	t_nsx_Gobject	*world;
	t_nsx_Gobject	door_close;
	t_nsx_Gobject	door_open;
	t_nsx_Gplayer	player;
	t_nsx_Gobject	Collection;
	t_nsx_Gobject	Score_Board;
	t_nsx_Gobject	Floor;
	t_nsx_Gobject	Enemy;
	int				Enemies_count;
	t_nsx_Gobject	Box;
	t_vect2			doorpos;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**maps;
	int				win_x;
	int				win_y;
	int				door_locked;
	int				Coll_Goal;
	int				P_Coll_n;
}	t_mlx;

void	_initialize_vect(t_vect2 *vect2, int x, int y);
void	_move_to(t_mlx	*mlx_info, int x, int y);


void	check_maps(t_mlx *mlx_info);
void	_nsx_invalid_maps(void);
void	_nsx_invalid_xpmfile(char *fname);
void	_nsx_exit(char *last_msg, int status, char type);
void	_nsx_check_extension_args(int ac, char **av);

void	_nsx_start_game(t_mlx *mlx_data);
int		key_down(int keycode, t_mlx *mlx_info);
int		exitfunc(t_mlx *mlx_info);
int		loop(t_mlx *mlx_info);
void	_painter_api(t_mlx *mlx_info, t_vect2 step, t_vect2 pos);

void	_nsx_new_gameobject(char *xpmfile, t_nsx_Gobject *gameobject, t_mlx *m_data);

void	_nsx_free_all(t_mlx *mlx_info);
int		_nsx_p_open(char *filename);
void	*_nsx_p_malloc(int size);

int		_nsx_gettrgb(int t, int r, int g, int b);
void	_nsx_game_closed(t_mlx *mlx_info);
void	_nsx_Log(char *msg, char *about);
void	_nsx_draw_image(t_mlx *mlx_info, t_vect2 pos, void *texture);
void	_nsx_draw_str(t_mlx *mlx_info, t_vect2 pos, char *s);
void	_nsx_show_score(t_mlx *mlx_info);

void	_nsx_draw_xpm(t_mlx *mlx_info, t_vect2 pos, char *xpmfile);
void	_nsx_new_player(t_nsx_Gplayer *gameobject, t_mlx *m_data);
#endif