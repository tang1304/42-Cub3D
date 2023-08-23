/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/23 11:34:14 by tgellon          ###   ########lyon.fr   */
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
# include <fcntl.h>
# include <math.h>

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
	double	x;
	double	y;
}				t_coord_d;

typedef struct s_coord_f
{
	float	x;
	float	y;
}				t_coord_f;

typedef struct s_ray
{
	t_coord_f	hit_p;
	t_coord_d	cell;
	double		len;
	int			side_hit;
	double		angle;
}				t_ray;

typedef struct s_map
{
	int			p_x;//player position on x
	int			p_y;//player position on y
	char		direction;//player orientation
	char		**tmp;//content of .cub file
	char		**map;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	int			f[3];//floor color
	int			c[3];//ceiling color
	int			elems;
	int		width;
	int		height;
}			t_map;

typedef struct s_col
{
	t_coord_d	center;
	t_coord_d	map;
	t_coord_f	dir;
	t_coord_f	dest;
	t_coord_f	step;
	t_coord_f	side_d;
	t_coord_f	delta_d;
	t_coord_d	cell;
}			t_col;

typedef struct s_data
{
	void	*mlx; //mlx pointer
	void	*win; //window pointer
	int		win_h;
	int		win_l;
	float	view_d;
	float	ray_len;
	t_ray	*ray;
	t_map	map;
	t_col	col;
	t_img	img;

	// Array 2D
	int		**arr;
	int		square_size;
}			t_data;

/*	close.c	*/
void	close_all(t_data *data);
void	close_win_error(t_data *data);
void	close_map_error(t_data *data);
int		ft_close(t_data *data);

/*	collision.c	*/
void	draw_coll(t_data *data);
void	init_data_collision(t_data *data);
void	wall_detection(t_data *data);

/*	errors.c	*/
void	exit_error(char *str);
void	map_error(t_map *map, char *str);

/*	frees.c	*/
void	t_texture_cleaning(t_texture *text);
void	t_map_cleaning(t_map *map);

/*	get_map.c	*/
void	get_ceiling_color(t_map *map, char *str, char *elem, int i);
void	get_floor_color(t_map *map, char *str, char *elem, int i);
void	get_map(t_map *map, int i);

/*	hooks.c	*/
void	hooks(t_data *data);

/*	hooks_changes.c	*/
void	change_board(t_data *data, int keycode);

/*	init_data_struct.c	*/
void	init_data_values(t_data *data);
void	init_data_map_values(t_data *data);

/*	init_array_map.c	*/
void	init_map(t_data *data);

/*	line.c	*/
void	create_line(t_data *data);

/*	map_char_checks.c	*/
void	direction_check(t_map *map, char c, int i, int j);
int		len_line_up(t_map *map, int i);
int		len_line_down(t_map *map, int i);

/*	map_init.c	*/
int		map_init(t_data *data, int argc, char **argv);

/*	map_parsing.c	*/
int		neighbour_ok(char c);
void	parse_map(t_map *map);

/*	map_utils.c	*/
void	map_format(char *argv);
int		check_if_map(t_map *map);
void	check_enough_datas(t_map *map);
int		count_lines(int fd);

/*	utils.c	*/
int		new_str_start(char *str, int k);
char	*double_strtrim(char *str, char *s1, char *s2);
char	*double_strtrim_free(char *str, char *s1, char *s2);
char	*triple_strtrim_free(char *str, char *s1, char *s2, char *s3);
int		correct_map_char(char c);

/*	utils.c	*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	window.c	*/
void	create_window(t_data *data);
void	img_loop(t_data *data);
void	create_board_img(t_data *data);

#endif
