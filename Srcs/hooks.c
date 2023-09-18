/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/18 13:24:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

int	actions(t_data *data)
{
	// if (keycode == Z || keycode == X)
	// 	change_board(data, keycode);
	// if (keycode == LEFT || keycode == RIGHT)
	if (data->player.left)
		rotate_left(data);
	if (data->player.right)
		rotate_right(data);
	if (data->player.w)
		move_forward(data);
	if (data->player.s)
		move_backward(data);
	if (data->player.a)
		move_left(data);
	if (data->player.d)
		move_right(data);
	create_board_img(data);
	create_cone_multi_rays(data, data->player.angle);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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
	create_rays(data, dest, 0);
	return (0);
}

void	hooks(t_data *data)
{
	// Adding/removing walls + mvment
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 3, 1L << 1, key_released, data);
	mlx_loop_hook(data->mlx, actions, data);
	// mlx_hook(data->win, 3, 1L << 0, key_released, data);
	// When mouse moves over window
	// mlx_hook(data->win, 6, 1L << 6, mouse_moved, data);
}
