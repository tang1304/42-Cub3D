/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:18:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/09/27 09:01:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Incs/cub3D.h"

static float	vector_f_len_sq(t_coord_f position, t_coord_d map)
{
	float		value_sq;
	t_coord_f	map_bis;

	map_bis.x = map.x;
	map_bis.y = map.y;
	value_sq = (position.x - map_bis.x) * (position.x - map_bis.x) + \
			(position.y - map_bis.y) * (position.y - map_bis.y);
	return (value_sq);

}

static void	detection_wall_touched(t_data *data, t_ray *ray)
{
	// right and left side
	if (data->col.side_touched == 0)
	{
		if (data->col.step.x == 1)
			ray->side_hit = 1;
		else
			ray->side_hit = 2;
	}
	// top and bottom side
	else
	{
		if (data->col.step.y == 1)
			ray->side_hit = 3;
		else
			ray->side_hit = 4;
	}
}

static t_coord_f	wall_detection(t_data *data, t_ray *ray)
{
	t_coord_f	miss;

	miss.x = -1;
	miss.y = -1;
	ray->side_hit = 0;
	data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
	while (data->ray_len_sq < data->square_view_d)
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
		data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
		ray->cell.x = data->col.map.x / SQUARE_SIZE;
		ray->cell.y = data->col.map.y / SQUARE_SIZE;
		if (ray->cell.x < 0 || ray->cell.x >= data->mini.width)
			continue ;
		if (ray->cell.y < 0 || ray->cell.y >= data->mini.height)
			continue ;
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1')
		{
			detection_wall_touched(data, ray);
			// draw_coll(data, data->col.map.x, data->col.map.y, ray);
			miss.x = (float)data->col.map.x;
			miss.y = (float)data->col.map.y;
			return (miss);
		}
	}
	return (miss);
}

// Using dda algorithm
t_coord_f	init_data_collision(t_data *data, t_ray *ray)
{
	t_coord_f	miss;

	// ray->hit_p.x = ray->dest.x;
	// ray->hit_p.y = ray->dest.y;
	data->col.map.x = data->player.pos.x;
	data->col.map.y = data->player.pos.y;
	data->col.dir.x = (ray->hit_p.x - data->player.pos.x);
	data->col.dir.y = (ray->hit_p.y - data->player.pos.y);
	if (data->col.dir.x == 0)
		data->col.delta_d.x = (float)INT_MAX;
	else
		data->col.delta_d.x = fabs(1.0f / data->col.dir.x);
	if (data->col.dir.y == 0)
		data->col.delta_d.y = (float)INT_MAX;
	else
		data->col.delta_d.y = fabs(1.0f / data->col.dir.y);
	if (data->col.dir.x < 0)
	{
		data->col.step.x = -1;
		data->col.side_d.x = (data->player.pos.x - data->col.map.x) * \
								data->col.delta_d.x;
	}
	else
	{
		data->col.step.x = 1;
		data->col.side_d.x = (data->col.map.x + 1.0f - data->player.pos.x) * \
								data->col.delta_d.x;
	}
	if (data->col.dir.y < 0)
	{
		data->col.step.y = -1;
		data->col.side_d.y = (data->player.pos.y - data->col.map.y) * \
								data->col.delta_d.y;
	}
	else
	{
		data->col.step.y = 1;
		data->col.side_d.y = (data->col.map.y + 1.0f - data->player.pos.y) * \
								data->col.delta_d.y;
	}
	miss = wall_detection(data, ray);
	return (miss);
}
