/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/25 13:08:33 by rrebois          ###   ########lyon.fr   */
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
	if (data->player.left)
		rotate_left(data);
	if (data->player.right)
		rotate_right(data);

	if (data->player.w || data->player.s || data->player.a || data->player.d \
		|| data->player.left || data->player.right)
	{
		init_black_img(data);
		create_board_img(data);
		create_rays(data);
		// create_cone_multi_rays(data, data->player.angle);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == W)
		data->player.w = 1;
	if (keycode == S)
		data->player.s = 1;
	if (keycode == A)
		data->player.a = 1;
	if (keycode == D)
		data->player.d = 1;
	if (keycode == LEFT)
		data->player.left = 1;
	if (keycode == RIGHT)
		data->player.right = 1;
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
		data->player.left = 0;
	if (keycode == RIGHT)
		data->player.right = 0;
	return (1);
}

int	mouse_moved(int x, int y, t_data *data)
{
	t_coord_d	dest;

	dest.x = x;
	dest.y = y;
	(void)data;
	create_rays(data);
	return (0);
}
