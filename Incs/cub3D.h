/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/05 13:08:49 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>

// Keycodes
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 68
# define RIGHT 67
# define Z 122
# define X 120
# define RED_CROSS 33

// Colors
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF

// data info
# define VIEW_DIST 15
# define SQUARE_SIZE 40
# define WIN_WIDTH 1920
# define WIN_LEN 1080
# define FOV 60

// strings
# define COLOR_CHAR "Error\nWrong char in array (%s), must be only digits\n"
# define COLOR_NBR "Error\nWrong color numbers, must be 3 colors x,y,z\n"
# define COLOR_VAL "Error\nWrong color value (%d), must be between 0 and 255 \
included\n"
# define LESS_ELEM "Error\nNot all configuration elements are present before \
the map\nYou must have NO, SO, EA, WE, F and C\n"
# define MORE_ELEM "Error\nToo much elements before the map, must be only NO, \
SO, EA, WE, F and C, one of each\n"
# define WALLS_ERR "Error\nThe map must be surrounded by walls\n"
# define WALLS_ALONE "Error\nThere is a wall outside the map\n"
# define WRONG_CHAR "Error\nWrong char in map, must be 0, 1, N, S, E, W or a \
whitespace\n"
# define MORE_DIRECTION "Error\nThere must be only one player direction\n"
# define LESS_DIRECTION "Error\nThere must be a player direction (N,S,E or W)\n"
# define DIRECTION_OUT "Error\nThe player is not inside the map\n"

typedef struct s_img
{
	void	*img;
	char	*addr;//img address
	int		bpp;//bits per pixel
	int		endian;//the way bytes are stored
	int		line_l;//line length
}			t_img;

typedef struct s_texture
{
	void	*text;
	char	*addr;//img address
	int		bpp;//bits per pixel
	int		endian;//the way bytes are stored
	int		line_l;//line length
	int		height;
	int		width;
}			t_texture;

typedef struct s_coord_d
{
	int	x;
	int	y;
}				t_coord_d;

typedef struct s_coord_f
{
	float	x;
	float	y;
}				t_coord_f;

typedef struct s_player
{
	t_coord_f	pos;
	t_coord_d	view_dist_pos;
	t_coord_f	dir;
}				t_player;

typedef struct s_bresenham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	inc_x;
	int	inc_y;
	int	slope;
	int	error;
	int	error_inc;
}				t_bresenham;

typedef struct s_ray
{
	t_coord_f	hit_p;
	t_coord_d	cell;
	t_coord_d	dest;
	double		len;
	int			side_hit;
}				t_ray;

typedef struct s_map
{
	int			p;
	double		angle;
	int			p_x;//player position on x
	int			p_y;//player position on y
	char		direction;//player orientation
	char		**tmp;//content of .cub file
	char		**map;//only the map
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	int			f[3];//floor color
	int			c[3];//ceiling color
	int			elems;
	int			width;
	int			height;
}				t_map;

typedef struct s_col
{
	t_coord_d	center;
	t_coord_d	map;
	t_coord_f	dir;
	t_coord_f	dest;
	t_coord_f	step;
	t_coord_f	side_d;
	int			side_touched;
	t_coord_f	delta_d;
	t_coord_d	cell;
}			t_col;

typedef struct s_mini
{
	int	height;
	int	width;
}				t_mini;

typedef struct s_data
{
	void		*mlx; //mlx pointer
	void		*win; //window pointer
	int			win_h;
	int			win_w;
	double		fov;
	float		square_view_d;
	float		ray_len;
	int			**arr;
	int			square_size;
	t_ray		*ray;
	t_player	player;
	t_map		map;
	t_col		col;
	t_img		img;
	t_bresenham	bre;
	t_mini		mini;
}			t_data;

/*	close.c	*/
void		close_all(t_data *data);
void		close_win_error(t_data *data);
void		close_map_error(t_data *data);
int			ft_close(t_data *data);

/*	collision.c	*/
t_coord_f	init_data_collision(t_data *data, t_ray *ray);
t_coord_f	wall_detection(t_data *data, t_ray *ray);

/*	draw.c	*/
void		draw_point(t_data *data, double tX, double tY, int color);
void		draw_coll(t_data *data, int x, int y, t_ray *ray);

/*	errors.c	*/
void		exit_error(char *str);
void		map_error(t_map *map, char *str);

/*	frees.c	*/
void		t_texture_cleaning(t_texture *text);
void		t_map_cleaning(t_map *map);

/*	get_map.c	*/
void		get_ceiling_color(t_map *map, char *str, char *elem, int i);
void		get_floor_color(t_map *map, char *str, char *elem, int i);
void		get_map(t_map *map, int i);

/*	hooks.c	*/
void		hooks(t_data *data);

/*	hooks_changes.c	*/
void		change_board(t_data *data, int keycode);
void		rotate(t_data *data, int keycode);

/*	init_data_struct.c	*/
void		init_data_values(t_data *data);

/*	init_array_map.c	*/
void		create_cpy_map_arr(t_data *data);

/*	line.c	*/
void		create_line(t_data *data, t_coord_f dest);
void		bresenham_algo(t_data *data, t_coord_f dest);

/*	line_utils.c	*/
int			get_inc_value(int i);
void		draw_hor_ver_line(t_data *data, t_coord_f dest);
void		draw_x_line(t_data *data, t_coord_f dest);
void		draw_y_line(t_data *data, t_coord_f dest);

/*	map_char_checks.c	*/
void		direction_check(t_map *map, char c, int i, int j);
int			len_line_up(t_map *map, int i);
int			len_line_down(t_map *map, int i);

/*	map_init.c	*/
int			map_init(t_data *data, int argc, char **argv);

/*	map_parsing.c	*/
int			neighbour_ok(char c);
void		parse_map(t_map *map);

/*	map_utils.c	*/
void		map_format(char *argv);
int			check_if_map(t_map *map);
void		check_enough_datas(t_map *map);
int			count_lines(int fd);
void		define_map_width(t_map *map);

/*	rays.c	*/
double		get_straight_angle(t_data *data, t_coord_f dest);
void		create_rays(t_data *data, t_coord_f dest);

/*	utils.c	*/
int			new_str_start(char *str, int k);
char		*double_strtrim(char *str, char *s1, char *s2);
char		*double_strtrim_free(char *str, char *s1, char *s2);
char		*triple_strtrim_free(char *str, char *s1, char *s2, char *s3);
int			correct_map_char(char c);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	window.c	*/
void		create_window(t_data *data);
void		img_loop(t_data *data);
void		create_board_img(t_data *data);

#endif
