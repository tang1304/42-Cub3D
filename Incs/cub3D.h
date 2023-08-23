/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/23 08:22:06 by rrebois          ###   ########lyon.fr   */
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
	double	x;
	double	y;
}				t_coord_d;

typedef struct s_coord_f
{
	float	x;
	float	y;
}				t_coord_f;

typedef struct s_map
{
	int		p_x;
	int		p_y;
	int		**map;
	int		width;
	int		height;
	int		p;
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
	t_map	map;
	t_col	col;
	t_img	img;

	// Array 2D
	int		**arr;
	int		square_size;
}			t_data;

/*	utils.c	*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	array_init.c	*/
void	create_arr(t_data *data);
void	init_array_data(t_data *data);

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

/*	collision.c	*/
void	draw_coll(t_data *data);
void	init_data_collision(t_data *data);
void	wall_detection(t_data *data);

#endif
