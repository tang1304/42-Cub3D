/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/08/24 15:34:12 by tgellon          ###   ########lyon.fr   */
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
void	init_data_collision(t_data *data, int r)
{(void)r;
	int	i;
	int	j;

	mlx_mouse_get_pos(data->mlx, data->win, &i, &j);
	data->ray[i]->hit_p.x = (double)i;
	data->ray[i]->hit_p.y = (double)j;
	data->col.map = data->col.center;
	data->col.dir.x = (data->ray[i]->hit_p.x - data->col.center.x);
	data->col.dir.y = (data->ray[i]->hit_p.y - data->col.center.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = 1e8;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = 1e8;
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
}

static void	detection_wall_touched(t_data *data, int r)
{
	// right and left side
	if (data->col.side_touched == 0)
	{
		if (data->col.step.x == 1)
			data->ray[r]->side_hit = 0;
		else
			data->ray[r]->side_hit = 1;
	}
	// top and bottom side
	else
	{
		if (data->col.step.y == 1)
			data->ray[r]->side_hit = 2;
		else
			data->ray[r]->side_hit = 3;
	}
}

void	wall_detection(t_data *data, int r)
{
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
		if (data->ray[r]->cell.x < 0 || data->ray[r]->cell.x >= data->win_l)
			continue ;
		if (data->ray[r]->cell.y < 0 || data->ray[r]->cell.y >= data->win_h)
			continue ;
		if (data->arr[(int)data->ray[r]->cell.y][(int)data->ray[r]->cell.x] == 1)
		{
			detection_wall_touched(data, r);
			draw_coll(data, r);
			return ;
		}
	}
}

void	draw_coll(t_data *data, int r)
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
			if (data->ray[r]->side_hit == 3)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x002C55010);
			else if (data->ray[r]->side_hit == 2)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x0000FF00);
			else if (data->ray[r]->side_hit == 1)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x00FF0000);
			else if (data->ray[r]->side_hit == 0)
				my_mlx_pixel_put(&data->img, start.x, start.y, 0x00000FF);
			start.y = start.y + 1;
		}
		start.x = start.x + 1;
	}
}
