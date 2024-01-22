/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:13:45 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/22 05:47:48 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft_advanced/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define OBJ_SCALE 32

# define P_UP "textures/player_up.xpm"
# define P_DOWN "textures/player_down.xpm"
# define P_LEFT "textures/player_left.xpm"
# define P_RIGHT "textures/player_right.xpm"

# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_ARROW_UP 126
# define K_ARROW_LEFT 123
# define K_ARROW_DOWN 125
# define K_ARROW_RIGHT 124

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
int			_nsx_loop_coin(t_mlx *mlx_info);

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
void		_nsx_putcoin_nextframe(t_mlx *mlx_info, t_vect2 pos, int f);

void		_nsx_enemy_init_dir(t_vect2 *dir, t_nsx_dir bomb_dir);
t_nsx_dir	_nsx_enemy_mv_dir(t_vect2 *dir, t_vect2 *targ, t_mlx *m);
void		_nsx_draw_enemy(t_mlx *mlx_info, t_vect2 dir, t_nsx_dir bomb_dir);

#endif