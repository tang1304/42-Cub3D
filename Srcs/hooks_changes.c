/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 13:41:15 by rrebois          ###   ########lyon.fr   */
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
	double	old_dir_x;

	old_dir_x = data->player.dir.x;
	if (keycode == LEFT)
	{
		data->player.angle += M_PI_4;
		data->player.dir.x = old_dir_x * cos(-M_PI_4) - \
							data->player.dir.y * sin(-M_PI_4);
		data->player.dir.y = old_dir_x * sin(-M_PI_4) + \
							data->player.dir.y * cos(-M_PI_4);
	}
	else if (keycode == RIGHT)
	{
		data->player.angle -= M_PI_4;
		data->player.dir.x = old_dir_x * cos(M_PI_4) - \
							data->player.dir.y * sin(M_PI_4);
		data->player.dir.y = old_dir_x * sin(M_PI_4) + \
							data->player.dir.y * cos(M_PI_4);
	}
	if (data->player.angle > 2 * M_PI)
	data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
	// data->player.view_dst_pos.x = data->square_view_d * \
	// 		cos(-data->player.angle) + data->player.pos.x;
	// data->player.view_dst_pos.y = data->square_view_d * \
	// 		sin(-data->player.angle) + data->player.pos.y;
}

void	rotate(t_data *data, int keycode)
{
	player_dst_pos(data, keycode);
	create_rays(data, data->player.view_dst_pos, data->player.angle);
}

void	move_sideways(t_data *data, int keycode)
{
	double		move_speed;
	t_coord_d	new_pos;
	t_coord_f	new_dir;

	if (keycode == A)
		move_speed = 5;
	else
		move_speed = -5;
	new_dir.x = data->player.dir.x * cos(-M_PI_2) - \
				data->player.dir.y * sin(-M_PI_2);
	new_dir.y = data->player.dir.x * sin(-M_PI_2) + \
				data->player.dir.y * cos(-M_PI_2);
	new_pos.x = new_dir.x * move_speed;
	new_pos.y = new_dir.y * move_speed;
	if (check_walls(data, &new_pos))
		return ;
	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
	create_board_img(data);
	create_cone_multi_rays(data, data->player.angle);
}

void	move_forward(t_data *data)
{
	double		move_speed;
	t_coord_d	new_pos;

	move_speed = 10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (check_walls(data, &new_pos))
		return ;
	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
	create_board_img(data);
	create_cone_multi_rays(data, data->player.angle);
	// create_rays(data, data->player.view_dst_pos, data->player.angle);
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_d	new_pos;

	move_speed = -10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (check_walls(data, &new_pos))
		return ;
	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
	create_board_img(data);
	create_cone_multi_rays(data, data->player.angle);
	// create_rays(data, data->player.view_dst_pos, data->player.angle);
}
