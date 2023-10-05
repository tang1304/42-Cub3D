/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/05 16:29:57 by tgellon          ###   ########lyon.fr   */
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
# define M 109 // no used
# define PLUS 65451
# define MINUS 65453
# define LEFT 65361
# define RIGHT 65363
# define Z 122
# define X 120
# define RED_CROSS 33

// Colors
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define WALL 0x00b2b2b2
# define TRANS 0xFF000000
# define PURPLE 0x00890089
# define ORANGE 0x00FFA500
# define BROWN 0x000F4A460

// data info
# define VIEW_DIST 400
# define SQUARE_SIZE 15
# define SQ_NUM 12
# define WIN_WIDTH 1440
# define WIN_HEIGHT 720
# define FOV 60
# define RAY_NUMBER WIN_WIDTH
# define MOVE_SPEED 0.4
# define ANGLE_MOVE 0.01

// strings
# define COLOR_CHAR "ErrorWrong char in array (%c b), must be only digits\n"
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
# define XPM_OPEN_ERR "Error\nProblem opening the xpm texture\n"

typedef struct s_img
{
	void	*img;
	char	*addr;//img address
	int		bpp;//bits per pixel
	int		endian;//the way bytes are stored
	int		line_l;//line length
	int		w;
	int		h;
}			t_img;

typedef struct s_texture
{
	void	*text;
	char	*addr;//img address
	char	*path;
	int		bpp;//bits per pixel
	int		endian;//the way bytes are stored
	int		line_l;//line length
	int		height;
	int		width;
}			t_texture;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_coord_f
{
	float	x;
	float	y;
}				t_coord_f;

typedef struct s_player
{
	t_coord_f	pos;
	t_coord	view_dst_pos;
	t_coord_f	dir;
	double		angle;
	int			map;// remove
	int			zoom_in;
	int			zoom_out;
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
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
	t_coord	cell;
	t_coord	w_top;
	t_coord	w_bottom;
	int			top_bef;
	int			bottom_bef;
	int			x_text;
	float		y_text;
	double		len;
	double		correction;
	int			side_hit;
	double		angle;
}				t_ray;

typedef struct s_map
{
	int				p;
	double			angle;
	int				p_x;//player position on x
	int				p_y;//player position on y
	char			direction;//player orientation
	char			**tmp;//content of .cub file
	char			**map;//only the map
	t_texture		text[5];
	int				f[3];//floor color
	int				c[3];//ceiling color
	int				elems;
	int				width;
	int				height;
	struct s_data	*data;
}				t_map;

typedef struct s_col
{
	t_coord	map;
	t_coord_f	dir;
	t_coord_f	dest;
	t_coord	step;
	t_coord_f	side_d;
	int			side_touched;
	t_coord_f	delta_d;
	// t_coord	cell; not used
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
	double		fov;
	double		max_correct_len;
	float		square_view_d;
	float		ray_len_sq;
	int			**arr;
	int			**mini_arr;
	t_ray		*ray;
	t_player	player;
	t_map		map;
	t_col		col;
	t_img		main;
	t_img		game;
	t_img		minimap;
	t_img		bigmap;
	t_img		full;
	t_img		start;
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

/*	draw.c	*/
void		draw_point(t_data *data, int tX, int tY, int color);
void		draw_coll(t_data *data, int x, int y, t_ray *ray);

/*	errors.c	*/
void		exit_error(char *str);
void		map_error(t_map *map, char *str);
void		textures_error(t_data *data, char *str);
void		ray_error(t_data *data, char *str);

/*	frees.c	*/
void		t_texture_cleaning(t_texture *text);
void		t_map_cleaning(t_map *map);
int			exit_cub(t_data *data);

/*	get_map.c	*/
void		get_ceiling_color(t_map *map, char *str, char *elem, int i);
void		get_floor_color(t_map *map, char *str, char *elem, int i);
void		get_map(t_map *map, int i);

/*	hooks.c	*/
int			key_pressed(int keycode, t_data *data);
int			key_released(int keycode, t_data *data);
int			actions(t_data *data);
// void		hooks(t_data *data);

/*	hooks_changes.c	*/
void	map_zoom(t_data *data, int keycode);
void		change_board(t_data *data, int keycode);
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		move_forward(t_data *data);
void		move_backward(t_data *data);

/*	init_data_struct.c	*/
void		init_player_data(t_data *data);
void		init_data_values(t_data *data);

/*	init_array_map.c	*/
void		create_cpy_map_arr(t_data *data);

/*	line.c	*/
void		create_line(t_data *data, t_coord_f dest);
// void		create_line(t_data *data, t_ray *ray);
void		bresenham_algo(t_data *data, t_coord_f dest);

/*	line_utils.c	*/
void		draw_line_vert(t_data *data, t_coord_f start, t_coord_f end);
void		draw_line_hor(t_data *data, t_coord_f start, t_coord_f end);

/*	map_char_checks.c	*/
void		direction_check(t_map *map, char c, int i, int j);
int			len_line_up(t_map *map, int i);
int			len_line_down(t_map *map, int i);

/*	map_init.c	*/
void		map_init(t_data *data, int argc, char **argv);

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
void		create_cone_multi_rays(t_data *data, t_coord_f left, \
									t_coord_f right);
void		create_rays(t_data *data);

/*	render.c	*/
void		create_game_rays(t_data *data);

/*	textures.c	*/
int			get_rgb(int *color);
void		load_textures(t_data *data, t_map *map);
int			get_texture_x(t_data *data, t_ray *ray, float text_ratio);
int			get_pixel_from_texture(t_texture *text, int x, int y);

/*	textures_extra.c	*/
void	load_extra_textures(t_data *data, t_map *map);

/*	utils.c	*/
int			new_str_start(char *str, int k);
char		*double_strtrim(char *str, char *s1, char *s2);
char		*double_strtrim_free(char *str, char *s1, char *s2);
char		*triple_strtrim_free(char *str, char *s1, char *s2, char *s3);
int			correct_map_char(char c);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	vector_utils.c	*/
t_coord_f	calculate_vector(t_coord_f start, double angle, double len);
t_coord_f	vector_d_to_f(t_coord vector);
float		get_angle(t_coord_f start, t_coord_f dest);

/*	window.c	*/
void		create_window(t_data *data);
void		img_loop(t_data *data);
// void		create_minimap_img(t_data *data);

/*	math.c	*/
double		vector_d_len_sq(t_coord center, t_coord map);
float		calculate_len_vector(t_data *data, t_coord_f hit);

/*	image.c	*/
void			init_black_img(t_data *data, int value);
void			create_main_image(t_data *data);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			put_pixel_img(t_img img, t_coord coord, int color);

/*	image_minimap.c	*/
void	create_mini_from_big(t_data *data);
void	crop_full_img(t_data *data, t_coord start, t_coord size, t_img *img);

/*	image_bigmap.c	*/
void	init_bigmap_img(t_data *data);

/*	image_full.c	*/
void	create_full_img(t_data *data);
void	create_big_from_full(t_data *data);

/*	image_utils.c	*/
void	transparency_img(t_img *img, t_coord size);
void	add_squares(t_coord coord, int num, t_img *img);
void	add_border(int w, int h, t_img *img);

#endif
