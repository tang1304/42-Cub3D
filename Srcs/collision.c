/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/22 12:45:54 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"
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
		// printf("start.x: %f\n", start.x);
		start.y = data->col.map.y - 5;
		while (start.y <= end.y)
		{
			my_mlx_pixel_put(&data->img, start.x, start.y, 0xFF00FF00);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}

static float	vector_f_len_sq(t_coord_d center, t_coord_d map)
{
	float	value_sq;
// printf("center.x: %f .y: %f\n", center.x, center.y);
// printf("map.x: %f .y: %f\n", map.x, map.y);
	value_sq = (center.x - map.x) * (center.x - map.x) + \
			(center.y - map.y) * (center.y - map.y);
// printf("ray_len: %f\n", value_sq);
	return (value_sq);
}

t_coord_f	init_data_collision(t_data *data)
{
	int	i;
	int	j;
	t_coord_f	hit;

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
	hit = wall_detection(data);
// printf("hit.x: %f\n", hit.x);
	// draw_coll(data);
	return (hit);
}

t_coord_f	wall_detection(t_data *data)
{
	t_coord_f	hit;
	float ray_len = vector_f_len_sq(data->col.center, data->col.map);
	while (ray_len < VIEW_DIST * VIEW_DIST)
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
		data->col.cell.x = data->col.map.x / data->square_size;
		data->col.cell.y = data->col.map.y / data->square_size;
// printf("square.x: %d .y: %d val:%d\n", (int)data->col.cell.x, (int)data->col.cell.y,data->arr[(int)data->col.cell.y][(int)data->col.cell.x]);
		ray_len = vector_f_len_sq(data->col.center, data->col.map);
// printf("ray len: %f\n", ray_len);
		if (data->col.cell.x < 0 || data->col.cell.x >= WIN_WIDTH)
			continue;
		if (data->col.cell.y < 0 || data->col.cell.y >= WIN_HEIGHT)
			continue;
		if (data->arr[(int)data->col.cell.y][(int)data->col.cell.x] == 1)
		{
			hit.x = data->col.map.x;
			hit.y = data->col.map.y;
// printf("square.x: %d .y: %d\n", (int)data->col.cell.x, (int)data->col.cell.y);
			return (hit);
		}
	}
	hit.x = -1;
	hit.y = -1;
	return (hit);
}
