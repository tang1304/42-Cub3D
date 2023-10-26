/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/26 09:48:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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
	if (data->player.left_arrow || data->player.left_mouse)
		rotate_left(data);
	if (data->player.right_arrow || data->player.right_mouse)
		rotate_right(data);
	if (data->player.action)
		weapon_animation(data);
	data->player.view_dst_pos.x = data->player.dir.x * VIEW_DIST + \
									data->player.pos.x;
	data->player.view_dst_pos.y = data->player.dir.y * VIEW_DIST + \
									data->player.pos.y;
	if (data->player.w || data->player.s || data->player.a || data->player.d \
		|| data->player.left_arrow || data->player.right_arrow || \
		data->player.left_mouse || data->player.right_mouse)
		create_full_img(data);
	data->player.left_mouse = 0;
	data->player.right_mouse = 0;
	return (0);
}

static void	update_weapon(t_data *data, int keycode)
{
	if (keycode - 48 == data->player.weapon)
		data->player.weapon = 0;
	else
		data->player.weapon = keycode - 48;
	create_rays(data);
}

int	key_pressed(int key, t_data *data)
{
	if (key == ESC)
		exit_cub(data);
	if (key == E)
		open_close_doors(data);
	if (key == W)
		data->player.w = 1;
	if (key == S)
		data->player.s = 1;
	if (key == A)
		data->player.a = 1;
	if (key == D)
		data->player.d = 1;
	if (key == LEFT)
		data->player.left_arrow = 1;
	if (key == RIGHT)
		data->player.right_arrow = 1;
	if (key == PLUS || key == MINUS)
		map_zoom(data, key);
	if (key == ON || key == TW || key == TH || key == FO || key == FI \
		|| key == SI)
		update_weapon(data, key);
	if (key == ACTION && data->player.weapon)
		data->player.action = 1;
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
	int	new_mouse_pos;

	(void)y;
	new_mouse_pos = ((WIN_WIDTH * 0.5f) - x);
	if (new_mouse_pos > (WIN_WIDTH * 0.5f) - 20 || \
		new_mouse_pos < -(WIN_WIDTH * 0.5f) + 20)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (new_mouse_pos > data->player.mouse_pos)
		data->player.left_mouse = 1;
	else if (new_mouse_pos < data->player.mouse_pos)
		data->player.right_mouse = 1;
	data->player.mouse_pos = new_mouse_pos;
	return (0);
}
