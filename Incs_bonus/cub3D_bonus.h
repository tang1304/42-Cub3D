/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:17:33 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/26 11:35:05 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>
# include <math.h>
# include "general_bonus.h"
# include "struct_bonus.h"

/*	animation_bonus.c	*/
void			weapon_animation(t_data *data);
void			select_weapon(t_data *data);

/*	collision.c	*/
t_coord_f		init_data_collision(t_data *data, t_ray *ray, int i);

/*	collision_door_bonus.c	*/
int				check_side_door(t_data *data, t_ray *ray, int x, int y);
void			check_door_col(t_data *data, t_ray *ray, t_coord_f *miss);

/*	collision_improved_doors_bonus.c	*/
void			detection_wall_touched_door(t_data *data, t_ray *ray, \
											t_col *col);
void			get_miss_values(t_data *data, t_ray *ray, t_coord_f *miss);
void			improved_doors(t_data *data, t_ray *ray, t_coord_f *miss, \
								int check);

/*	collision_improved_doors_utils_bonus.c	*/
int				set_miss_return_e_w(t_data *data, t_ray *ray, \
									t_coord_f *miss, int check);
int				set_miss_return_n_s(t_data *data, t_ray *ray, \
									t_coord_f *miss, int check);

/*	collision_utils_bonus.c	*/
float			vector_f_len_sq(t_coord_f position, t_coord map);
void			set_values(t_data *data);
void			detection_wall_touched(t_data *data, t_ray *ray, int x, int y);
void			wall_detection(t_data *data, t_ray *ray, t_coord_f *miss);

/*	errors.c	*/
void			exit_error(char *str);
void			map_error(t_map *map, char *str);
void			textures_error(t_data *data, char *str);
void			ray_error(t_data *data, char *str);
int				exit_cub_error(t_data *data, char *str);

/*	free_utils_bonus.c	*/
void			destroy_sprites_img(t_data *data);

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
int				mouse_moved(int x, int y, t_data *data);

/*	hooks_moves.c	*/
void			move_left(t_data *data);
void			move_right(t_data *data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);

/*	hooks_rotate_bonus.c	*/
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

/*	hook_others.c	*/
void			map_zoom(t_data *data, int keycode);
void			open_close_doors(t_data *data);

/*	image.c	*/
unsigned int	get_pixel_img(t_img img, int x, int y);
void			create_main_image(t_data *data);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			put_pixel_img(t_img img, t_coord coord, int color);

/*	image_bigmap.c	*/
void			init_bigmap_img(t_data *data);

/*	image_full.c	*/
void			crop_full_img(t_data *data, t_coord start, \
							t_coord size, t_img *img);
void			create_full_img(t_data *data);
void			create_big_from_full(t_data *data);

/*	image_minimap.c	*/
void			create_mini_from_big(t_data *data);

/*	image_utils.c	*/
void			transparency_img(t_img *img, t_coord size);
void			add_squares(t_coord coord, int num, t_img *img);
void			add_border(int w, int h, t_img *img);
void			clear_image(t_img *img);

/*	init_data_struct.c	*/
void			init_player_data(t_data *data);
void			init_data_values(t_data *data);
void			data_init(t_data *data);

/*	init_array_map.c	*/
void			create_cpy_map_arr(t_data *data);

/*	init_animations_bonus.c	*/
void			load_sprite_weapons(t_data *data);

/*	line.c	*/
void			init_data_line(t_data *data, t_coord_f start, \
								t_coord_f end, int i);
void			create_line(t_data *data, t_coord_f dest);

/*	list_bonus.c	*/
t_frame			*add_new_frame(t_data *data, int i, int j);
void			add_frame_last(t_animation *a, t_frame *node);
t_animation		*add_anim_node(t_data *data, int i);
void			add_anim_last(t_data *data, t_animation *node);

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

/*	map_utils2.c	*/
void			check_valid_doors(t_map *map);

/*	rays.c	*/
t_coord_f		get_dst_coord(t_coord_f pos, double angle, int dist);
void			create_cone_multi_rays(t_data *data, t_coord_f left, \
									t_coord_f right);
void			create_rays(t_data *data);

/*	render.c	*/
void			create_game_rays(t_data *data);

/*	render_utils_bonus.c*/
void			get_color_from_text(t_data *data, t_ray *ray);
void			set_ratio_val(t_data *data, t_ray *ray, float slice_h);

/*	textures.c	*/
int				get_rgb(int *color);
int				get_texture_x(t_data *data, t_ray *ray, float text_ratio);
int				get_pixel_from_texture(t_texture *text, int x, int y);
void			load_textures(t_data *data, t_map *map);
void			texture_init(t_data *data);

/*	textures_extra.c	*/
void			wall_door_text_init(t_data *data);
int				set_x_texture_val(t_data *data, t_ray *ray, float val);
void			load_extra_textures(t_data *data, t_map *map);
char			*get_texture_path(t_map *map, char *str, char *elem, int i);

/*	utils.c	*/
int				new_str_start(char *str, int k);
char			*double_strtrim(char *str, char *s1, char *s2);
char			*double_strtrim_free(char *str, char *s1, char *s2);
char			*triple_strtrim_free(char *str, char *s1, char *s2, char *s3);
int				correct_map_char(char c);

/*	utils2_bonus.c	*/
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

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
