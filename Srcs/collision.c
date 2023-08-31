/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/31 16:41:05 by tgellon          ###   ########lyon.fr   */
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
void	init_data_collision(t_data *data, t_coord_d dest, int r)
{
	data->ray[r]->hit_p.x = (double)dest.x;
	data->ray[r]->hit_p.y = (double)dest.y;
	data->col.map = data->col.center;
	data->col.dir.x = (data->ray[r]->hit_p.x - data->col.center.x);
	data->col.dir.y = (data->ray[r]->hit_p.y - data->col.center.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = INT_MAX;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = INT_MAX;
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
	wall_detection(data, 0);
	draw_coll(data, data->col.map.x, data->col.map.y, r);
}

static void	detection_wall_touched(t_data *data, int r)
{
	// right and left side
	if (data->col.side_touched == 0)
	{
		if (data->col.step.x == 1)
			data->ray[r]->side_hit = 1;
		else
			data->ray[r]->side_hit = 2;
	}
	// top and bottom side
	else
	{
		if (data->col.step.y == 1)
			data->ray[r]->side_hit = 3;
		else
			data->ray[r]->side_hit = 4;
	}
}

void	wall_detection(t_data *data, int r)
{
	data->ray[r]->side_hit = 0;
	data->ray_len = vector_d_len_sq(data->col.center, data->col.map);
	while (data->ray_len < data->view_d * data->view_d)
	{
		if (data->col.side_d.x < data->col.side_d.y)
		{
			data->col.side_d.x += data->col.delta_d.x;
			data->col.map.x += data->col.step.x;
			data->col.side_touched = 0;
		}
		else
		{
			data->col.side_d.y += data->col.delta_d.y;
			data->col.map.y += data->col.step.y;
			data->col.side_touched = 1;
		}
		data->ray_len = vector_d_len_sq(data->col.center, data->col.map);
		data->ray[r]->cell.x = data->col.map.x / data->square_size;
		data->ray[r]->cell.y = data->col.map.y / data->square_size;
		if (data->ray[r]->cell.x < 0 || data->ray[r]->cell.x >= data->win_w)
			continue ;
		if (data->ray[r]->cell.y < 0 || data->ray[r]->cell.y >= data->win_h)
			continue ;
		if (data->arr[(int)data->ray[r]->cell.y][(int)data->ray[r]->cell.x] == 1)
		{
			detection_wall_touched(data, r);
			return ;
		}
	}
}
