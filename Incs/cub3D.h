/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/31 16:15:23 by tgellon          ###   ########lyon.fr   */
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
# include "general.h"
# include "struct.h"

/*	collision.c	*/
t_coord_f		init_data_collision(t_data *data, t_ray *ray);

/*	collision_utils.c	*/
t_coord_f		wall_detection(t_data *data, t_ray *ray);

/*	errors.c	*/
void			exit_error(char *str);
void			map_error(t_map *map, char *str);
void			textures_error(t_data *data, char *str);
void			ray_error(t_data *data, char *str);
int				exit_cub_error(t_data *data, char *str);

/*	frees.c	*/
void			t_texture_cleaning(t_texture *text);
void			t_map_cleaning(t_map *map);
void			free_datas(t_data *data);
void			image_destroy(t_data *data);
int				exit_cub(t_data *data);

/*	get_map.c	*/
void			get_ceiling_color(t_map *map, char *str, char *elem, int i);
void			get_floor_color(t_map *map, char *str, char *elem, int i);
void			get_map(t_map *map, int i);

/*	hooks.c	*/
int				actions(t_data *data);
int				key_pressed(int keycode, t_data *data);
int				key_released(int keycode, t_data *data);

/*	hooks_moves.c	*/
void			move_left(t_data *data);
void			move_right(t_data *data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);

/*	hooks_rotate.c	*/
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

/*	image.c	*/
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			put_pixel_img(t_img img, t_coord coord, int color);

/*	image_utils.c	*/
void			transparency_img(t_img *img, t_coord size);

/*	init_data_struct.c	*/
void			init_player_data(t_data *data);
void			init_data_values(t_data *data);
void			data_init(t_data *data);

/*	init_array_map.c	*/
void			create_cpy_map_arr(t_data *data);

/*	line.c	*/
void			create_line(t_data *data, t_coord_f dest);
void			init_data_line(t_data *data, t_coord_f start, \
								t_coord_f end, int i);

/*	map_char_checks.c	*/
void			direction_neighbour_check(t_map *map, char **tab, \
											int i, int j);
void			direction_check(t_map *map, char c, int i, int j);
int				len_line_up(t_map *map, int i);
int				len_line_down(t_map *map, int i);

/*	map_init.c	*/
void			map_init(t_data *data, int argc, char **argv);

/*	map_parsing.c	*/
int				neighbour_ok(char c);
void			parse_map(t_map *map);

/*	map_utils.c	*/
void			map_format(char *argv);
int				check_if_map(t_map *map);
void			check_enough_datas(t_map *map);
int				count_lines(int fd);
void			define_map_width(t_map *map);

/*	rays.c	*/
t_coord_f		get_dst_coord(t_coord_f pos, double angle, int dist);
void			create_cone_multi_rays(t_data *data, t_coord_f left, \
									t_coord_f right);
void			create_rays(t_data *data);

/*	render.c	*/
void			create_game_rays(t_data *data);

/*	textures.c	*/
int				get_rgb(int *color);
int				get_texture_x(t_data *data, t_ray *ray, float text_ratio);
int				get_pixel_from_texture(t_texture *text, int x, int y);
void			load_textures(t_data *data, t_map *map);
void			texture_init(t_data *data);

/*	textures_extra.c	*/
void			top_bottom_wall_pxl(t_ray *ray, int i, float wall_h, \
									int wall_w);
char			*get_texture_path(t_map *map, char *str, char *elem, int i);

/*	utils.c	*/
int				new_str_start(char *str, int k);
char			*double_strtrim(char *str, char *s1, char *s2);
char			*double_strtrim_free(char *str, char *s1, char *s2);
char			*triple_strtrim_free(char *str, char *s1, char *s2, char *s3);
int				correct_map_char(char c);

/*	utils2.c	*/
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			check_coma_color(t_map *map, char **new, char *tmp);

/*	vector_utils.c	*/
t_coord_f		calculate_vector(t_coord_f start, double angle, double len);
t_coord_f		vector_d_to_f(t_coord vector);
float			get_angle(t_coord_f start, t_coord_f dest);
double			vector_d_len_sq(t_coord center, t_coord map);
float			calculate_len_vector(t_data *data, t_coord_f hit);

/*	window.c	*/
void			create_window(t_data *data);
void			img_loop(t_data *data);

#endif
