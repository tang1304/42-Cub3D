/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/14 14:24:41 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 68
# define RIGHT 67
# define RED_CROSS 33

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

typedef struct s_map
{
	int			p_x;//player position on x
	int			p_y;//player position on y
	char		direction;//player orientation
	char		**tmp;//content of .cub file
	char		**map;
	t_texture	*no;
	t_texture	*so;
	t_texture	*ea;
	t_texture	*we;
	int			f;//floor color
	int			c;//ceiling color
	// int		width;
	// int		height;
}			t_map;

typedef struct s_data
{
	void	*mlx;//mlx pointer
	void	*win;//window pointer
	t_img	*img;
	t_map	*map;
	
}			t_data;

/*	close.c	*/
int		ft_close(t_data *data);
int		ft_close_win_error(t_data *data);
int		ft_close_map_error(t_data *data);

#endif