/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/07 11:07:10 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x /= data->square_size;
	y /= data->square_size;
	if (x < 0 || y < 0 || x > data->mini.width || y > data->mini.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = '0';
	else if (keycode == X)
		data->arr[y][x] = '1';
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	calculate_new_view_pos(t_data *data)
{
	double	angle;

	angle = get_straight_angle(data, data->player.view_dist_pos);
	data->player.view_dist_pos.x = data->square_view_d * \
		cos(-(angle)) + data->col.center.x;
	data->player.view_dist_pos.y = data->square_view_d * \
		sin(-(angle)) + data->col.center.y;
}

void	rotate(t_data *data, int keycode)
{(void)keycode;
	double		rot_speed;
	double		old_dir_x;

// printf("playerbefX: %f\n", data->player.dir.x);
// printf("playerbefY: %f\n", data->player.dir.y);
// printf("angbef: %f\n", get_straight_angle(data, data->player.view_dist_pos)*180 / M_PI);
	// return ;
	old_dir_x = data->player.dir.x;
	if (keycode == A)
		rot_speed = 1.5f;
	else
		rot_speed = -1.5f;
	data->player.dir.x = data->player.dir.x * cos(rot_speed) - \
						data->player.dir.y * sin(rot_speed);
// printf("playerX: %f\n", data->player.dir.x);
	data->player.dir.y = old_dir_x * sin(rot_speed) + data->player.dir.y * \
						cos(rot_speed);
// printf("playerY: %f\n", data->player.dir.y);
// printf("X: %f\n", dest.x);
// printf("y: %f\n", dest.y);
	calculate_new_view_pos(data);
	create_rays(data, data->player.view_dist_pos);
}
