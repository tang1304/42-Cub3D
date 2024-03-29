/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:41:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/17 10:25:22 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

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
	if (data->arr[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.\
		pos.x + new_pos.x) / SQUARE_SIZE] != '1' && data->arr[(int)data->\
		player.pos.y / SQUARE_SIZE][(int)(data->player.pos.x + \
		new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->arr[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && data->arr[\
		(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE][(int)data->\
		player.pos.x / SQUARE_SIZE] != 'D')
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
	if (data->arr[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player.\
		pos.x + new_pos.x) / SQUARE_SIZE] != '1' && data->arr[(int)data->\
		player.pos.y / SQUARE_SIZE][(int)(data->player.\
		pos.x + new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->arr[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && data->arr \
		[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != 'D')
		data->player.pos.y += new_pos.y;
}

void	move_forward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

	move_speed = MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->arr[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->player \
		.pos.x + new_pos.x) / SQUARE_SIZE] != '1' && data->arr[(int)data->\
		player.pos.y / SQUARE_SIZE][(int)(data->player \
		.pos.x + new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->arr[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && data->arr \
		[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != 'D')
		data->player.pos.y += new_pos.y;
}

void	move_backward(t_data *data)
{
	double		move_speed;
	t_coord_f	new_pos;

	move_speed = -MOVE_SPEED;
	new_pos.x = data->player.dir.x * move_speed;
	new_pos.y = data->player.dir.y * move_speed;
	if (data->arr[(int)data->player.pos.y / SQUARE_SIZE][(int)(data->\
		player.pos.x + new_pos.x) / SQUARE_SIZE] != '1' && data->arr[(int)data \
		->player.pos.y / SQUARE_SIZE][(int)(data->\
		player.pos.x + new_pos.x) / SQUARE_SIZE] != 'D')
		data->player.pos.x += new_pos.x;
	if (data->arr[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != '1' && data->arr \
		[(int)(data->player.pos.y + new_pos.y) / SQUARE_SIZE] \
		[(int)data->player.pos.x / SQUARE_SIZE] != 'D')
		data->player.pos.y += new_pos.y;
}
