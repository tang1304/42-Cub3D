/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_improved_doors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:12:24 by rrebois           #+#    #+#             */
/*   Updated: 2023/10/20 12:12:24 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Incs_bonus/cub3D_bonus.h"

static int	set_plan_values(t_data *data, t_ray *ray)
{
	if (ray->side_hit == 1 || ray->side_hit == 2)
	{
		data->door.d_plan.y = -1;
		if (ray->side_hit == 1)
			data->door.d_plan.x = data->door.d_hit.x + SQUARE_SIZE * 0.5 - 1;
		else
			data->door.d_plan.x = data->door.d_hit.x - SQUARE_SIZE * 0.5 + 2;
		return (data->door.d_plan.x);
	}
	else
	{
		data->door.d_plan.x = -1;
		if (ray->side_hit == 3)
			data->door.d_plan.y = data->door.d_hit.y + SQUARE_SIZE * 0.5 - 1;
		else
			data->door.d_plan.y = data->door.d_hit.y - SQUARE_SIZE * 0.5 + 2;
		return (data->door.d_plan.y);
	}
}

void	get_miss_values(t_data *data, t_ray *ray, t_coord_f *miss)
{
	int	check_value;

	detection_wall_touched(data, ray, (int)ray->cell.y, (int)ray->cell.x);
	if (data->arr[(int)ray->cell.y][(int)ray->cell.x] == '1')
	{
		(*miss).x = (float)data->col.map.x;
		(*miss).y = (float)data->col.map.y;
		return ;
	}
	else
	{
		data->door.d_hit.x = data->col.map.x;
		data->door.d_hit.y = data->col.map.y;
		check_value = set_plan_values(data, ray);
		improved_doors(data, ray, miss, check_value);
		return ;
	}
}

void	detection_wall_touched_door(t_data *data, t_ray *ray)
{
	if (data->col.side_touched == 0)
	{
		ray->correction = (data->col.side_d.x - data->col.delta_d.x) \
							* SQUARE_SIZE;
		if (data->col.step.x == 1)
			ray->side_hit = 1;//E door displaying ok
		else
			ray->side_hit = 2;//O
	}
	else
	{
		ray->correction = (data->col.side_d.y - data->col.delta_d.y) \
							* SQUARE_SIZE;
		if (data->col.step.y == 1)
			ray->side_hit = 3;//S door displaying ok
		else
			ray->side_hit = 4;//N
	}
	if (data->arr[ray->cell.y][ray->cell.x] == '1')
		ray->wall_door = 1;
	else
		ray->wall_door = 0;
	if (data->arr[ray->cell.y][ray->cell.x] == 'D')
		ray->door = 1;
	else
		ray->door = 0;
}

void	improved_doors(t_data *data, t_ray *ray, t_coord_f *miss, int check)
{
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
		if (set_miss_return_e_w(data, ray, miss, check))
			return ;
		else if (set_miss_return_n_s(data, ray, miss, check))
			return ;
	}
}
