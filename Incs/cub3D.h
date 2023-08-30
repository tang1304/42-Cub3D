/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/30 12:45:59 by rrebois          ###   ########lyon.fr   */
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
# include <math.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define Z 122
# define X 120
# define RED_CROSS 33
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLUE 0x000000FF

typedef struct s_img
{
	void	*img;
	char	*addr; //img address
	int		bpp; //bits per pixel
	int		endian; //the way bytes are stored
	int		line_l; //line length
}			t_img;

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

typedef struct s_bresebham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	incX;
	int	incY;
}				t_bresenham;

typedef struct s_ray
{
	t_coord_f	hit_p;
	t_coord_d	cell;
	double		len;
	int			side_hit;
}				t_ray;

typedef struct s_map
{
	int		p_x;
	int		p_y;
	int		**map;
	int		width;
	int		height;
	int		p;
	double	angle;
}			t_map;

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

typedef struct s_data
{
	void		*mlx; //mlx pointer
	void		*win; //window pointer
	int			win_h;
	int			win_w;
	double		fov;
	float		view_d;
	float		ray_len;
	t_ray		**ray;
	t_map		map;
	t_col		col;
	t_img		img;
	t_bresenham	bre;

	// Array 2D
	int		**arr;
	int		square_size;
}			t_data;

/*	utils.c	*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	init_data_struct.c	*/
void	init_data_values(t_data *data);
void	init_data_map_values(t_data *data);

/*	init_array_map.c	*/
void	init_map(t_data *data);

/*	window.c	*/
void	create_window(t_data *data);
void	img_loop(t_data *data);
void	create_board_img(t_data *data);

/*	hooks.c	*/
void	hooks(t_data *data);

/*	hooks_changes.c	*/
void	change_board(t_data *data, int keycode);

/*	line.c	*/
void	create_line(t_data *data);
void	bresenham_algo(t_data *data, t_coord_d mouse);

/*	line_utils.c	*/
int		get_inc_value(int i);
void	draw_hor_ver_line(t_data *data, t_coord_d dest);

/*	collision.c	*/
void	init_data_collision(t_data *data, int r);
void	wall_detection(t_data *data, int r);

/*	draw.c	*/
void	draw_point(t_data *data, double tX, double tY);
void	draw_coll(t_data *data, int x, int y, int r);

/*	rays.c	*/
void	create_rays(t_data *data);

#endif
