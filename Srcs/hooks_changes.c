/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 09:30:57 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x /= SQUARE_SIZE;
	y /= SQUARE_SIZE;
	if (x < 0 || y < 0 || x > data->mini.width || y > data->mini.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = '0';
	else if (keycode == X)
		data->arr[y][x] = '1';
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static void	player_dst_pos(t_data *data, int keycode)
{
// printf("angle initial: %f\n", data->player.angle * 180 / M_PI);
	if (keycode == A)
		data->player.angle += M_PI_4;
	else if (keycode == D)
		data->player.angle -= M_PI_4;
	if (data->player.angle > 2 * M_PI)
	data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	data->player.view_dst_pos.x = data->square_view_d * \
			cos(-data->player.angle) + data->player.pos.x;
	data->player.view_dst_pos.y = data->square_view_d * \
			sin(-data->player.angle) + data->player.pos.y;
// printf("x: %d\n", data->player.view_dst_pos.x);
// printf("y: %d\n", data->player.view_dst_pos.y);
}

void	rotate(t_data *data, int keycode)
{(void)keycode;
	// double		rot_speed;
	// double		old_dir_x;
	// t_coord_f	dest;

	player_dst_pos(data, keycode);
	create_rays(data, data->player.view_dst_pos, data->player.angle);
	// else


}

// void	move_forward(t_data *data)
// {
// 	double		move_speed;
// 	t_coord_d	new_pos;

// 	move_speed = 10;
// 	new_pos.x = data->player.dir.x * move_speed;
// 	new_pos.y = data->player.dir.y * move_speed;

// 	data->player.pos.x += new_pos.x;
// 	data->player.pos.y += new_pos.y;
// 	create_rays(data, data->player.dir);
// }

// void	move_backward(t_data *data)
// {
// 	double		move_speed;
// 	t_coord_d	new_pos;

// 	move_speed = -10;
// 	new_pos.x = data->player.dir.x * move_speed;
// 	new_pos.y = data->player.dir.y * move_speed;

// 	data->player.pos.x += new_pos.x;
// 	data->player.pos.y += new_pos.y;
// 	create_rays(data, data->player.dir);
// }
