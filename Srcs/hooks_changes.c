/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/05 16:38:05 by tgellon          ###   ########lyon.fr   */
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
	// create_minimap_img(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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

// static int	check_wall(t_data *data, float x, float y)
// {
// 	t_coord	pos;

// 	pos.x = x / SQUARE_SIZE;
// 	pos.y = y / SQUARE_SIZE;
// 	if (pos.x < 0 || pos.x > WIN_WIDTH - 1)
// 		return (0);
// 	if (pos.y <0 || pos.y > WIN_HEIGHT - 1)
// 		return (0);
// 	if (data->map.map[pos.y][pos.x] != '1')
// 		return (1);
// 	return (0);
// }

void	move_left(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;
	t_coord_f	new_dir;

	move_speed = MOVE_SPEED;
	new_dir.x = data->player.dir.x * cos(-M_PI_2) - \
				data->player.dir.y * sin(-M_PI_2);
	new_dir.y = data->player.dir.x * sin(-M_PI_2) + \
				data->player.dir.y * cos(-M_PI_2);
	new_pos.x = new_dir.x * move_speed;
	new_pos.y = new_dir.y * move_speed;
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
}

void	move_right(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;
	t_coord_f	new_dir;

	move_speed = -MOVE_SPEED;
	new_dir.x = data->player.dir.x * cos(-M_PI_2) - \
				data->player.dir.y * sin(-M_PI_2);
	new_dir.y = data->player.dir.x * sin(-M_PI_2) + \
				data->player.dir.y * cos(-M_PI_2);
	new_pos.x = new_dir.x * move_speed;
	new_pos.y = new_dir.y * move_speed;
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
}

void	move_forward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

	move_speed = MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1' && data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.y += new_pos.y;
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

	move_speed = -MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
}
