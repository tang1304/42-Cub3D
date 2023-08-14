/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 17:25:48 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define RED_CROSS 33

typedef struct s_img
{
	void	*img;
	char	*addr; //img address
	int		bpp; //bits per pixel
	int		endian; //the way bytes are stored
	int		line_l; //line length
}			t_img;

typedef struct s_map
{
	int		p_x;
	int		p_y;
	char	**map;
	int		width;
	int		height;
	int		p;
}			t_map;

typedef struct s_data
{
	void	*mlx; //mlx pointer
	void	*win; //window pointer
	int		win_h;
	int		win_l;
	t_img	*img;

	// Array 2D
	int		**arr;
	int		arr_h;
	int		arr_l;
	int		square_size;
}			t_data;

/*	utils.c	*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*	window.c	*/
void	white(int i, int j, t_data *data, int size);
void	create_window(t_data *data);
void	create_array(t_data *data);
void	init_data(t_data *data);
void	create_chess_board(t_data *data);
#endif
