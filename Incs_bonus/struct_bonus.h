/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:11:48 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/17 10:21:36 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_l;
	int		w;
	int		h;
}			t_img;

typedef struct s_texture
{
	void	*text;
	char	*addr;
	char	*path;
	int		bpp;
	int		endian;
	int		line_l;
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
	t_coord		view_dst_pos;
	t_coord_f	dir;
	double		angle;
	int			zoom_in;
	int			zoom_out;
	int			w;
	int			a;
	int			s;
	int			d;
	int			left_arrow;
	int			right_arrow;
	int			left_mouse;
	int			right_mouse;
	int			mouse_pos;
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
	t_coord		cell;
	t_coord		w_top;
	t_coord		w_bottom;
	int			wall_door;
	int			door;
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
	int				p_x;
	int				p_y;
	char			direction;
	char			**tmp;
	char			**map;
	t_texture		text[6];
	int				f[3];
	int				c[3];
	int				elems;
	int				width;
	int				height;
	struct s_data	*data;
}				t_map;

typedef struct s_col
{
	t_coord		map;
	t_coord_f	dir;
	t_coord_f	dest;
	t_coord		step;
	t_coord_f	side_d;
	int			side_touched;
	t_coord_f	delta_d;
}			t_col;

typedef struct s_mini
{
	int	height;
	int	width;
}				t_mini;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	double		fov;
	double		max_correct_len;
	float		square_view_d;
	float		ray_len_sq;//used??
	int			**arr;
	int			**mini_arr;
	t_ray		*ray;
	t_player	player;
	t_map		map;
	t_col		col;
	t_img		test;
	t_img		main;
	t_img		game;
	t_img		minimap;
	t_img		bigmap;
	t_img		full;
	t_bresenham	bre;
	t_mini		mini;
	t_mini		max;
}			t_data;

#endif
