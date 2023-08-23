/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/23 08:37:44 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static float	vector_d_len_sq(t_coord_d center, t_coord_d map)
{
	float	value;

	value = sqrt((center.x - map.x) * (center.x - map.x) + \
			(center.y - map.y) * (center.y - map.y));
	return (value);
}

// Using dda algorithm
void	init_data_collision(t_data *data)
{
	int	i;
	int	j;

	mlx_mouse_get_pos(data->mlx, data->win, &i, &j);
	data->col.dest.x = (double)i;
	data->col.dest.y = (double)j;
	data->col.map = data->col.center;
	data->col.dir.x = (data->col.dest.x - data->col.center.x);
	data->col.dir.y = (data->col.dest.y - data->col.center.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = (int)1e30;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = (int)1e30;
	else
		data->col.delta_d.y = fabs(1.0f / data->col.dir.y);
	if (data->col.dir.x < 0)
	{
		data->col.step.x = -1;
		data->col.side_d.x = (data->col.center.x - data->col.map.x) * \
								data->col.delta_d.x;
	}
	else
	{
		data->col.step.x = 1;
		data->col.side_d.x = (data->col.map.x + 1.0f - data->col.center.x) * \
								data->col.delta_d.x;
	}
	if (data->col.dir.y < 0)
	{
		data->col.step.y = -1;
		data->col.side_d.y = (data->col.center.y - data->col.map.y) * \
								data->col.delta_d.y;
	}
	else
	{
		data->col.step.y = 1;
		data->col.side_d.y = (data->col.map.y + 1.0f - data->col.center.y) * \
								data->col.delta_d.y;
	}
	wall_detection(data);
	draw_coll(data);
}

void	wall_detection(t_data *data)
{
	data->ray_len = vector_d_len_sq(data->col.center, data->col.map);
	while (data->ray_len < data->view_d * data->view_d)
	{
		if (data->col.side_d.x < data->col.side_d.y)
		{
			data->col.side_d.x += data->col.delta_d.x;
			data->col.map.x += data->col.step.x;
		}
		else
		{
			data->col.side_d.y += data->col.delta_d.y;
			data->col.map.y += data->col.step.y;
		}
		data->ray_len = vector_d_len_sq(data->col.center, data->col.map);
		data->col.cell.x = data->col.map.x / data->square_size;
		data->col.cell.y = data->col.map.y / data->square_size;
		if (data->col.cell.x < 0 || data->col.cell.x >= data->win_l)
			continue ;
		if (data->col.cell.y < 0 || data->col.cell.y >= data->win_h)
			continue ;
		if (data->arr[(int)data->col.cell.y][(int)data->col.cell.x] == 1)
			return ;
	}
}

// draw-cool works ok BUT if we havea U wall shape just below the edge of the line, we have
// a wronf collision detected.
void	draw_coll(t_data *data)
{
	t_coord_d	start;
	t_coord_d	end;

	start.x = data->col.map.x - 5;
	end.x = data->col.map.x + 5;
	end.y = data->col.map.y + 5;
	while (start.x <= end.x)
	{
		start.y = data->col.map.y - 5;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, 0xFF00FF00);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}
