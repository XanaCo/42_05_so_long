/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:58:16 by ancolmen          #+#    #+#             */
/*   Updated: 2023/02/27 20:42:26 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIN_W 1920
# define WIN_H 1024
# define IS 64
# define RATE 3000

typedef enum s_keycode
{
	ESC = 65307,
	UP = 65362,
	W = 119,
	DOWN = 65364,
	S = 115,
	RIGHT = 65363,
	A = 97,
	LEFT = 65361,
	D = 100,
	RESET = 114,
	QUIT = 113,
	ESPACE = 32,
	ENTER = 65293
}	t_keycode;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_lay
{
	size_t	col;
	size_t	row;
	size_t	player;
	size_t	enemy;
	size_t	collect;
	size_t	exit;
	size_t	floor;
	size_t	e_walls;
	size_t	e_c;
	size_t	e_rowlen;
	size_t	e_path;
	size_t	p_c;
	size_t	p_exit;
}		t_lay;

typedef struct s_map
{
	int		fd;
	char	**map;
	char	**map_cpy;
	char	*line;
	char	*big_line;
	char	*last_line;
	size_t	len;
}		t_map;

typedef struct s_img
{
	void	*w_n;
	void	*w_s;
	void	*w_ew;
	void	*w_ne;
	void	*w_nw;
	void	*w_se;
	void	*w_sw;
	void	*w_t;
	void	*fl;
	void	*ex;
	void	*n_ex;
	void	*col;
	void	*y_w;
	void	*die;
}	t_img;

typedef struct s_num
{
	void	*img;
}	t_num;

typedef struct s_anim
{
	void			*img1;
	void			*img2;
	void			*img3;
	void			*img4;
}	t_anim;

typedef struct s_en
{
	struct s_en	*next;
	t_point		pos;
}	t_en;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_point	size;
	t_point	plpos;
	t_point	epos;
	int		n_loops;
	int		dir;
	int		res;
	int		won;
	int		mov;
	int		exit;
	int		death;
	t_lay	lay;
	t_lay	lay_cpy;
	t_map	map;
	t_img	fix;
	t_anim	pl_r;
	t_anim	pl_l;
	t_anim	en_r;
	t_anim	en_i;
	t_en	*en;
	t_anim	col;
	t_num	*dig;
}	t_game;

/*READ AND CHECK*/
char	**check_map(t_game	*game);
void	read_map(t_game	*game);
void	check_errors(char *line, t_game *game, int last);
void	print_map_error(t_game *game);
void	map_error(char	*str, t_game *game);
void	check_path(t_game *game);
void	check_tiles(int x, int y, t_game *game);
void	flood(size_t x, size_t y, t_game *game);
char	*concat_bg(char *big_line, char *str);

/*START AND UPDATE*/
void	start_game(t_game *game);
int		update_game(t_game *game);

/*INIT STRUCT AND LOAD IMG*/
t_game	game_init(void);
void	load_all_xpm(t_game *game);
void	map_init(t_game *game);
void	event_init(t_game *game);
void	digit_init(t_game *game);
void	pl_r_init(t_game *game);
void	pl_l_init(t_game *game);
void	en_r_init(t_game *game);
void	en_i_init(t_game *game);

/*EVENTS*/
int		key_event_handler(int keycode, t_game *game);
void	update_player(t_game *game, int x, int y);
void	update_enemy(t_game	*game);
void	stock_enemy(t_game *game, t_point crd);
void	player_move(t_game *game, int x, int y);
void	render_death(t_game *game);
void	render_won(t_game *game);

/*DRAW*/
void	render_map(t_game *game);
void	render_wall(t_game *game, t_point crd);
void	render_wall_n(t_game *game, t_point crd);
void	render_wall_s(t_game *game, t_point crd);
void	render_exit(t_game *game, t_point crd);
void	render_en_i(t_game *game, t_point pos);
void	render_en_r(t_game *game, t_point pos);
void	render_en_res(t_game *game, t_point pos);
void	render_player(t_game *game);
void	render_pl_r(t_game *game);
void	render_pl_l(t_game *game);
void	render_col(t_game *game, t_point crd);
void	render_floor(t_game *game, t_point crd);
void	render_moves(t_game *game);

/*END*/
int		ft_exit(t_game *game);
void	end_game(t_game	*game);
void	free_img_fix(t_game *game);
void	free_anim(t_game *game);
void	free_player(t_game *game);
void	free_enemy(t_game *game);
void	free_list(t_en *enemy);
void	free_col(t_game *game);
void	free_digits(t_game *game);
void	free_events(t_game *game);

#endif
