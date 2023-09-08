/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 13:25:23 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	key_pressed(int keycode, t_data *data)
{
	if (keycode == Z || keycode == X)
		change_board(data, keycode);
	if (keycode == LEFT || keycode == RIGHT)
		rotate(data, keycode);
	if (keycode == W)
		move_forward(data);
	else if (keycode == S)
		move_backward(data);
	else if (keycode == A || keycode == D)
		move_sideways(data, keycode);
	return (0);
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

	// When mouse moves over window
	// mlx_hook(data->win, 6, 1L << 6, mouse_moved, data);
}
