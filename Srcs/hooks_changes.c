/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/08 14:05:56 by tgellon          ###   ########lyon.fr   */
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
		data->player.angle += 0.1;
		data->player.dir.x = old_dir_x * cos(-0.1) - \
							data->player.dir.y * sin(-0.1);
		data->player.dir.y = old_dir_x * sin(-0.1) + \
							data->player.dir.y * cos(-0.1);
	}
	else if (keycode == RIGHT)
	{
		data->player.angle -= 0.1;
		data->player.dir.x = old_dir_x * cos(0.1) - \
							data->player.dir.y * sin(0.1);
		data->player.dir.y = old_dir_x * sin(0.1) + \
							data->player.dir.y * cos(0.1);
	}
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= 2 * M_PI;
	else if (data->player.angle < -(2 * M_PI))
		data->player.angle += 2 * M_PI;
}

void	rotate(t_data *data, int keycode)
{
	if (keycode != LEFT && keycode != RIGHT)
		return ;
	player_dst_pos(data, keycode);
	// create_rays(data, data->player.view_dst_pos, data->player.angle);
}

void	move_sideways(t_data *data, int keycode)
{
	double		move_speed;
	t_coord_d	new_pos;
	t_coord_f	new_dir;

	if (keycode != A && keycode != D)
		return ;
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
	if (data->map.map[data->player.pos.y / SQUARE_SIZE][(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
	// create_board_img(data);
	// create_cone_multi_rays(data, data->player.angle);
}

void	move_fward_bward(t_data *data, int keycode)
{
	double		move_speed;
	t_coord_d	new_pos;

	if (keycode != W && keycode != S)
		return ;
	if (keycode == W)
		move_speed = MOVE_SPEED;
	else
		move_speed = -MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->map.map[data->player.pos.y / SQUARE_SIZE][(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
	// create_board_img(data);
	// create_cone_multi_rays(data, data->player.angle);
}
