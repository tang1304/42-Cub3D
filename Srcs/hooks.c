/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:36:09 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/16 11:22:34 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

// static int	key_pressed(int keycode, t_data *data)
// {(void)data;
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_image(data->mlx, data->img);
// 		mlx_destroy_window(data->mlx, data->win);
// 		exit (1);
// 	}
// 	return (0);
// }

static int	mouse_hook(int keycode, t_data *data)
{
	if (keycode == 1)
		change_chessboard(data);
	// else if (keycode == 3)
	return (0);
}

void	hooks(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_hook, data);
	// mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	// mlx_hook(v->win, 17, 1L << 0, close_game, v);
}
