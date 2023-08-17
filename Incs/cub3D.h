/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/08/17 15:11:48 by tgellon          ###   ########lyon.fr   */
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

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 68
# define RIGHT 67
# define RED_CROSS 33

# define COLOR_CHAR "Error\nWrong char in array (%s), must be only digits\n"
# define COLOR_NBR "Error\nWrong color numbers, must be 3 colors x,y,z\n"
# define COLOR_VAL "Error\nWrong color value (%d), must be between 0 and 255 \
included\n"
# define LESS_ELEM "Error\nNot all configuration elements are present before \
the map\nYou must have NO, SO, EA, WE, F and C\n"
# define MORE_ELEM "Error\nToo much elements before the map, must be only NO, \
SO, EA, WE, F and C\n"

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
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	int			f[3];//floor color
	int			c[3];//ceiling color
	int			elems;
	// int		width;
	// int		height;
}			t_map;

typedef struct s_data
{
	void	*mlx;//mlx pointer
	void	*win;//window pointer
	t_img	img;
	t_map	map;
}			t_data;

/*	close.c	*/
void	close_all(t_data *data);
void	close_win_error(t_data *data);
void	close_map_error(t_data *data);

/*	errors.c	*/
void	exit_error(char *str);
void	get_texture_error(t_map *map, char *str);

/*	frees.c	*/
void	t_texture_cleaning(t_texture *text);
void	t_map_cleaning(t_map *map);

/*	map.c	*/
int		map_init(t_data *data, int argc, char **argv);

/*	map_2.c	*/
void	get_ceiling_color(t_map *map, char *str, char *elem, int i);
void	get_floor_color(t_map *map, char *str, char *elem, int i);
void	get_map(t_map *map, int i);

/*	map_3.c	*/
void	map_format(char *argv);
int		check_if_map(t_map *map);

/*	utils.c	*/
int		new_str_start(char *str, int k);
char	*double_strtrim(char *str, char *s1, char *s2);
char	*double_strtrim_free(char *str, char *s1, char *s2);
int		correct_map_char(char c);

#endif