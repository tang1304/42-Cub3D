/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:53:40 by tgellon           #+#    #+#             */
/*   Updated: 2023/10/09 15:54:03 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

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
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
		[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != '1')
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
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
		[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != '1')
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
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
		[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != '1' && \
		data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
		[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && \
		data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
		[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.y += new_pos.y;
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

	move_speed = -MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->map.map[(int)data->player.pos.y / SQUARE_SIZE] \
	[(int)(data->player.pos.x + new_pos.x) / SQUARE_SIZE] != '1')
		data->player.pos.x += new_pos.x;
	if (data->map.map[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1')
		data->player.pos.y += new_pos.y;
}
