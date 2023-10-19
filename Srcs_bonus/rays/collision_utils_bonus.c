/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:31:04 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/19 13:03:36 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

float	vector_f_len_sq(t_coord_f position, t_coord map)
{
	float		value_sq;
	t_coord_f	map_bis;

	map_bis.x = map.x;
	map_bis.y = map.y;
	value_sq = (position.x - map_bis.x) * (position.x - map_bis.x) + \
			(position.y - map_bis.y) * (position.y - map_bis.y);
	return (value_sq);
}

static void	set_door_val(t_data *data, t_ray *ray, int x, int y)
{
	if (check_side_door(data, ray, x, y))
		ray->wall_door = 1;
	else
		ray->wall_door = 0;
	if (data->arr[ray->cell.y][ray->cell.x] == 'D')
		ray->door = 1;
	else
		ray->door = 0;
	if (ray->correction > data->max_correct_len)
		data->max_correct_len = ray->correction;
}

static void	detection_wall_touched(t_data *data, t_ray *ray, int x, int y)
{
	if (data->col.side_touched == 0)
	{
		ray->correction = (data->col.side_d.x - data->col.delta_d.x) \
							* SQUARE_SIZE;
		if (data->col.step.x == 1)
			ray->side_hit = 1;
		else
			ray->side_hit = 2;
	}
	else
	{
		ray->correction = (data->col.side_d.y - data->col.delta_d.y) \
							* SQUARE_SIZE;
		if (data->col.step.y == 1)
			ray->side_hit = 3;
		else
			ray->side_hit = 4;
	}
	set_door_val(data, ray, x, y);
}

void	set_values(t_data *data)
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
}

void	wall_detection(t_data *data, t_ray *ray, t_coord_f *miss)
{
	(*miss).x = -1;
	(*miss).y = -1;
	data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
	while (data->ray_len_sq < data->square_view_d)
	{
		set_values(data);
		data->ray_len_sq = vector_f_len_sq(data->player.pos, data->col.map);
		ray->cell.x = data->col.map.x / SQUARE_SIZE;
		ray->cell.y = data->col.map.y / SQUARE_SIZE;
		if (ray->cell.x < 0 || ray->cell.x >= data->mini.width)
			continue ;
		if (ray->cell.y < 0 || ray->cell.y >= data->mini.height)
			continue ;
		if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1' ||
			data->arr[(int)ray->cell.y][(int)ray->cell.x] == 'D')
		{
			detection_wall_touched(data, ray, \
					(int)ray->cell.y, (int)ray->cell.x);
			(*miss).x = (float)data->col.map.x;
			(*miss).y = (float)data->col.map.y;
			return ;
		}
	}
}
