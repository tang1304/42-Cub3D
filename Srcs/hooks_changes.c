/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/07 11:42:49 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

void	change_board(t_data *data, int keycode)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x /= data->square_size;
	y /= data->square_size;
	if (x < 0 || y < 0 || x > data->mini.width || y > data->mini.height)
		return ;
	if (keycode == Z)
		data->arr[y][x] = '0';
	else if (keycode == X)
		data->arr[y][x] = '1';
	create_board_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

static t_coord_f	calculate_dest_coord(t_data *data)
{
	t_coord_f	dest;
	double		angle;

	angle = get_straight_angle(data, data->player.dir);
	dest.x = data->square_view_d * \
			cos(-angle) + data->col.center.x;
	dest.y = data->square_view_d * \
			sin(-angle) + data->col.center.y;
	return (dest);
}

void	rotate(t_data *data, int keycode)
{
	double		rot_speed;
	double		old_dir_x;
	t_coord_f	dest;
printf("playerbefX: %f\n", data->player.dir.x);
printf("playerbefY: %f\n", data->player.dir.y);
printf("angbef: %f\n", get_straight_angle(data, data->player.dir)*180 / M_PI);
	dest = calculate_dest_coord(data);
	// return ;
	old_dir_x = data->player.dir.x;
	if (keycode == A)
		rot_speed = 1.5f;
	else
		rot_speed = -1.5f;
	data->player.dir.x = data->player.dir.x * cos(rot_speed) - \
						data->player.dir.y * sin(rot_speed);
printf("playerX: %f\n", data->player.dir.x);
	data->player.dir.y = old_dir_x * sin(rot_speed) + data->player.dir.y * \
						cos(rot_speed);
printf("playerY: %f\n", data->player.dir.y);
printf("X: %f\n", dest.x);
printf("y: %f\n", dest.y);
	create_rays(data, dest);
}

void	move_forward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

printf("playerX:%f\n", data->player.pos.x);
printf("playerY:%f\n", data->player.pos.y);
	move_speed = 10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;

	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
	create_rays(data, data->player.dir);
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

printf("playerX:%f\n", data->player.pos.x);
printf("playerY:%f\n", data->player.pos.y);
	move_speed = -10;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;

	data->player.pos.x += new_pos.x;
	data->player.pos.y += new_pos.y;
	create_rays(data, data->player.dir);
}
