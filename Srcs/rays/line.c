/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:36:00 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 10:21:52 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs/cub3D.h"

static void	draw_line_vert(t_data *data, t_coord e)
{
	data->bre.inc_x = 1;
	if (data->bre.dx < 0)
	{
		data->bre.inc_x = -1;
		data->bre.dx = -data->bre.dx;
	}
	data->bre.error = 2 * data->bre.dx - data->bre.dy;
	data->bre.error_inc = 2 * (data->bre.dx - data->bre.dy);
	data->bre.slope = 2 * data->bre.dx;
	while (data->bre.y < e.y)
	{
		if (data->bre.error > 0)
		{
			data->bre.x += data->bre.inc_x;
			data->bre.error += data->bre.error_inc;
		}
		else
			data->bre.error += data->bre.slope;
		data->bre.y++;
	}
}

static void	draw_line_hor(t_data *data, t_coord e)
{
	data->bre.inc_y = 1;
	if (data->bre.dy < 0)
	{
		data->bre.inc_y = -1;
		data->bre.dy = -data->bre.dy;
	}
	data->bre.error = 2 * data->bre.dy - data->bre.dx;
	data->bre.error_inc = 2 * (data->bre.dy - data->bre.dx);
	data->bre.slope = 2 * data->bre.dy;
	while (data->bre.x < e.x)
	{
		if (data->bre.error > 0)
		{
			data->bre.y += data->bre.inc_y;
			data->bre.error += data->bre.error_inc;
		}
		else
			data->bre.error += data->bre.slope;
		data->bre.x++;
	}
}

void	init_data_line(t_data *data, t_coord_f start, t_coord_f end, int i)
{
	t_coord	s;
	t_coord	e;

	s.x = start.x;
	s.y = start.y;
	e.x = end.x;
	e.y = end.y;
	data->bre.x = s.x;
	data->bre.y = s.y;
	data->bre.dx = e.x - s.x;
	data->bre.dy = e.y - s.y;
	data->bre.inc_x = 1;
	if (i == 0)
		draw_line_hor(data, e);
	else
		draw_line_vert(data, e);
}

void	create_line(t_data *data, t_coord_f end)
{
	if (fabs(end.y - data->player.pos.y) < fabs(end.x - data->player.pos.x))
	{
		if (data->player.pos.x > end.x)
			init_data_line(data, end, data->player.pos, 0);
		else
			init_data_line(data, data->player.pos, end, 0);
	}
	else
	{
		if (data->player.pos.y > end.y)
			init_data_line(data, end, data->player.pos, 1);
		else
			init_data_line(data, data->player.pos, end, 1);
	}
}
