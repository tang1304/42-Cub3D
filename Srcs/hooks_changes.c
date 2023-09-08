/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 10:13:53 by tgellon          ###   ########lyon.fr   */
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

static void	player_dst_pos(t_data *data, int keycode)
{
	if (data->player.view_dst_pos.x == INT_MAX && \
		data->player.view_dst_pos.y == INT_MAX)
		data->player.angle = 0;
	else if (keycode == LEFT)
		data->player.angle += M_PI_4;
	else if (keycode == RIGHT)
		data->player.angle -= M_PI_4;
printf("angle initial: %f\n", data->player.angle * 180 / M_PI);
	data->player.view_dst_pos.x = data->square_view_d * \
			cos(-data->player.angle) + data->player.pos.x;
	data->player.view_dst_pos.y = data->square_view_d * \
			sin(-data->player.angle) + data->player.pos.y;
printf("x: %d\n", data->player.view_dst_pos.x);
printf("y: %d\n", data->player.view_dst_pos.y);
}

void	rotate(t_data *data, int keycode)
{
	double		old_dir_x;
	// t_coord_f	dest;

	player_dst_pos(data, keycode);
	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(data->player.angle) - data->player.dir.y * sin(data->player.angle);
	data->player.dir.y = old_dir_x * sin(data->player.angle) + data->player.dir.y * cos(data->player.angle);
	create_rays(data, data->player.view_dst_pos, data->player.angle);
	// else
}

void	move_forward(t_data *data)
{
	double		move_speed;
	t_coord_d	new_pos;

	move_speed = 10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;

	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
printf("posX:%d\n", data->player.pos.x);
printf("posY:%d\n", data->player.pos.y);
printf("Angle:%f\n", data->player.angle* 180 / M_PI);
	// player_dst_pos(data, 0);
	create_rays(data, data->player.view_dst_pos, data->player.angle);
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_d	new_pos;

	move_speed = -10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;

	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
printf("posX:%d\n", data->player.pos.x);
printf("posY:%d\n", data->player.pos.y);
printf("Angle:%f\n", data->player.angle* 180 / M_PI);
	// player_dst_pos(data, 0);
	create_rays(data, data->player.view_dst_pos, data->player.angle);
}
