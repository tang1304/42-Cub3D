/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/09 15:54:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	map_zoom(t_data *data, int keycode)
{
	if (keycode == PLUS && !data->player.zoom_in)
	{
		data->player.zoom_in = 1;
		data->player.zoom_out = 0;
	}
	if (keycode == MINUS && !data->player.zoom_out)
	{
		data->player.zoom_in = 0;
		data->player.zoom_out = 1;
	}
	create_full_img(data);
	create_rays(data);
}

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
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;

	old_dir_x = data->player.dir.x;
	data->player.angle += ANGLE_MOVE;
	data->player.dir.x = old_dir_x * cos(-ANGLE_MOVE) - \
						data->player.dir.y * sin(-ANGLE_MOVE);
	data->player.dir.y = old_dir_x * sin(-ANGLE_MOVE) + \
						data->player.dir.y * cos(-ANGLE_MOVE);
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	if (data->player.angle < 0)
		data->player.angle = fabs(data->player.angle) + 2 * M_PI;
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;

	old_dir_x = data->player.dir.x;
	data->player.angle -= ANGLE_MOVE;
	data->player.dir.x = old_dir_x * cos(ANGLE_MOVE) - \
						data->player.dir.y * sin(ANGLE_MOVE);
	data->player.dir.y = old_dir_x * sin(ANGLE_MOVE) + \
						data->player.dir.y * cos(ANGLE_MOVE);
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	if (data->player.angle < 0)
		data->player.angle = fabs(data->player.angle) + 2 * M_PI;
}
