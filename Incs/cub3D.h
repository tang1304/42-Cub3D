/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 10:31:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
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
	t_img	*img;
}			t_data;

/*	close.c	*/
int		ft_close(t_data *data);
int		ft_close_win_error(t_data *data);
int		ft_close_map_error(t_data *data);

#endif