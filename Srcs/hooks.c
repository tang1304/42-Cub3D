/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/11 15:03:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	actions(t_data *data)
{
	if (data->player.w)
		move_forward(data);
	if (data->player.s)
		move_backward(data);
	if (data->player.a)
		move_left(data);
	if (data->player.d)
		move_right(data);
	if (data->player.left_arrow)
		rotate_left(data);
	if (data->player.right_arrow)
		rotate_right(data);
	if (data->player.right_mouse)
		rotate_right(data);
	if (data->player.left_mouse)
		rotate_left(data);
	data->player.view_dst_pos.x = data->player.dir.x * VIEW_DIST + \
									data->player.pos.x;
	data->player.view_dst_pos.y = data->player.dir.y * VIEW_DIST + \
									data->player.pos.y;
	if (data->player.w || data->player.s || data->player.a || data->player.d \
		|| data->player.left_arrow || data->player.right_arrow || \
		data->player.left_mouse || data->player.right_mouse)
	{
		create_full_img(data);
		create_rays(data);
	}
	data->player.left_mouse = 0;
	data->player.right_mouse = 0;
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_cub(data);
	if (keycode == E)
		open_close_doors(data);
	if (keycode == W)
		data->player.w = 1;
	if (keycode == S)
		data->player.s = 1;
	if (keycode == A)
		data->player.a = 1;
	if (keycode == D)
		data->player.d = 1;
	if (keycode == LEFT)
		data->player.left_arrow = 1;
	if (keycode == RIGHT)
		data->player.right_arrow = 1;
	if (keycode == PLUS || keycode == MINUS)
		map_zoom(data, keycode);
	return (1);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.w = 0;
	if (keycode == S)
		data->player.s = 0;
	if (keycode == A)
		data->player.a = 0;
	if (keycode == D)
		data->player.d = 0;
	if (keycode == LEFT)
		data->player.left_arrow = 0;
	if (keycode == RIGHT)
		data->player.right_arrow = 0;
	return (1);
}

int	mouse_moved(int x, int y, t_data *data)
{
	float	new_mouse_pos;

	(void)y;
	new_mouse_pos = ((WIN_WIDTH * 0.5f) - x) / WIN_WIDTH;
	if (new_mouse_pos > data->player.mouse_pos)
	{
		data->player.left_mouse = 1;
		// rotate_left(data);
	}
	else if (new_mouse_pos < data->player.mouse_pos)
	{
		data->player.right_mouse = 1;
		// rotate_right(data);
	}
	data->player.mouse_pos = new_mouse_pos;
	return (0);
}
