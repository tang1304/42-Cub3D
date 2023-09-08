/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 15:26:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static int	key_pressed(int keycode, t_data *data)
{
	if (keycode == Z || keycode == X)
		change_board(data, keycode);
	// if (keycode == LEFT || keycode == RIGHT)
	rotate(data, keycode);
	// if (keycode == W || keycode == S)
	move_fward_bward(data, keycode);
	// else if (keycode == A || keycode == D)
	move_sideways(data, keycode);
	create_board_img(data);
	create_cone_multi_rays(data, data->player.angle);
	return (0);
}

// static int	key_released(int keycode, t_data *data)
// {
// 	(void)data;
// 	(void)keycode;
// 	return (0);
// }

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
	// mlx_hook(data->win, 3, 1L << 0, key_released, data);
	// When mouse moves over window
	// mlx_hook(data->win, 6, 1L << 6, mouse_moved, data);
}
